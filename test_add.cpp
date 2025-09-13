// Alex Donahue
// Kent State University - Computer Science 2 - Lab 2
// test_add.cpp
// Tests for adding two Time objects together

#include "time.hpp"
#include <cassert>

int main()
{
    std::cout << "Begin unit test for: void add(int seconds)\n";

    {
        std::cout << "Add 5 seconds\n";
        Time t1(5, 5, 5);
        t1.add(5);
        TimePart ref = {5, 5, 10};
        assert(t1.time() == ref);
        std::cout << "Pass\n";
    }

    {
        std::cout << "Add 10 seconds, seconds rollover\n";
        Time t1(5, 5, 55);
        t1.add(10);
        TimePart ref = {5, 6, 5};
        assert(t1.time() == ref);
        std::cout << "Pass\n";
    }

    {
        std::cout << "Add 20 seconds, seconds and minutes rolls over\n";
        Time t1(5, 59, 59);
        t1.add(20);
        TimePart ref = {6, 0, 19};
        assert(t1.time() == ref);
        std::cout << "Pass\n";
    }

    std::cout << "Done testing void add(int seconds)\n";
    return 0;
}
