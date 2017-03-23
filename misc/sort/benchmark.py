from time import time


def benchmark(func):
    """Record elapsed time and function calls"""
    print('now: {}...'.format(func.__doc__))
    def wrap(*args, **kwargs):
        wrap.cnt += 1
        wrap._started = time() * 1000   # milliseconds
        ret = func(*args, **kwargs)
        wrap.ms += time() * 1000 - wrap._started
        return ret
    wrap.cnt = wrap.ms = 0
    return wrap
