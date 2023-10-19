//测试用例
#include <iostream>

#include "logger.h"


using namespace std;
using namespace llog;

int add(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int mult(int a, int b) { return a * b; }

int divide(int a, int b) {
  if (0 == b) {
    LOG_FATAL << "Divisor cannot be zero";
  }

  return a / b;
}

int main(void) {
  Logger::setLogLevel(INFO);
  Logger::setOutputMode(LOGGER_MODE_OUTANDFILE);

  // std::cout << __FILE__ << std::endl;
  // std::cout << INFO << std::endl;
  // std::cout << __LINE__ << std::endl;
  // Logger(__FILE__, INFO, __LINE__).GetLogStream() << "log test!\n";

  LOG_INFO << "The test program began to run!";
  LOG_DEBUG << "Debug Mode!";

  int iNum1;
  int iNum2;
  int iSum;

  cout << "Please inout two number:" << endl;
  cin >> iNum1 >> iNum2;

  LOG_INFO << "User input two number: " << iNum1 << ", " << iNum2;

  iSum = add(iNum1, iNum2);
  LOG_INFO << "iNum1 + iNum2 =  " << iSum;

  iSum = sub(iNum1, iNum2);
  LOG_INFO << "iNum1 - iNum2 = " << iSum;

  iSum = mult(iNum1, iNum2);
  LOG_INFO << "iNum1 * iNum2 = " << iSum;

  iSum = divide(iNum1, iNum2);
  LOG_INFO << "iNum1 / iNum2 = " << iSum;
  LOG_DEBUG << "iNum1 / iNum2 = " << iSum;

  LOG_INFO << "The test program end!";

  return 0;
}
