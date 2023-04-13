#include "HTTPrequest.h"

void HTTPrequest::init()
{
    state_=REQUEST_LINE;
    header_.clear();
    post_.clear();
}
void parsePath()
{

}
bool HTTPrequest::parseRequestLine(const std::string& line)
{
    std::regex pattern("^([^ ]*) ([^ ])* HTTP/([^ ]*)$");
    std::smatch subMatch;
    if(regex_match(line,subMatch,pattern)){
        method_=subMatch[1];
        path_=subMatch[2];
        version_=subMatch[3];
        state_=HEADERS;
        return true;
    }
    return false;
} 
bool HTTPrequest::parse(Buffer& buff)
{
    const char CRLF[]="\r\n";
    if(buff.readableBytes()<=0)
    {
        return false;
    }
    while(buff.readableBytes()&&state_!=FINISH){
        const char* lineEnd=std::search(buff.curReadPtr(),buff.curWritePtrConst(),CRLF,CRLF+2);
        std::string line(buff.curReadPtr(),lineEnd);
        switch (state_)
        {
        case REQUEST_LINE:
            if(!parseRequestLine(line)){
                return false;
            }
            parsePath();
            break;
        case HEADERS:
            parseRequestHeader(line);
            if(buff.readableBytes()<=2){
                state_=FINISH;
            }
            break;
        case BODY:
            parseDataBody(line);
            break;
        default:
            break;
        }
        if(lineEnd==buff.curWritePtr()){break;}
        buff.updateReadPtrUntilEnd(lineEnd+2);
    }
    return true;
}