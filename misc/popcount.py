"""Population count, or Hamming weight problem.
"""

from wh import trek

SIZE = 64
M1 = 0x55_55_55_55_55_55_55_55
M2 = 0x33_33_33_33_33_33_33_33
M4 = 0x0f_0f_0f_0f_0f_0f_0f_0f
M8 = 0x00_ff_00_ff_00_ff_00_ff
M16 = 0x00_00_ff_ff_00_00_ff_ff
M32 = 0x00_00_00_00_ff_ff_ff_ff
# Most bits in N0 are 0, while most are 1 in N1.
N0 = 0x00_00_00_00_00_00_00_ff
N1 = 0x55_55_55_55_55_55_55_55


@trek()
def popcount0(n):
    """Come-to-mind-first naive solution"""
    count = 0
    for _ in range(SIZE):
        if n & 1:
            count += 1
        n >>= 1
    return count


with popcount0(N0) as ret:
    assert ret == 8
with popcount0(N1) as ret:
    assert ret == 32


@trek()
def popcount1(n):
    """No shifting and better for N0 situation"""
    count = 0
    while n:
        n &= n - 1
        count += 1
    return count


with popcount1(N0) as ret:
    assert ret == 8
with popcount1(N1) as ret:
    assert ret == 32


@trek()
def popcount2(n):
    """Naive better solution for N1 situation"""
    n = (n & M1) + ((n >> 1) & M1)
    n = (n & M2) + ((n >> 2) & M2)
    n = (n & M4) + ((n >> 4) & M4)
    n = (n & M8) + ((n >> 8) & M8)
    n = (n & M16) + ((n >> 16) & M16)
    n = (n & M32) + ((n >> 32) & M32)
    return n


with popcount2(N0) as ret:
    assert ret == 8
with popcount2(N1) as ret:
    assert ret == 32
