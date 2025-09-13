#include "time.hpp"
#include <cassert>

int main() {
    std::cout << "Begin unit test for: Time::Time(int hour, int minute, int second)\n";
    {
        std::cout << "Set hour to 5, minute to 2, and second to 30\n";
        Time t1(5,2,30);
        TimePart ref = {5,2,30};
        assert(t1.time() == ref);
        std:: cout << "Pass\n";
    }

    {
        std::cout << "Set hour to 20, minute to 59, and second to 60\n";
        Time t1(20,59,60);
        TimePart ref = {21,0,0};
        assert(t1.time() == ref);
        std:: cout << "Pass\n";
    }

    {
        std::cout << "Set hour to -1, minute to 40, and second to -30\n";
        Time t1(-1,40,-30);
        TimePart ref = {0,39,30};
        assert(t1.time() == ref);
        std:: cout << "Pass\n";
    }

    {
        std::cout << "Set hour to 500, minute to -300, and second to 6000\n";
        Time t1(500,-300,6000);
        // This timepart took some mathematics on paper to figure out!
        TimePart ref = {16,40,0};
        assert(t1.time() == ref);
        std:: cout << "Pass\n";
    }
     
    std::cout << "Done testing Time::Time(int hour, int minute, int second)\n";
    return 0;
}
