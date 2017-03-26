"""
    2to1
    ====

    Given any two of the pre-order, in-order or post-order traversals of a
    binary tree, return the graphical tree representation and the other
    traversals.
"""

class _Node:
    def __init__(self, v, l, r):
        self.value = v
        self.left = l
        self.right = r


def solve(_pre=None, _in=None, _post=None):
    """\
    Set two tree traversals, return the other and visualize it.
    Non-string-typed arguments would be replaced with None.
    """
    try:
        trv = dict(filter(lambda x: x[1],
            tuple(zip(('pre', 'in', 'post'), [list(t.replace(' ', '')) \
            if type(t) == str else None for t in (_pre, _in, _post)]))))

        assert(len(trv) == 2)
    except AssertionError:
        raise TypeError('should be given two string-typed traversals')

    # At 1st in pre-order or the last in post-order is the root.
    root = trv.get('pre', trv['post'][-1])[0]
    print(root)


def _visualize():
    return


solve(None, 'cba', 'cba')
