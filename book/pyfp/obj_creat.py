"""\
    Object creation
    ===============

    > Left to right or right to left?

    In the case of simple integer arithmetic, the arithmetic operators have
    identical performance. There's no optimization benefit.

    But when working with something like list appending, there might be
    some optimization improvements when changing the association rules.

    What's important for functional design is the idea that the operator
    can be used in any order to produce the same results, and has no hidden
    side effects that restrict the way this operator can be used.

    Note: Right to left is faster, phew.
"""

from timeit import timeit


list(map(lambda i, c: print('{}={}'.format(i, timeit(c))),
    ('lr', 'rl'),
    ('((((([]+[1])+[2])+[3])+[4])+[5])+[6]',
     '[]+([1]+([2]+([3]+([4]+([5]+[6])))))')))
