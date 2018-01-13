/**
 *  Increment operators are compiler-specific
 *  =========================================
 *
 *  Note: Compile with clang++, g++ in versions:
 *  - clang version 4.0.0-1ubuntu1 (tags/RELEASE_400/rc1)
 *  - gcc version 6.3.0 20170406 (Ubuntu 6.3.0-12ubuntu2)
 */

#include <iostream>

int
main()
{
    int a = 0;
    ++a += a++ + a++;
    // g++: 3; clang++: 2.
    std::cout << a << std::endl;
    return 0;
}
