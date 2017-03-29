namespace myods {

template <class T> inline
T
array_stack<T>::get(int i) const
{
    return arr[i];  // already has bounds-checking
}

template <class T> inline
T
array_stack<T>::set(int i, T v)
{
    T ret = arr[i];
    arr[i] = v;
    return ret;
}

template <class T>
void
array_stack<T>::add(int i, T v)
{
    if (n + 1 > arr.size()) resize();   // growing
    
    // Copy the data from i to n.
    for (int j = n; j > i; --j) arr[j] = arr[j - 1];
    
    arr[i] = v;
    n++;
}

template <class T>
T
array_stack<T>::remove(int i)
{
    T ret = arr[i];
    for (int j = i; j < n - 1; ++j) arr[j] = arr[j + 1];
    n--;
    if (arr.size() >= 3 * n) resize();  // shrinking
    return ret;
}

/// XXX: Not on the book.
template <class T> inline
void
array_stack<T>::push(T v)
{
    add(n, v);
}

/// XXX: Not on the book.
template <class T> inline
T
array_stack<T>::pop()
{
    return remove(std::max(n - 1, 0));
}

template <class T>
void
array_stack<T>::resize()
{
    // Grows doubly or shrinks 1/3.
    array<T> a(std::max(2 * n, 1));
    for (int i = 0; i < n; ++i) a[i] = arr[i];
    arr = a;
}   // array<T> a would be free for it is automatic

} /* namespace myods */
