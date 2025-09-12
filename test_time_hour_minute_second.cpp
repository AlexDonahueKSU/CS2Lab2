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
     
    std::cout << "Done testing Time::Time(int hour, int minute, int second)\n";
    return 0;
}
