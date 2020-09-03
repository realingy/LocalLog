#include "logrealize.h"

namespace llog {

LogRealize::LogRealize(FileName& filename, const char* level, int line)
    : filename_(filename)
    , line_(line)
    , time_()
    , stream_()
{
    // 填充日志头(时间和等级)
    // 首先，输出打印日志时间
    stream_ << time_.getLogTime();

    // 其次，输出日志等级
    stream_ << level;
}

LogRealize::~LogRealize()
{
}

LogStream& LogRealize::getlogstream()
{
    return stream_;
}

void LogRealize::finishlog()
{
    //根据我们的日志格式安排，最后输出的是
    //文件名即行号。这个方法是在Logger析构
    //时候调用的，表示一条日志流的完成，可以
    //输出到标准输出或文件中去。
    stream_ << " - " << filename_.filename_ << ":" << line_ << "\n";
}

const char* LogRealize::getlogstreambuffer()
{
    // return stream_.GetStreamBuff();
    return stream_.getstreambuffer();
}

int LogRealize::getlogstreambufferlen()
{
    // return stream_.GetStreamBuffLen();
    return stream_.getstreambufferlen();
}

}
