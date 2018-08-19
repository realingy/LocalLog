/**
 * @file logrealize.cpp
 * @brief  
 * @author  
 * @version 1.0
 * @date 2018年08月03日 11时25分53秒
 */

#include "logrealize.h"
 
namespace Log
{
    
    LogRealize::LogRealize(FileName &SourceFile, const char *pLevel, int iLine)
        : m_SourceFileName(SourceFile)
        , m_iLine(iLine)
        , m_LogTimeStr()
        , m_Stream()
    {
        //在构造的时候会填充日志头(其实就是时间和报警等级)
        //首先，输出打印日志时间到LogStream中的Buffer
        m_Stream << m_LogTimeStr.getLogTime();
	
        //其次，输出日志等级
        m_Stream << pLevel;
    }
 
    LogRealize::~LogRealize()
    {
	
    }
	
    LogStream &LogRealize::GetLogStream(void)
    {
        return m_Stream;
    }
	
    void LogRealize::FinishLog()
    {
        //根据我们的日志格式安排，最后输出的是
        //文件名即行号。这个方法是在Logger析构
        //时候调用的，表示一条日志流的完成，可以
        //输出到标准输出或文件中去。
        m_Stream << " - " << m_SourceFileName.m_pFileName << ":" << m_iLine << "\n";
    }
 
    const char *LogRealize::GetLogStreamBuff(void)
    {
        return m_Stream.GetStreamBuff();
    }
	
    int LogRealize::GetLogStreamBuffLen(void)
    {
        return m_Stream.GetStreamBuffLen();
    }
}
