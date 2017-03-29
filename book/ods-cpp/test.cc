#include "myods.h"

int
main(int argc, const char *argv[])
{
    myods::array_stack<int> s;
    s.push(1); s.push(2); s.push(3);
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;

    myods::fast_array_stack<int> fs;
    fs.push(1); fs.push(2); fs.push(3);
    std::cout << fs.pop() << std::endl;
    std::cout << fs.pop() << std::endl;
    std::cout << fs.pop() << std::endl;
    return 0;
}
