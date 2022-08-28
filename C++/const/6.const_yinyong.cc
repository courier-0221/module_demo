#include <iostream>
using namespace std;

// 基本操作，传入引用修改对象中成员变量
namespace base
{
class Timer
{
public:
    Timer(int hour, int minutes, int seconds)
        : _hour(hour)
        , _minutes(minutes)
        , _seconds(seconds)
    {}

    void showTime()
    {
        printf("%d %d %d\n", _hour, _minutes, _seconds);
    }

public:
    int _hour;
    int _minutes;
    int _seconds;
};

void modifyTime(Timer &time)
{
    time._hour = 30;
}

void test()
{
    Timer time(12,12,12);
    time.showTime();
    
    printf("----------modifytime----------\n");

    modifyTime(time);
    time.showTime();
}
}

// 参数为常引用，不允许对实参做修改
namespace constCannotModify
{
class Timer
{
public:
    Timer(int hour, int minutes, int seconds)
        : _hour(hour)
        , _minutes(minutes)
        , _seconds(seconds)
    {}

    void showTime()
    {
        printf("%d %d %d\n", _hour, _minutes, _seconds);
    }

public:
    int _hour;
    int _minutes;
    int _seconds;
};

void modifyTime(const Timer &time)
{
    time._hour = 30;    //err 这里报错，不允许修改
}

void test()
{
    Timer time(12,12,12);
    time.showTime();
    
    printf("----------modifytime----------\n");

    modifyTime(time);
    time.showTime();
}
}

int main(void)
{
    //base::test();
    constCannotModify::test();  // err 会报错
    return 0;
}