
#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, char** av)
{
#ifdef CPPUTEST
    printf("CPPUTEST: \n");
#endif
    return CommandLineTestRunner::RunAllTests(ac, av);
}

