/**
 * @file logrealize.h
 * @brief  
 * @author  
 * @version 1.0
 * @date 2018年08月03日 11时25分41秒
 */

#ifndef __LOG_REALIZE_H__
#define __LOG_REALIZE_H__
 
#include "logtime.h"
#include "logcommon.h"
#include "logstream.h"
 
namespace Log
{
    class LogRealize
    {
    public:
        explicit LogRealize(FileName &SourceFile, const char *pLevel, int line);
        ~LogRealize();

        LogStream &GetLogStream(void);
	
        //完成日志流的输出后填充文件名和行号
        void FinishLog();
	
        //我们的实现上，日志流是先存储在固定的
        //Buffer里面，等到整条日志流输出完毕。
        //这个方法就是获取获取日志流
        const char *GetLogStreamBuff(void);
        int GetLogStreamBuffLen(void);
	
    private:
        int m_iLine;			//行号
        LogTime m_LogTimeStr;		//Log时间类
        FileName m_SourceFileName;	//文件名
        LogStream m_Stream;		//LogStream类
    };
}
 
#endif	//#ifndef __LOG_REALIZE_H__
