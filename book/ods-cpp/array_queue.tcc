namespace myods {

template <class T>
void
array_queue<T>::add(T v)
{
    if (n + 1 > arr.size()) resize();
    arr[(tail + n) % arr.size()] = v;
    n++;
}

template <class T>
T
array_queue<T>::remove()
{
    T ret = arr[tail];
    // Circularly goes forward, without deleting the element.
    tail = (tail + 1) % arr.size();
    n--;
    if (arr.size() >= 3 * n) resize();
    return ret;
}

template <class T>
void
array_queue<T>::resize()
{
    array<T> a(std::max(2 * n, 1));
    for (int i = 0; i < n; ++i) a[i] = arr[(tail + i) % arr.size()];
    arr = a;
    tail = 0;
}

} /* namespace myods */
