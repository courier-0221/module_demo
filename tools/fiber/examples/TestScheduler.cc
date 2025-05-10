#include "Scheduler.h"

void test_fiber()
{
    static int s_count = 5;
    std::cout << "test in fiber s_count=" << s_count << std::endl;

    sleep(1);
    if(--s_count >= 0)
    {
        Scheduler::GetThis()->schedule(&test_fiber, CurrentThread::tid());
    }
}

int main(int argc, char** argv)
{
    std::cout << "main" << std::endl;
    Scheduler sc(3, false, "test");
    sc.start();
    sleep(2);
    std::cout << "---start schedule---" << std::endl;
    sc.schedule(&test_fiber);
    sc.stop();
    std::cout << "---end schedule---" << std::endl;
    return 0;
}
