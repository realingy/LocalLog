#include "logstream.h"
#include <stdio.h>

#if _MSC_VER
#define snprintf _snprintf //WIN
#endif

namespace llog {
const int iFloatMaxStrLen = 16;
const int iDoubleMaxStrLen = 32;

LogStream::LogStream()
{
}

LogStream::~LogStream()
{
}

const char* LogStream::getstreambuffer()
{
    return buffer_.data();
}

int LogStream::getstreambufferlen()
{
    return buffer_.len();
}

LogStream& LogStream::operator<<(char value)
{
    int iLen = NumberToString(buffer_.getCurrent(), value);
    buffer_.appendLen(iLen);
    return *this;
}

LogStream& LogStream::operator<<(unsigned char value)
{
    int iLen = NumberToString(buffer_.getCurrent(), value);
    buffer_.appendLen(iLen);
    return *this;
}

LogStream& LogStream::operator<<(short value)
{
    int iLen = NumberToString(buffer_.getCurrent(), value);
    buffer_.appendLen(iLen);
    return *this;
}

LogStream& LogStream::operator<<(unsigned short value)
{
    int iLen = NumberToString(buffer_.getCurrent(), value);
    buffer_.appendLen(iLen);
    return *this;
}

LogStream& LogStream::operator<<(int value)
{
    int iLen = NumberToString(buffer_.getCurrent(), value);
    buffer_.appendLen(iLen);
    return *this;
}

LogStream& LogStream::operator<<(unsigned int value)
{
    int iLen = NumberToString(buffer_.getCurrent(), value);
    buffer_.appendLen(iLen);
    return *this;
}

LogStream& LogStream::operator<<(long value)
{
    int iLen = NumberToString(buffer_.getCurrent(), value);
    buffer_.appendLen(iLen);
    return *this;
}

LogStream& LogStream::operator<<(unsigned long value)
{
    int iLen = NumberToString(buffer_.getCurrent(), value);
    buffer_.appendLen(iLen);
    return *this;
}

LogStream& LogStream::operator<<(long long value)
{
    int iLen = NumberToString(buffer_.getCurrent(), value);
    buffer_.appendLen(iLen);
    return *this;
}

LogStream& LogStream::operator<<(unsigned long long value)
{
    int iLen = NumberToString(buffer_.getCurrent(), value);
    buffer_.appendLen(iLen);
    return *this;
}

LogStream& LogStream::operator<<(float fValue)
{
    int iLen = snprintf(buffer_.getCurrent(), iFloatMaxStrLen, "%f", fValue);
    buffer_.appendLen(iLen);
    return *this;
}

LogStream& LogStream::operator<<(double dValue)
{
    int iLen = snprintf(buffer_.getCurrent(), iDoubleMaxStrLen, "%lf", dValue);
    buffer_.appendLen(iLen);
    return *this;
}

LogStream& LogStream::operator<<(char* pChar)
{
    buffer_.appendString(pChar, strlen(pChar));
    return *this;
}

LogStream& LogStream::operator<<(const char* pChar)
{
    buffer_.appendString(pChar, strlen(pChar));
    return *this;
}

LogStream& LogStream::operator<<(unsigned char* pChar)
{
    return operator<<(reinterpret_cast<char*>(pChar));
}

LogStream& LogStream::operator<<(const unsigned char* pChar)
{
    return operator<<(reinterpret_cast<const char*>(pChar));
}

LogStream& LogStream::operator<<(std::string strString)
{
    return operator<<(strString.c_str());
}
}
