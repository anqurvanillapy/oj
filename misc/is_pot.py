def is_pot(n):
    """\
    Check if n is the power of 2.  It can also be done by using logical right
    shift operator in O(n) time, where n is the bits of n's type.
    """
    return n == n & -n


tc = [1, 2, 3, 4, 5, 6, 7, 8]
print(tc)
print(list(map(lambda x: is_pot(x), tc)))
