#ifndef __LOG_STREAM_H__
#define __LOG_STREAM_H__

/**
 * @file logstream.h
 * @brief  
 * @author  
 * @version 1.0
 * @date 2018年08月03日 11时24分46秒
 */
 
#include <string>
#include "logcommon.h"
 
namespace Log
{
    //这个类主要是日志流的实现
    //其实就是重载了操作符<<
    //可能没有考虑到所有情况
    class LogStream
    {
    public:
        LogStream();
        ~LogStream();
	
        //获取数据缓存
        const char *GetStreamBuff(void);
        //获取缓存长度
        int GetStreamBuffLen(void);
	
        LogStream &operator<<(char);
        LogStream &operator<<(unsigned char);
        LogStream &operator<<(short);
        LogStream &operator<<(unsigned short);
        LogStream &operator<<(int);
        LogStream &operator<<(unsigned int);
        LogStream &operator<<(long);
        LogStream &operator<<(unsigned long);
        LogStream &operator<<(long long);
        LogStream &operator<<(unsigned long long);
        LogStream &operator<<(float);
        LogStream &operator<<(double);
        LogStream &operator<<(char *pChar);
        LogStream &operator<<(const char *pChar);
        LogStream &operator<<(unsigned char *pChar);
        LogStream &operator<<(const unsigned char *pChar);
        LogStream &operator<<(std::string strString);
    
    private:
        //typedef FixedBuffer<iFixedBuffer> FixedBuffer;
        //FixedBuffer m_Buffer;
        FixedBuffer<iFixedBuffer> m_Buffer;
    };
}
 
#endif	//#ifndef __LOG_STREAM_H__
