#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<regex>

#include "buffer.h"
class HTTPrequest
{
public:
    enum PARSE_STATE{
        REQUEST_LINE,
        HEADERS,
        BODY,
        FINISH,
    };
    enum HTTP_CODE{
        NO_REQUEST=0,
        GET_REQUEST,
        BAD_REQUEST,
        NO_RESOURCE,
        FORBIDDENT_REQUEST,
        FILE_REQUEST,
        INTERNAL_ERROR,
        CLOSED_CONNECTION,
    };
    HTTPrequest(){init();};
    ~HTTPrequest()=default;
    void init();
    bool parse(Buffer& buff);
    void parsePath();
    
private:
    bool parseRequestLine(const std::string &line);
    void parseRequestHeader(const std::string &line);
    void parseDataBody(const std::string & line);
    PARSE_STATE state_;
    std::string method_,path_,version_,body_;
    std::unordered_map<std::string,std::string>header_;
    std::unordered_map<std::string,std::string>post_;

};

#endif