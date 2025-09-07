#include "time.hpp"
#include <cassert>

int main() {
    std::cout << "Begin unit test for: Time::Time(int hour)\n";
    {
        std::cout << "Set hour to 5\n";
        Time t1(5);
        TimePart ref = {5,0,0};
        assert(t1.time() == ref);
        std:: cout << "Pass\n";
    }
     
    {
        std::cout << "Set hour to -1\n";
        Time t1(-1);
        TimePart ref = {0,0,0};
        assert(t1.time() == ref);
        std:: cout << "Pass\n";
    }

    {
        std::cout << "Set hour to 24\n";
        Time t1(24);
        TimePart ref = {0,0,0};
        assert(t1.time() == ref);
        std:: cout << "Pass\n";
    }

    {
        std::cout << "Set hour to 26\n";
        Time t1(26);
        TimePart ref = {2,0,0};
        assert(t1.time() == ref);
        std:: cout << "Pass\n";
    }
    std::cout << "Done testing Time::Time(int hour)\n";
    return 0;
}
