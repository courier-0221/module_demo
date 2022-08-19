#include "Fiber.h"

void run_in_fiber()
{
    std::cout << "run_in_fiber begin" << std::endl;
    Fiber::YieldToHold();
    std::cout << "run_in_fiber mid" << std::endl;
    Fiber::YieldToHold();
    std::cout << "run_in_fiber end" << std::endl;
}

int main(int argc, char** argv)
{
    Fiber::GetThis();
    std::cout << "main begin" << std::endl;
    Fiber::ptr fiber(new Fiber(run_in_fiber));
    fiber->swapIn();
    std::cout << "main after swapIn1" << std::endl;
    fiber->swapIn();
    std::cout << "main after swapIn2" << std::endl;
    fiber->swapIn();
    std::cout << "main after end" << std::endl;
    return 0;
}
