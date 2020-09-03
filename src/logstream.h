#ifndef __LOG_STREAM_H__
#define __LOG_STREAM_H__

#include "logcommon.h"
#include <string>

namespace llog {

// 这个类是日志流的实现，重载了操作符<<, 可能没有考虑到所有情况
class LogStream {
public:
    LogStream();
    ~LogStream();

    const char* getstreambuffer();

    int getstreambufferlen();

    LogStream& operator<<(char);
    LogStream& operator<<(unsigned char);
    LogStream& operator<<(short);
    LogStream& operator<<(unsigned short);
    LogStream& operator<<(int);
    LogStream& operator<<(unsigned int);
    LogStream& operator<<(long);
    LogStream& operator<<(unsigned long);
    LogStream& operator<<(long long);
    LogStream& operator<<(unsigned long long);
    LogStream& operator<<(float);
    LogStream& operator<<(double);
    LogStream& operator<<(char* pChar);
    LogStream& operator<<(const char* pChar);
    LogStream& operator<<(unsigned char* pChar);
    LogStream& operator<<(const unsigned char* pChar);
    LogStream& operator<<(std::string strString);

private:
    FixedBuffer<iFixedBuffer> buffer_;
};

}

#endif //__LOG_STREAM_H__
