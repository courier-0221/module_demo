#ifndef COMMON_H
#define COMMON_H

#include <memory>
#include <iostream>
using namespace std;

class noncopyable
{
public:
    noncopyable(const noncopyable&) = delete;
    void operator=(const noncopyable&) = delete;

protected:
    noncopyable() = default;
    ~noncopyable() = default;
};

class copyable
{
protected:
    copyable() = default;
    ~copyable() = default;
};

#endif
