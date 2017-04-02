import random
from benchmark import calltime


FIXTURE = [random.randint(0, 100) for _ in range(100)]


@calltime
def rquicksort(arr):
    """Recursive quicksort"""
    if len(arr) <= 1: return arr
    return rquicksort([i for i in arr[1:] if i < arr[0]]) + \
           [arr[0]] + \
           rquicksort([i for i in arr[1:] if i > arr[0]])


list(map(lambda x: print('cnt={1}, ms={2}'.format(x(FIXTURE), x.cnt, x.ms)),
    [rquicksort]))
