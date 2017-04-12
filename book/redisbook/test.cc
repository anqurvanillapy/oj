#include <iostream>
#include <string>
#include "mydict.h"

int
main(int argc, const char *argv[])
{
    int a;
    dict<std::string, int> d;

    d.set("a", 1);
    a = d.get("a");

    std::cout << a << std::endl;
    return 0;
}
