namespace myods {

template <class T>
T const
array_deque<T>::get(int i)
{
    return arr[(tail + i) % arr.size()];
}

template <class T>
T
array_deque<T>::set(int i, T v)
{
    T ret = arr[(tail + i) % arr.size()];
    arr[(tail + i) % arr.size()] = v;
    return ret;
}

template <class T>
void
array_deque<T>::add(int i, T v)
{
    if (n + 1 > arr.size()) resize();
    
    if (i < n / 2) {    // shift arr[0], ..., arr[i - 1] left one position
        tail = (tail == 0) ? arr.size() - 1 : tail - 1;
        for (int j = 0; j < i; ++j) {
            arr[(tail + j) % arr.size()] = arr[(tail + j + 1) % arr.size()];
        }
    } else {    // shift arr[i], ..., arr[n - 1] right one position
        for (int j = n; j > i; --j) {
            arr[(tail + j) % arr.size()] = arr[(tail + j - 1) % arr.size()];
        }
    }

    arr[(tail + i) % arr.size()] = v;
    n++;
}

template <class T>
T
array_deque<T>::remove(int i)
{
    T ret = arr[(tail + i) % arr.size()];
    
    if (i < n / 2) {    // shift arr[0], ..., arr[i - 1] right one position
        for (int j = i; j > 0; --j) {
            arr[(tail + j) % arr.size()] = arr[(tail + j - 1) % arr.size()];
        }
        tail = (tail + 1) % arr.size();
    } else {    // shift arr[i], ..., arr[n - 1] left one position
        for (int j = i; j < n; ++j) {
            arr[(tail + j) % arr.size()] = arr[(tail + j + 1) % arr.size()];
        }
    }

    n--;
    if (arr.size() >= 3 * n) resize();

    return ret;
}

} /* myods */
