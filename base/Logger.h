#ifndef _MUDUOWK_BASE_LOGGER_
#define _MUDUOWK_BASE_LOGGER_

#include<string>

#include "uncopyable.h"
#include "LogStream.h"
#include "FixedBuffer.h"

namespace muduoWK{

#define LOG Logger(__FILE__,__LINE__).stream()

class Logger:uncopyable{
public:
    Logger(const char* programFileName,size_t line);
    ~Logger();

    LogStream& stream(){
        return impl_.stream_;
    }
    static void setLogFileName(std::string name){logFileName_ = name;}
    static std::string getLogFileName(){return logFileName_;}
private:
    class Impl:uncopyable{
        public:
            Impl(const char * programFileName,size_t line);
            void formatTime();

            LogStream stream_;
            size_t line_;
            std::string programFileName_;
    };
    Impl impl_;
    static std::string logFileName_;

};

}



#endif