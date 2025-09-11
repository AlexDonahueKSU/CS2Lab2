#include "time.hpp"
#include <cassert>

int main() {
    std::cout << "Begin unit test for: Time::Time(int hour)\n";
    {
        std::cout << "Set hour to 5, minute to 2\n";
        Time t1(5,2);
        TimePart ref = {5,2,0};
        assert(t1.time() == ref);
        std:: cout << "Pass\n";
    }
     
    {
        std::cout << "Set hour to 23, minute to 66\n";
        Time t2(23, 66);
        TimePart ref = {0,6,0};
        assert(t2.time() == ref);
        std:: cout << "Pass\n";
    }

    {
        std::cout << "Set hour to 10, and minute to negative 5\n";
        Time t3(10, -5);
        TimePart ref = {9,55,0};
        assert(t3.time() == ref);
        std:: cout << "Pass\n";
    }
    
    {
        std::cout << "Set hour to 10, and minute to -61\n";
        Time t4(10, -61);
        TimePart ref = {8,59,0};
        assert(t4.time() == ref);
        std:: cout << "Pass\n";
    }

    {
        std::cout << "Set hour to 30, and minute to 121\n";
        Time t5(30, 121);
        TimePart ref = {8,1,0};
        assert(t5.time() == ref);
        std:: cout << "Pass\n";
    }
    std::cout << "Done testing Time::Time(int hour)\n";
    return 0;
}
