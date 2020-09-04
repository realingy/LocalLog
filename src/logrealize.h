#ifndef __LOG_REALIZE_H__
#define __LOG_REALIZE_H__

#include "logcommon.h"
#include "logstream.h"
#include "logtime.h"

namespace llog {

class LogRealize {

public:
    LogRealize(const char * filename, const char* level, int line);
    ~LogRealize();

    LogStream& getlogstream();

    void finishlog();

    const char* getlogstreambuffer();
    int getlogstreambufferlen();

private:
    int line_; //行号
    LogTime time_;
    const char * filename_;
    LogStream stream_;
};

}

#endif //__LOG_REALIZE_H__
