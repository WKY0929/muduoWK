#include<iostream>
#include<string>
using namespace std;
class abstructFruit{
    public:
        virtual void Fruit()=0;
};
class apple:public abstructFruit{
    public:
            virtual void Fruit(){
            cout<<"It is an apple"<<endl;
        }
};
class Factory{
    public:
        static abstructFruit* createFruit(const string&str){
            if(str=="apple"){
                return new apple;
            }
        }
    private:
        string str="";
};
int main(){
    auto A=Factory::createFruit("apple");
    A->Fruit();
    return 0;
}