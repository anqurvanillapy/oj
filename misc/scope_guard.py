"""\
A scope guard in Python.  Because an additional indent for `with' taking over
the whole function looks unnecessary and ugly.
"""


def scope_guard(target):
    """Scope guard that forwards the target by the first argument"""

    def _decorator(wrapped_fn):
        def _wrapper(*args, **kwargs):
            with target:
                wrapped_fn(target, *args, **kwargs)

        return _wrapper

    return _decorator


class Foo:
    """Guardee"""

    def __enter__(self):
        print("enter")

    def __exit__(self, *exc):
        print("exit")

    def say(self, v):
        print(v)


@scope_guard(Foo())
def foo(f, n):
    f.say(n)
    # Guaranteed to call __exit__.
    raise RuntimeError("oops")


foo(42)
