from time import time


def counter(func):
    """Count the function calls and record the elapsed time for benchmarking."""
    def wrapper(*args, **kwargs):
        wrapper.cnt += 1
        wrapper._started = time() * 1000   # milliseconds
        ret = func(*args, **kwargs)
        wrapper.ms += time() * 1000 - wrapper._started
        return ret
    wrapper.cnt = wrapper.ms = 0
    return wrapper
