"""\
Pick a card, if it is black, pick another one while no giving back the
previous, else stop picking. Calculate the expected value of how many cards
could be picked at a time.
"""

BLACK = 26
ALL = 52


def get_ev(n, m):
    """Pick n from m."""
    ret = 0
    for i in range(n):
        ret += permute(n, i + 1) / permute(m, i + 1)
    return ret


cache = {}
def permute(n, k):
    """Recursive permutation with cache."""
    if n < k: raise ArithmeticError('invalid permutation')

    try: return cache[(n, k)]
    except: pass

    if k < 2: return n
    else:
        ret = n
        ret *= permute(n - 1, k - 1)
    cache[(n, k)] = ret
    return ret


print(get_ev(BLACK, ALL))
