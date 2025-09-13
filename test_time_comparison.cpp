#include "time.hpp"
#include <cassert>

int main()
{
    std::cout << "Begin unit test for: bool operator==(const Time& rhs)\n";
    {
        std::cout << "Test 2 default constructors\n";
        Time t1;
        Time t2;
        assert(t1 == t2);
        std::cout << "Pass\n";
    }

    {
        std::cout << "Test 2 hour constructors\n";
        Time t1(5);
        Time t2(5);
        assert(t1 == t2);
        std::cout << "Pass\n";
    }

    {
        std::cout << "Test 2 hour, minute constructors\n";
        Time t1(30, 40);
        Time t2(30, 40);
        assert(t1 == t2);
        std::cout << "Pass\n";
    }

    {
        std::cout << "Test 2 hour, minute, second constructors\n";
        Time t1(50, 15, 20);
        Time t2(50, 15, 20);
        assert(t1 == t2);
        std::cout << "Pass\n";
    }

    {
        std::cout << "Test non-equivalence\n";
        Time t1;
        Time t2(10);
        assert(!(t1 == t2));
        std::cout << "Pass\n";
    }
    std::cout << "Done testing bool operator==(const Time& rhs)\n";
    return 0;
}
