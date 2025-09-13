// Alex Donahue
// Kent State University - Computer Science 2 - Lab 2
// test_diff.cpp
// Testing subtracting time between 2 objects

#include "time.hpp"
#include <cassert>

int main()
{
    std::cout << "Begin unit test for: int diff(const Time &sub)\n";
    {
        std::cout << "Subtract two small times.\n";
        Time t1(5, 5, 5);
        Time t2(5, 5, 4);
        assert(t1.diff(t2) == 1);
        std::cout << "Pass\n";
    }

    {
        std::cout << "Subtract times that end in a negative.\n";
        Time t1(5, 30, 15);
        Time t2(8, 30, 15);
        assert(t1.diff(t2) == -10800);
        std::cout << "Pass\n";
    }

    std::cout << "Done testing int diff(const Time &sub)\n";
    return 0;
}
