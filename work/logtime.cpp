/**
 * @file logtime.cpp
 * @brief  
 * @author  
 * @version 1.0
 * @date 2018年08月03日 11时24分30秒
 */

#include <time.h>
#include "logtime.h"
#include "logfile.h"
#include "logcommon.h"
 
namespace Log
{
    static const char *arrWeek[] = { "Sunday", "Monday", "Tuesday", "Wednessday","Thursday", "Friday", "Saturday" };
 
    LogTime::LogTime()
    {
        char arrBuffer[32]; //时间字符串 
        memset(arrBuffer, 0x00, sizeof(arrBuffer));
	
        time_t timep; //时间戳
        struct tm *pTm;
        time(&timep);
        pTm = localtime(&timep);
 
        snprintf(arrBuffer, sizeof(arrBuffer), "%d-%02d-%02d %02d:%02d:%02d %s ",
            pTm->tm_year + 1900, pTm->tm_mon + 1, pTm->tm_mday,
            pTm->tm_hour, pTm->tm_min, pTm->tm_sec, arrWeek[pTm->tm_wday]);
	
        m_strTimeString = arrBuffer; //赋值时间字符串
	
        LOGDATE tDate; //结构体
        tDate.m_iYear = pTm->tm_year + 1900;
        tDate.m_iMon = pTm->tm_mon + 1;
        tDate.m_iDay = pTm->tm_mday;

        LogFile *pLogFile = LogFile::instance();
        pLogFile->updateLogFile(&tDate); //更新时间
    }

    LogTime::~LogTime()
    {
        //nothing
    }

    string &LogTime::getLogTime()
    {
        return m_strTimeString;
    }
}
