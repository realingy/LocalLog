/**
 * @file logger.cpp
 * @brief  
 * @author  
 * @version 1.0
 * @date 2018年08月03日 11时26分18秒
 */

#include <stdio.h>
#include <stdlib.h>
#include "logger.h"
#include "logrealize.h"
#include "logfile.h"
 
namespace Log
{
    const char *arrLevel[] = { "[DEBUG] ", "[INFO] ", "[WARN] ", "[ERROR] ", "[FATAL] " };

    Logger::LogLevel gLogLevel = Logger::INFO; //默认的日志等级为INFO
    int gLogMode = LOGGER_MODE_STDOUT;//默认的输出模式为输出到标准输出

    void WriteStdOut(const char *pMsg, int len)
    {
        ::fwrite(pMsg, 1, len, stdout);
    }

    void FlushStdOut(void)
    {
        ::fflush(stdout);
    }

    Logger::OutputFunc gLogFunc = WriteStdOut; //默认的写日志函数
    Logger::FlushFunc gFlushFunc = FlushStdOut; //默认的清空缓存函数

    Logger::Logger(FileName SourceFile, LogLevel Level, int len)
        : m_pRealize(new LogRealize(SourceFile, arrLevel[Level], len))
        , m_LogLevel(Level)
    {

    }

    Logger::~Logger()
    {
        //日志流填充下文件名和行号，就是完整的一条日志了
        m_pRealize->FinishLog();
        gLogFunc(m_pRealize->GetLogStreamBuff(), m_pRealize->GetLogStreamBuffLen());
        
        if (m_LogLevel == FATAL)
        {
            //如果发生了FATAL错误，那么就终止程序。
            //以便之后重启程序。
            FlushStdOut(); //在此之前先清空缓冲区
            abort();
        }
    }

    LogStream &Logger::GetLogStream(void)
    {
        return m_pRealize->GetLogStream();
    }
 
    Logger::LogLevel Logger::getLogLevel(void)
    {
        return gLogLevel;
    }

    void Logger::setLogLevel(LogLevel level)
    {
        gLogLevel = level;
    }

    //设置输出模式
    void Logger::setOutputMode(int mode)
    {
        gLogMode = mode;
	
        if (gLogMode == LOGGER_MODE_STDOUT)
        {
            //默认的输出就是输出到标准输出，不做处理
            return;
        }
        else if (gLogMode == LOGGER_MODE_LOGFILE)
        {
            //仅输出到日志文件
            setWriteFunc(LogFile::WriteLog);
            setFlushFunc(LogFile::FlushBuffer);
        }
        else if (gLogMode == (LOGGER_MODE_STDOUT | LOGGER_MODE_LOGFILE))
        {
            //输出到标准输出和log中去
            setWriteFunc(OutputComplex);
            setFlushFunc(FlushAll);
        }
        else
        {
            //nothing
        }
    }

    //设置写日志方法
    void Logger::setWriteFunc(OutputFunc func)
    {
        gLogFunc = func;
    }

    void Logger::setFlushFunc(FlushFunc Flush)
    {
        gFlushFunc = Flush;
    }
 
    //写到标准输出和日志文件
    void Logger::OutputComplex(const char *pMsg, int len)
    {
        WriteStdOut(pMsg, len); //写到标准输出
        LogFile::WriteLog(pMsg, len); //写到日志
    }
 
    void Logger::FlushAll(void)
    {
        FlushStdOut();
        LogFile::FlushBuffer();
    }
}