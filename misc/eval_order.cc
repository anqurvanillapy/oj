// #include <iostream>

int
main()
{
    int a = 0;
    // ++a: side-effect sequence-before value computation.
    // +=: side effect sequence-after value of computations (not side-effects)
    // of both left and right arguments.
    // a++: value computation is sequence-before side-effect.
    ++a += 2 + a++;
    // std::cout << a << std::endl;
    return 0;
}
