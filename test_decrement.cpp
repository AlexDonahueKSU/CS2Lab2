// Alex Donahue
// Kent State University - Computer Science 2 - Lab 2
// test_decrement.cpp
// Tests for decrementing in the Time decrement function.

#include "time.hpp"
#include <cassert>

int main()
{
    std::cout << "Begin unit test for: void decrement()\n";

    {
        std::cout << "Decrement of 1 second, no rollover\n";
        Time t1(5, 5, 5);
        t1.decrement();
        TimePart ref = {5, 5, 4};
        assert(t1.time() == ref);
        std::cout << "Pass\n";
    }

    {
        std::cout << "Decrement of 1 second, second rolls over\n";
        Time t1(5, 5, 0);
        t1.decrement();
        TimePart ref = {5, 4, 59};
        assert(t1.time() == ref);
        std::cout << "Pass\n";
    }

    {
        std::cout << "Decrement of 1 second, second and minute rolls over\n";
        Time t1(20, 0, 0);
        t1.decrement();
        TimePart ref = {19, 59, 59};
        assert(t1.time() == ref);
        std::cout << "Pass\n";
    }

    std::cout << "Done testing void decrement()\n";
    return 0;
}
