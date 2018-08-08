/**
 * @file main.cpp
 * @brief  
 * @author  
 * @version 1.0
 * @date 2018年08月07日 16时39分48秒
 */

//测试用例
#include <iostream>
#include "logger.h"
 
using namespace std;
using namespace Log;

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mult(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b == 0)
    {
        LOG_FATAL << "Divisor cannot be zero";
    }

    return a / b;
}

int main(void)
{
    //日志的报警等级为INFO
    Logger::setLogLevel(Logger::INFO);
    //我们设置日志输出到文件和标准输出
    Logger::setOutputMode(LOGGER_MODE_OUTANDFILE);

    LOG_INFO << "The test program began to run!";
    LOG_DEBUG << "Debug Mode!";
    int iNum1;
    int iNum2;
    int iSum;

    cout << "Please inout two number:" << endl;
    cin >> iNum1 >> iNum2;

    LOG_INFO << "User input two number: " << iNum1 << "and" << iNum2;

    iSum = add(iNum1, iNum2);
    LOG_INFO << "iNum1 + iNum2 =  " << iSum;

    iSum = sub(iNum1, iNum2);
    LOG_INFO << "iNum1 - iNum2 = " << iSum;
    
    iSum = mult(iNum1, iNum2);
    LOG_INFO << "iNum1 * iNum2 = " << iSum;

    iSum = divide(iNum1, iNum2);
    LOG_INFO << "iNum1 / iNum2 = " << iSum;

    LOG_INFO << "The test program end!";

    return 0;
}

