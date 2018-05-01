"""Memory leaks by GC.
"""

import sys, gc
from functools import reduce
from operator import sub, truediv


def rss():
    with open("/proc/self/stat") as s:
        return 4096 * int(s.read().split()[23])


def gcsize():
    return sum(
        [
            sys.getsizeof(o) if hasattr(o, "__class__") else 0
            for o in gc.get_objects()
        ]
    )


rss0, gc0 = rss(), gcsize()


diff = lambda: (rss() - rss0, gcsize() - gc0)
stat = lambda s0, s1: round(reduce(truediv, map(sub, s0, s1)) * 100, 3)


buf = [bytearray(1024) for i in range(200 * 1024)]
diff0 = diff()
print("0: rss={} gcsize={}".format(*diff0))

buf = buf[::2]
diff1 = diff()
print("1: rss={} gcsize={}".format(*diff1))
print("{}% back to os".format(stat(diff0, diff1)))

b = [bytearray(1024) for i in range(2 * 1024)]
# b = [bytearray(int(1024 * 1.5)) for i in range(2 * 1024)]
diff2 = diff()
print("2: rss={} gcsize={}".format(*diff2))
print("{}% back to os".format(stat(diff1, diff2)))
