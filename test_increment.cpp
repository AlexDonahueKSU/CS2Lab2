// Alex Donahue
// Kent State University - Computer Science 2 - Lab 2
// test_increment.cpp
// Testing Time's increment function

#include "time.hpp"
#include <cassert>

int main()
{
    std::cout << "Begin unit test for: void increment()\n";
    {
        std::cout << "Increment of 1 second, no rollover\n";
        Time t1(5, 5, 5);
        t1.increment();
        TimePart ref = {5, 5, 6};
        assert(t1.time() == ref);
        std::cout << "Pass\n";
    }

    {
        std::cout << "Increment of 1 second, second rolls over\n";
        Time t1(5, 5, 59);
        t1.increment();
        TimePart ref = {5, 6, 0};
        assert(t1.time() == ref);
        std::cout << "Pass\n";
    }

    std::cout << "Done testing void increment()\n";
    return 0;
}
