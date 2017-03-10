def counter(func):
    """Count the function calls, for benchmarking."""
    def wrap(*args, **kwargs):
        wrap.called += 1
        return func(*args, **kwargs)
    wrap.called = 0
    return wrap
