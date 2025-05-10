#include <stdio.h>
#include "transpose.hpp"
#include "timer.hpp"


int main(void)
{
    Timer timer;

    // timer.start_gpu();
    // transpose_gpt();
    // timer.stop_gpu();
    // timer.duration_gpu("transpose_gpt result.");
    bank();

    return 0;
}