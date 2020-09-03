#include "logtime.h"
#include "logcommon.h"
#include "logfile.h"
#include <time.h>

namespace llog {

static const char* arrWeek[] = { "Sunday", "Monday", "Tuesday", "Wednessday", "Thursday", "Friday", "Saturday" };

LogTime::LogTime()
{
    char arrBuffer[32]; //时间字符串
    memset(arrBuffer, 0x00, sizeof(arrBuffer));

    time_t timep; //时间戳
    struct tm* pTm;
    time(&timep);
    pTm = localtime(&timep);

    snprintf(arrBuffer, sizeof(arrBuffer), "%d-%02d-%02d %02d:%02d:%02d %s ",
        pTm->tm_year + 1900, pTm->tm_mon + 1, pTm->tm_mday,
        pTm->tm_hour, pTm->tm_min, pTm->tm_sec, arrWeek[pTm->tm_wday]);

    time_ = arrBuffer; //赋值时间字符串

    Date date; //结构体
    date.year_ = pTm->tm_year + 1900;
    date.month_ = pTm->tm_mon + 1;
    date.day_ = pTm->tm_mday;

    LogFile::instance()->updatefile(&date); //更新时间
}

LogTime::~LogTime()
{
}

std::string& LogTime::getLogTime()
{
    return time_;
}

}
