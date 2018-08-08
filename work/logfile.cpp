/**
 * @file logfile.cpp
 * @brief  
 * @author  
 * @version 1.0
 * @date 2018年08月03日 11时25分15秒
 */

#include <string>
#include <time.h>
#include <iostream>
#include "logfile.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
 
namespace Log
{
    static const char LogDir[] = "/work/log/";

    LogFile::LogFile()
        //: m_Mutex()
    {
        time_t timep;
        struct tm *pTm;
        time(&timep);
        pTm = localtime(&timep);

        m_Date.m_iDay = pTm->tm_mday;
        m_Date.m_iMon = pTm->tm_mon + 1;
        m_Date.m_iYear = pTm->tm_year + 1900;
	
        createLogDir(); //创建存放Log的目录
        openLogFile(); //打开对应日志文件 
    }
	
    LogFile::~LogFile()
    {
	
    }

    /* 单例写日志功能 */
    void LogFile::WriteLog(const char *pMsg, int iLen)
    {
        LogFile *pLogFile = instance();
        pLogFile->OutputLogFile(pMsg, iLen);
    }
 
    /* 单例缓存清空功能 */
    void LogFile::FlushBuffer(void)
    {
        LogFile *pLogFile = instance();
        pLogFile->FlushLogFile();
    }
 
    /* 写日志 */
    void LogFile::OutputLogFile(const char *pMsg, int len)
    {
        //boost::mutex::scoped_lock lock(m_Mutex);
        if (m_pFile != NULL)
            ::fwrite(pMsg, 1, len, m_pFile);
    }

    /* 清空缓存 */
    void LogFile::FlushLogFile(void)
    {
        //boost::mutex::scoped_lock lock(m_Mutex);
        ::fflush(m_pFile);
    }
 
    /* 单例模式 */
    LogFile *LogFile::instance(void)
    {
        static LogFile tLogFile;
        return &tLogFile;
    }
 
    /* 创建目录 */
    void LogFile::createLogDir(void)
    {	
        if (access(LogDir, F_OK) == -1)
	{
            //不存在这个目录，创建它 
            mkdir(LogDir, 0777);
        }
    }
	
    /* 获取日志文件名 */
    string LogFile::getLogFileName(void)
    {
        char arrBuffer[64]; //绝对路径文件名
        memset(arrBuffer, 0x00, sizeof(arrBuffer));

        snprintf(arrBuffer, sizeof(arrBuffer), "%04d-%02d-%02d-Log.txt",
            m_Date.m_iYear, m_Date.m_iMon, m_Date.m_iDay);
	
        return arrBuffer;
    }
 
    /* 打开日志文件 */
    void LogFile::openLogFile(void)
    {
        char arrBuffer[64]; //绝对文件名
        string fileName = getLogFileName();
        memset(arrBuffer, 0x00, sizeof(arrBuffer));

        snprintf(arrBuffer, sizeof(arrBuffer), "%s/%s", LogDir, fileName.c_str());

        //boost::mutex::scoped_lock lock(m_Mutex);
        m_pFile = fopen(arrBuffer, "a");
    }
 
    /* 如果是新的一天则重新创建新的日志文件,并更新日期结构体 */
    void LogFile::updateLogFile(LOGDATE *pDate)
    {
        if (pDate == NULL)
            return;

        if (m_Date.m_iYear != pDate->m_iYear || m_Date.m_iMon != pDate->m_iMon || m_Date.m_iDay != pDate->m_iDay)
        {
            //新的一天开始了，那么就，关闭之前的。重新创建个对应日期的日志文件。
            m_Date.m_iYear = pDate->m_iYear;
            m_Date.m_iMon = pDate->m_iMon;
            m_Date.m_iDay = pDate->m_iDay;
	
            FlushLogFile();
            fclose(m_pFile);
            m_pFile = NULL;
	
            openLogFile();
        }
    }
}
