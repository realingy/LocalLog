/**
 * @file logstream.cpp
 * @brief  
 * @author  
 * @version 1.0
 * @date 2018年08月03日 11时24分59秒
 */

#include <stdio.h>
#include "logstream.h"
 
#if _MSC_VER
#define snprintf _snprintf //WIN
#endif
 
namespace Log
{
    const int iFloatMaxStrLen = 16;
    const int iDoubleMaxStrLen = 32;

    LogStream::LogStream()
    {
	
    }

    LogStream::~LogStream()
    {
	
    }

    const char *LogStream::GetStreamBuff(void)
    {
        return m_Buffer.data();
    }
 
    int LogStream::GetStreamBuffLen(void)
    {
        return m_Buffer.len();
    }
 
    LogStream &LogStream::operator << (char value)
    {
        int iLen = NumberToString(m_Buffer.getCurrent(), value);
        m_Buffer.appendLen(iLen);
        return *this;
    }
 
    LogStream &LogStream::operator << (unsigned char value)
    {
        int iLen = NumberToString(m_Buffer.getCurrent(), value);
        m_Buffer.appendLen(iLen);
        return *this;
    }
 
    LogStream &LogStream::operator << (short value)
    {
        int iLen = NumberToString(m_Buffer.getCurrent(), value);
        m_Buffer.appendLen(iLen);
        return *this;
    }
 
    LogStream &LogStream::operator << (unsigned short value)
    {
        int iLen = NumberToString(m_Buffer.getCurrent(), value);
        m_Buffer.appendLen(iLen);
        return *this;
    }
 
    LogStream &LogStream::operator << (int value)
    {
        int iLen = NumberToString(m_Buffer.getCurrent(), value);
        m_Buffer.appendLen(iLen);
        return *this;
    }
 
    LogStream &LogStream::operator << (unsigned int value)
    {
        int iLen = NumberToString(m_Buffer.getCurrent(), value);
        m_Buffer.appendLen(iLen);
        return *this;
    }
 
    LogStream &LogStream::operator << (long value)
    {
        int iLen = NumberToString(m_Buffer.getCurrent(), value);
        m_Buffer.appendLen(iLen);
        return *this;
    }

    LogStream &LogStream::operator << (unsigned long value)
    {
        int iLen = NumberToString(m_Buffer.getCurrent(), value);
        m_Buffer.appendLen(iLen);
        return *this;
    }

    LogStream &LogStream::operator << (long long value)
    {
        int iLen = NumberToString(m_Buffer.getCurrent(), value);
        m_Buffer.appendLen(iLen);
        return *this;
    }

    LogStream &LogStream::operator << (unsigned long long value)
    {
        int iLen = NumberToString(m_Buffer.getCurrent(), value);
        m_Buffer.appendLen(iLen);
        return *this;
    }

    LogStream &LogStream::operator<<(float fValue)
    {
        int iLen = snprintf(m_Buffer.getCurrent(), iFloatMaxStrLen, "%f", fValue);
        m_Buffer.appendLen(iLen);
        return *this;
    }

    LogStream &LogStream::operator<<(double dValue)
    {
        int iLen = snprintf(m_Buffer.getCurrent(), iDoubleMaxStrLen, "%lf", dValue);
        m_Buffer.appendLen(iLen);
        return *this;
    }

    LogStream &LogStream::operator<<(char *pChar)
    {
        m_Buffer.appendString(pChar, strlen(pChar));
        return *this;
    }

    LogStream &LogStream::operator<<(const char *pChar)
    {
        m_Buffer.appendString(pChar, strlen(pChar));
        return *this;
    }

    LogStream &LogStream::operator<<(unsigned char *pChar)
    {
        return operator<<(reinterpret_cast<char *>(pChar));
    }

    LogStream &LogStream::operator<<(const unsigned char *pChar)
    {
        return operator<<(reinterpret_cast<const char *>(pChar));
    }

    LogStream &LogStream::operator << (std::string strString)
    {
        return operator<<(strString.c_str());
    }
}
