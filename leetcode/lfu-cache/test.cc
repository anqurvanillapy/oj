#include <iostream>
#include "LFUCache.h"

int
main(int argc, const char *argv[])
{
    LFUCache cache{2};

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl; // returns 1
    cache.put(3, 3);                        // evicts key 2
    std::cout << cache.get(2) << std::endl; // returns -1 (not found)
    std::cout << cache.get(3) << std::endl; // returns 3
    cache.put(4, 4);                        // evicts key 1.
    std::cout << cache.get(1) << std::endl; // returns -1 (not found)
    std::cout << cache.get(3) << std::endl; // returns 3
    std::cout << cache.get(4) << std::endl; // returns 4

    return 0;
}
