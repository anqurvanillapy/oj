"""\
Fibonacci number function:
    * Recursive
    * Recursive, but improved
    * Iterative
    * Iterative, but a generator
"""

from callcnt import counter


@counter
def rfib(n):
    """Recursive Fibonacci number function, unimproved."""
    return rfib(n - 1) + rfib(n - 2) if n > 2 else 1


# Mapping store.
kvs = {}


@counter
def rfib1(n):
    """Imporved recursive function"""
    if n > 2:
        try: return kvs[n]
        except: pass
        ret = rfib1(n - 1) + rfib1(n - 2)
        kvs[n] = ret
        return ret
    return 1


@counter
def ifib(n):
    """Iterative function"""
    a, b = 0, 1
    if n > 1:
        for i in range(n): a, b = b, a + b
        return a
    return 1


def gen_ifib(n):
    """Iterative generator"""
    a, b, i = 0, 1, 0
    while True:
        a, b, i = b, a + b, i + 1
        yield a
        if i >= n: break


# It won't print anything if not converted into a list.
list(map(lambda x: print('v={}, cnt={}, ms={}'.format(x(35), x.cnt, x.ms)),
         [rfib, rfib1, ifib]))

# Mechanism of a generator is different.
print([i for i in gen_ifib(7)])
