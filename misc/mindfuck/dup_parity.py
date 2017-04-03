"""\
    Duplicate even or odd numbers in a list,achieved by a pretty Lisp-like
    Python code.
"""

print(
    (lambda fn0: lambda a0, b0: fn0(fn0, a0, b0)) \
        (lambda f, ls, dup: [] if len(ls) == 0 else \
            (lambda y, nls, d: \
                [nls[0]] + [nls[0]] + y(y, nls[1:], not d) if d \
                else [nls[0]] + y(y, nls[1:], not d)) \
            (f, ls, dup)) \
        (range(10), True) # True: even; False: odd
)
