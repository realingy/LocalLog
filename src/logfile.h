#ifndef __LOG_FILE_H__
#define __LOG_FILE_H__

#include "logcommon.h"
// #include <fstream>
#include <string>

namespace llog {

class LogFile {
public:
    static void writelog(const char* msg, int len);
    static void flushbuffer();

    void writelogfile(const char* msg, int len); //写入文件
    void flushlogfile(); //清空缓存

    static LogFile* instance();

    void updatefile(Date* date);

private:
    LogFile();
    ~LogFile();

    void createdir();
    std::string getfilename();
    void openfile();

private:
    Date* date_;
    // std::fstream filestream_;
    FILE* file_;
    // stdL::mutex mutex_;
};

} //namespace llog

#endif //__LOG_FILE_H__
