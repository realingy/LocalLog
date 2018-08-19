/**
 * @file logger.h
 * @brief  
 * @author  
 * @version 1.0
 * @date 2018年08月03日 11时26分14秒
 */

#ifndef __LOGGER_H__
#define __LOGGER_H__
 
#include <memory>
#include "logstream.h"
#include "logcommon.h"
 
namespace Log
{
    //向前声明
    class LogRealize;

    class Logger
    {
    public:
        //DEBUG Level:指出细粒度信息事件对调试应用程序是非常有帮助的。
        //INFO Level:消息在粗粒度级别上突出强调应用程序的运行
        //WARN Level:表明会出现潜在错误的情况。
        //ERROR Level:指出虽然发生错误事件，但不影响系统的继续运行。
        //FATAL Level:指出每个严重的错误事件将会导致应用程序的退出。
        //当我们定义了日志的优先级之后，应用程序中比设置的优先级别低的
        //都会被输出。
        enum LogLevel {
            DEBUG, 
            INFO, 
            WARN, 
            ERROR, 
            FATAL
        };
	
        //写日志的方法指针
        typedef void(*OutputFunc)(const char *pMsg, int iLen);
        //清空缓存的方法指针
        typedef void(*FlushFunc)(void);
	
        //设置日志等级
        static void setLogLevel(LogLevel level);

        //获取日志等级
        static LogLevel getLogLevel(void);

        //设置输出模式的，支持3种输出模式
        static void setOutputMode(int iMode);
	
        Logger(FileName SourceFile, LogLevel Level, int line);
        ~Logger();
	
        //获取日志流
        LogStream &GetLogStream(void);

    private:
        //
        static void setWriteFunc(OutputFunc Func);
        //
        static void setFlushFunc(FlushFunc Func);
        //
        static void OutputComplex(const char *pMsg, int iLen);
        //
        static void FlushAll(void);

        //使用Pimpl机制,解开类的使用接口和实现的耦合
        //std::shared_ptr<LogRealize> m_pRealize; //使用智能指针来管理
        LogRealize *m_pRealize;
        LogLevel m_LogLevel;

    };

//这几个宏是用来设置输出模式的：输出到标准输出 输出到log文件 输出到标准输出和log文件
#define LOGGER_MODE_STDOUT		0x01
#define LOGGER_MODE_LOGFILE		0x02
#define LOGGER_MODE_OUTANDFILE	(LOGGER_MODE_STDOUT | LOGGER_MODE_LOGFILE)
 
#if 1
#define LOG_DEBUG if (Logger::getLogLevel() <= Logger::DEBUG)	\
			Logger(__FILE__, Logger::DEBUG, __LINE__).GetLogStream()
 
#define LOG_INFO if (Logger::getLogLevel() <= Logger::INFO)	\
			Logger(__FILE__, Logger::INFO, __LINE__).GetLogStream()
 
#define LOG_WARN if (Logger::getLogLevel() <= Logger::WARN)	\
                        Logger(__FILE__, Logger::WARN, __LINE__).GetLogStream()
 
#define LOG_ERROR Logger(__FILE__, Logger::ERROR, __LINE__).GetLogStream()
 
#define LOG_FATAL Logger(__FILE__, Logger::FATAL, __LINE__).GetLogStream()
#endif
}
 
#endif	//#ifndef __LOGGER_H__
