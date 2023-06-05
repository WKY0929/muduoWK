#include <iostream>
#include <math.h>
#include <sys/wait.h>

#include "/home/ywk/muduoWK/base/Logger.h"
#include "/home/ywk/muduoWK/net/EventLoop.h"
#include "TimerWheel.h"

namespace muduoWK{

namespace net{

typedef std::shared_ptr<Timer> TimerPtr;
struct wheelPos{
	int slotToAdd;
	int level;
};

wheelPos calculatePosByTicks(size_t ticks,int slotNum){
    wheelPos pos;
    int level=0;
    size_t ticksTmp=ticks/slotNum;
    size_t slotToAdd=ticks;
    while (ticksTmp>0)
    {
        slotToAdd=ticksTmp;
        ticksTmp=ticksTmp/slotNum;
        level++;
    }
    pos.slotToAdd=slotToAdd;
    pos.level=level;
    return pos;   
}
void TimerWheel::addTimer(TimerPtr timer){
	slotVec_[timer->getSlot()].push_back(timer);
}
void TimerWheel::addTimerToLower(TimerPtr timer){
    int tickNum = timer->getTickNum() % TickNOneSlot;
    int slot = tickNum;
    if(level_!=0){
        if(tickNum!=0){
            timer->setLevel(level_);
            slot=(slotCur_+slot)%TimerWheels::SlotNum;
            slotVec_[slot].push_back(timer);
        }else{
            timerWheels_->getWheel(level_-1)->addTimerToLower(timer);//向下层送timer
        }

    }else{
        slotVec_[slotCur_].clear();//清空当前槽
	}  
}
void TimerWheel::runSlot(){
    std::list<TimerPtr>::iterator it =slotVec_[slotCur_].begin();
    while(it!=slotVec_[slotCur_].end()){
        TimerPtr timer =*it;
        int level=timer->getLevel();
        if(level==0){
            timer->callFunc();//最低的轮子执行
            if(timer->isRepeated()){
				size_t interval = timer->getInterval();
				timer->setTickNum(interval);
				
				//计算层数和该层的槽位置
				wheelPos pos = calculatePosByTicks(interval,TimerWheels::SlotNum);
				int slotCur =  timerWheels_->getWheel(pos.level)->getSlotCur();
				int slot = (slotCur + pos.slotToAdd) % TimerWheels::SlotNum;

				//赋值
				timer->setSlot(slot);
				timer->setLevel(pos.level);
				//派送timer
				timerWheels_->getWheel(pos.level)->addTimer(timer);
            }
        }
        it++;
    }
    slotVec_[slotCur_].clear();//清空当前槽
}
TimerWheels::TimerWheels(int maxLevel)
	:quit_(true),
	mutex_(){
	if(maxLevel<0) {
		//LOG<<"TimerWheels init error";
	}
	else{
		int num = TimerWheels::SlotNum;
		for(int i = 0;i<maxLevel;++i){
			wheelVec_.push_back(std::unique_ptr<TimerWheel>(new TimerWheel(i,SlotNum,this,num)));
			num *= TimerWheels::SlotNum;
		}
	}
}
TimerPtr TimerWheels::addTimer(TimeStamp expirationTime,TimerReachFunction func,size_t interval){
	//计算总tick数
	size_t ticks = TimeStamp::timeDiffInMillSeconds(TimeStamp::now(),expirationTime);
	if(ticks > TimerMax) {
		return NULL;
		//LOG
	}
	else if(ticks<=0) ticks = 1;

	//计算层数和该层的槽位置
	wheelPos pos = calculatePosByTicks(ticks,TimerWheels::SlotNum);
	int slotCur = wheelVec_[pos.level]->getSlotCur();
	int slot = (slotCur + pos.slotToAdd) % TimerWheels::SlotNum;

	TimerPtr timer(new Timer(ticks,slot,pos.level,std::move(func),interval));

	//addtimerinloop
	MutexLockGuard locker(mutex_);//开放给多线程的接口需要加锁
	wheelVec_[timer->getLevel()]->addTimer(timer);
	return timer;
}
void TimerWheels::delTimer(TimerPtr timer){
	MutexLockGuard locker(mutex_);//开放给多线程的接口需要加锁
	wheelVec_[timer->getLevel()]->delTimer(timer);
}

//先从高到低转移timer，然后执行最底层的timer，最后从低到高tick,一次tick耗费100us
void TimerWheels::tick(){
	for(int i = wheelVec_.size()-1;i>0;--i){
		wheelVec_[i]->checkCurSlot();
	}
	wheelVec_[0]->runSlot();

	for(int i = 0;i<wheelVec_.size();++i){
		wheelVec_[i]->tick();
		if(wheelVec_[i]->getSlotCur()!=0) break;
	}
}
void TimerWheels::run(){
	quit_ = false;
	while(!quit_){
		//usleep(1000);//睡眠
		 sleep(1);
		tick();
	}
}
void TimerWheels::delAll(){
	for(int i = 0;i<wheelVec_.size();++i){
		wheelVec_[i]->delAll();
	}
}


}

}