/**
 * @file logtime.h
 * @brief  
 * @author  
 * @version 1.0
 * @date 2018年08月03日 11时24分10秒
 */

#ifndef __LOG_TIME_H__
#define __LOG_TIME_H__
 
#include <string>
using namespace std;
 
namespace Log
{
    class LogTime
    {
    public:
        LogTime();
        ~LogTime();

        //获取时间
        string &getLogTime();
	
    private:
        //日志时间
        string m_strTimeString;
	
    };
}
 
#endif	//#ifndef __LOG_TIME_H__
