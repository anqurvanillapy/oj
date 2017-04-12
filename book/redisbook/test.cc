#include <iostream>
#include <string>
#include "mydict.h"

int
main(int argc, const char *argv[])
{
    dict<std::string, int> d;

    d.set("a", 1);
    d.set("b", 2);
    d.set("c", 3);

    std::cout << d.get("a") << std::endl;
    std::cout << d.get("b") << std::endl;
    std::cout << d.get("c") << std::endl;
    std::cout << d.get("d") << std::endl;

    return 0;
}
