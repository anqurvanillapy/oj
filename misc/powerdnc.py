from functools import reduce
from benchmark import calltime

@calltime
def rpower(n, k):
    """Recursive divide and conquer"""
    if k == 0: return 1
    p = rpower(n, k >> 1)
    if k & 1: return n * p * p
    return p * p

@calltime
def ipower(n, k):
    """Iterative divide and conquer"""
    ret = 1
    while k:
        if k & 1: ret *= n
        n *= n
        k >>= 1
    return ret

print(reduce(lambda x, y: x == y, map(lambda x: x(2, 10), [rpower, ipower])))
list(map(lambda x: print('cnt={1} ms={2}'.format(x(2, 50000), x.cnt, x.ms)),
    [rpower, ipower]))
