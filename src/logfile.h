/**
 * @file logfile.h
 * @brief  
 * @author  
 * @version 1.0
 * @date 2018年08月03日 11时25分20秒
 */

#ifndef __LOG_FILE_H__
#define __LOG_FILE_H__
 
#include <fstream>
#include <string>
#include "logcommon.h"
using namespace std;
 
namespace Log
{
    /*!
     * 日志文件类
     */
    class LogFile
    {
        friend class LogTime;
    public:
        LogFile();
        ~LogFile();
	
        static void WriteLog(const char *pMsg, int iLen);
        static void FlushBuffer(void);
	
        //将日志写入Log文件
        void OutputLogFile(const char *pMsg, int iLen);

        // 清空缓存
        void FlushLogFile(void);
	
        //单例模式
        static LogFile *instance(void);
	
    private:
        void createLogDir(); //创建文件夹
        string getLogFileName(void); //获取文件名
        void openLogFile(void); //打开文件

        /*!
         * 重新创建一个新文件，
         * 我们不希望这个方法暴露出来，声明为私有的，
         * 为了使类LogTime能调用，声明类LogTime为友元类
         */
        void updateLogFile(LOGDATE *pDate); 
	
        LOGDATE m_Date; //时间
        fstream m_LogFileStream; //文件流
        FILE *m_pFile;
        //mutex m_Mutex; //互斥锁
    };
}
 
#endif	//#ifndef __LOG_FILE_H__
