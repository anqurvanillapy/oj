"""\
    Lambda recursion
    ================

    Generate the factorial of integer n, by using a lambda function that
    invokes itself.

    More precisely, it is achieved by using Y combinator (a.k.a. fixed
    point combinators in lambda calculus), without introducing named
    lambdas, Python internals or some higher-order functions like reduce()
    and map().
"""

from math import factorial
from benchmark import calltime


@calltime
def lrfact(n):
    """Recursive with lambda functions"""
    # In fact, I have no ideas how to count the number of calls of those
    # lambda functions.
    return (lambda fn: lambda args: fn(fn, args)) \
        (lambda f, x: f(f, x - 1) * x if x > 0 else 1) \
        (n)


@calltime
def rfact(n):
    """Recursive"""
    return rfact(n - 1) * n if n > 0 else 1


@calltime
def ifact(n):
    """Iterative"""
    for i in range(n - 1, 0, -1): n *= i
    return n


# N should be large enough for testing performance.
N = 100


# Use math.factorial() to present the value.
print('math.factorial({}) = {}'.format(N, factorial(N)))
list(map(lambda x: print('cnt={1}, ms={2}'.format(x(N), x.cnt, x.ms)),
    [lrfact, rfact, ifact]))
