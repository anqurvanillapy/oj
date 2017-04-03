"""\
    Duplicate even or odd numbers in a list, achieved by a pretty Lisp-like
    Python code.
"""

print(
    (lambda fn: lambda a, b: fn(fn, a, b)) \
        (lambda f, ls, dup: [] if len(ls) == 0 else \
            (lambda y, nls, d: \
                [nls[0]] + [nls[0]] + y(y, nls[1:], not d) if d \
                else [nls[0]] + y(y, nls[1:], not d)) \
            (f, ls, dup)) \
        (range(10), True) # True: even; False: odd
)
