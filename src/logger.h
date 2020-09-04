#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "logcommon.h"
#include "logstream.h"
#include <memory>

namespace llog {

// DEBUG:指出细粒度信息事件对调试应用程序是非常有帮助的
// INFO:消息在粗粒度级别上突出强调应用程序的运行
// WARN:表明会出现潜在错误的情况
// ERROR:指出虽然发生错误事件，但不影响系统的继续运行。
// FATAL:指出每个严重的错误事件将会导致应用程序的退出。

// 当我们定义了日志的优先级之后，应用程序中比设置的优先级别低的都会被输出
enum LogLevel {
    DEBUG = 0,
    INFO,
    WARN,
    ERROR,
    FATAL
};

class LogRealize;

class Logger {
public:
    // 写日志的方法指针
    typedef void (*OutputFunc)(const char* msg, int len);

    //清空缓存的方法指针
    typedef void (*FlushFunc)();

    //设置日志等级
    static void setLogLevel(LogLevel level);

    //获取日志等级
    static LogLevel getLogLevel();

    //设置输出模式的，支持3种输出模式
    static void setOutputMode(int iMode);

	Logger(FileName absolute, LogLevel level, int line);
    ~Logger();

    //获取日志流
    LogStream& GetLogStream(void);

private:
    static void setWriteFunc(OutputFunc Func);
    static void setFlushFunc(FlushFunc Func);
    static void OutputComplex(const char* pMsg, int iLen);
    static void FlushAll();

    //使用Pimpl机制,解开类的使用接口和实现的耦合
    //std::shared_ptr<LogRealize> realize_; //使用智能指针来管理
    LogRealize* realize_;
    LogLevel level_;
};

//这几个宏是用来设置输出模式的：输出到标准输出 输出到log文件 输出到标准输出和log文件
#define LOGGER_MODE_STDOUT 0x01
#define LOGGER_MODE_LOGFILE 0x02
#define LOGGER_MODE_OUTANDFILE (LOGGER_MODE_STDOUT | LOGGER_MODE_LOGFILE)

#if 1
#define LOG_DEBUG                       \
    if (Logger::getLogLevel() <= DEBUG) \
    Logger(__FILE__, DEBUG, __LINE__).GetLogStream()

#define LOG_INFO                       \
    if (Logger::getLogLevel() <= INFO) \
    Logger(__FILE__, INFO, __LINE__).GetLogStream()

#define LOG_WARN                       \
    if (Logger::getLogLevel() <= WARN) \
    Logger(__FILE__, WARN, __LINE__).GetLogStream()

#define LOG_ERROR Logger(__FILE__, ERROR, __LINE__).GetLogStream()

#define LOG_FATAL Logger(__FILE__, FATAL, __LINE__).GetLogStream()
#endif

/*
LogStream& LOG(LogLevel level)
{
    switch (level) {
    case LogLevel::DEBUG:
        if (Logger::getLogLevel() <= LogLevel::DEBUG)
            return Logger(__FILE__, LogLevel::DEBUG, __LINE__).GetLogStream();
        break;
    case LogLevel::INFO:
        if (Logger::getLogLevel() <= LogLevel::INFO)
            return Logger(__FILE__, LogLevel::INFO, __LINE__).GetLogStream();
        break;
    case LogLevel::WARN:
        if (Logger::getLogLevel() <= LogLevel::WARN)
            return Logger(__FILE__, LogLevel::WARN, __LINE__).GetLogStream();
        break;
    case LogLevel::ERROR:
        return Logger(__FILE__, LogLevel::ERROR, __LINE__).GetLogStream();
        break;
    case LogLevel::FATAL:
        return Logger(__FILE__, LogLevel::FATAL, __LINE__).GetLogStream();
        break;
    default:
        break;
    }
}
*/

}

#endif //#ifndef __LOGGER_H__
