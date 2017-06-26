from collections import deque


def roundrobin(q, verbose, *args):
    """Calculates the total time of executing several processes using
    round-robin scheduling.  A process is a tuple with arrival time and
    execute time."""
    # sorted could sort the processes by their arrival time.
    procs, queue = deque(sorted([[at, et, et] for at, et in args])), deque()

    # States.
    job = None
    quantum = q
    elapsed = 0

    _can_terminate = lambda: not queue and not procs and not job
    _log = lambda *args: print(*args) if verbose else None

    while True:
        try:
            # If there is any process in procs, and it is time to arrive.
            assert(procs[0][0] == elapsed)
            queue.append(procs.popleft())
            _log('proc', tuple(queue[-1][:2]), 'arrives')
        except:
            pass
        finally:
            if _can_terminate(): break

        # If timeslice (quantum) is sufficient.
        if quantum:
            try:
                if not job: job = queue.popleft()
            except:
                # Waiting for the next process arrival.
                quantum, elapsed = q, elapsed + 1
                continue

            if job[2]:
                job[2] -= 1
                quantum, elapsed = quantum - 1, elapsed + 1
                continue
            else:
                _log('job', tuple(job[:2]), 'done at', elapsed)
                job = None
                quantum = q # NOTE: Doesn't take time
                continue
        else:
            if job and job[2]: queue.append(job)
            try:
                job = queue.popleft()
            except: job = None
            quantum = q # NOTE: Doesn't take time

        if _can_terminate(): break

    return elapsed


# Test case on Wikipedia.
print(roundrobin(100, True, (0, 250), (50, 170), (130, 75), (190, 100),
    (210, 130), (350, 50)))

# Test CPU idle.
print(roundrobin(100, False, (0, 150), (300, 150)))
