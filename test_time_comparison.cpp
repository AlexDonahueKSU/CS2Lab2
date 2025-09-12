#include "time.hpp"
#include <cassert>

int main() {
    std::cout << "Begin unit test for: bool operator==(const Time& rhs)\n";
    {
        std::cout << "Test 2 default constructors\n";
        Time t1();
        Time t2();
        // assert(t1.time() == t2.time());
        
    }
    std::cout << "Done testing bool operator==(const Time& rhs)\n";
    return 0;
}
