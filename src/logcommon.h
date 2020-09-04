#ifndef __LOG_COMMON_H__
#define __LOG_COMMON_H__

#include <iostream>
#include <string>

namespace llog {

typedef struct DATE {
    int year_;
    int month_;
    int day_;
} Date;

// 绝对路径只保留文件名
class FileName {
public:
    FileName(const char* absolute)
        : filename_(absolute)
        , len_(static_cast<int>(strlen(absolute)))
    {
#ifdef __unix
		const char* pTmp = strrchr(absolute, '/');

		if (pTmp != NULL) {
			filename_ = pTmp + 1;
			len_ = static_cast<int>(strlen(filename_));
		}
#else
		const char* pTmp = strrchr(absolute, '\\');

		if (pTmp != NULL) {
			filename_ = pTmp + 1;
			len_ = static_cast<int>(strlen(filename_));
		}

		/*
		std::string abspath(absolute);
		auto const pos = abspath.find_last_of('\\');
		const auto leaf = abspath.substr(pos + 1);
		filename_ = leaf.c_str();
		complete_ = leaf;
		len_ = static_cast<int>(strlen(filename_));
		std::cout << "1111111111: " << filename_ << std::endl;
		std::cout << "2222222222: " << complete_ << std::endl;
		*/
#endif
    }

    const char* filename_;
    int len_;
};

//下面这个类用来作为一个固定缓存，这个缓存将输出的日志信息
//追加到缓存区中，以便最后一条完整日志的输出。
const int iFixedBuffer = 4096; //可以使用的正常的缓存大小
const int iFixedBufferBig = 65535; //可以使用的最大的缓存大小

template <int SIZE>
class FixedBuffer {
public:
    FixedBuffer()
        : m_pCur(m_arrData)
    {
        memset(m_arrData, 0x00, SIZE);
    }

    ~FixedBuffer() { }

    void append(const char* pData, int len)
    {
        char* pEndBuffer = &m_arrData[SIZE - 1];
        if (static_cast<int>(pEndBuffer - m_pCur) > len) {
            memcpy(m_pCur, pData, len);
            m_pCur += len; //缓存的尾部
        }
    }

    //获取buffer数据
    const char* data() { return m_arrData; }

    //获取buffer的长度
    int len() { return static_cast<int>(m_pCur - m_arrData); }

    //将某字符串追加到buffer中
    void appendString(const char* pString, int len)
    {
        memcpy(m_pCur, pString, len);
        m_pCur += len;
    }

    //返回buffer当前的指针位置
    //以便外部能直接操作buffer提高效率
    char* getCurrent(void) { return m_pCur; }

    //这个方法与getCurrent配套使用
    void appendLen(int len) { m_pCur += len; }

private:
    char m_arrData[SIZE];
    char* m_pCur;
};

// 下面这个函数模板是用来实现整型转换为字符串
// itoa
const char NumTab[] = { "9876543210123456789" };

template <class T>
int NumberToString(char arrBuffer[], T value)
{
    int iStrNum = 0; //返回字符串长度
    int iRemainder;
    T TmpValue1 = value; //
    T TmpValue2 = value; //
    const char* pNumTab = &NumTab[9]; //

    if (value < 0)
        iStrNum++; //小于0

    do {
        iStrNum++; //
    } while ((TmpValue1 /= 10) != 0);

    char* pTmp = arrBuffer + iStrNum;
    *pTmp-- = '\0';

    do {
        iRemainder = static_cast<int>(TmpValue2 % 10);
        *pTmp-- = pNumTab[iRemainder];
    } while ((TmpValue2 /= 10) != 0);

    if (value < 0)
        *pTmp = '-';
    return iStrNum;
}

} // namespace llog

#endif //__LOG_COMMON_H__
