#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include <cxxabi.h>
#include <assert.h>
#include <execinfo.h>
#include <exception>
#include <string>
#include <cstring>
#include <cerrno>
#include <vector>
#include <sstream>
#include <iostream>
#include <utility>

#define THROW_EXCEPTION_WHIT_ERRNO                       \
    do                                                   \
    {                                                    \
        throw Exception(std::string(::strerror(errno))); \
    } while (0)

/**
 * @brief 以 vector 的形式获取调用栈
 * @param out 获取的调用栈
 * @param size 获取调用栈的最大层数，默认值为 200
 * @param skip 省略最近 n 层调用栈，默认值为 1，忽略获取 Backtrace() 本身的调用栈
*/
void Backtrace(std::vector<std::string>& out, int size = 200, int skip = 1);

/**
 * @brief 获取调用栈字符串，内部调用 Backtrace()
 * @param size 获取调用栈的最大层数，默认值为 200
 * @param skip 省略最近 n 层调用栈，默认值为 2，忽略获取 BacktraceToSring() 和 Backtrace() 的调用栈
*/
std::string BacktraceToString(int size = 200, int skip = 2);

/**
 * @brief std::exception 的封装
 * 增加了调用栈信息的获取接口
*/
class Exception : public std::exception
{
public:
    explicit Exception(std::string what);
    ~Exception() noexcept override = default;

    // 获取异常信息
    const char* what() const noexcept override;
    // 获取函数调用栈
    const char* stackTrace() const noexcept;

protected:
    std::string _message;
    std::string _stack;
};

//系统错误
class SystemError : public Exception
{
public:
    explicit SystemError(std::string what = "")
        : Exception(what + " : " + std::string(::strerror(errno)))
        {
        }
};

#endif
