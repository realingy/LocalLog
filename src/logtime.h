#ifndef __LOG_TIME_H__
#define __LOG_TIME_H__

#include <string>

namespace llog {

class LogTime {
public:
    LogTime();
    ~LogTime();

    std::string& getLogTime();

private:
    std::string time_;
};

}

#endif //#ifndef __LOG_TIME_H__
