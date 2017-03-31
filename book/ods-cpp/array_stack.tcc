namespace myods {

template <class T> inline
T const
array_stack<T>::get(int i)
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
    if (top + 1 > arr.size()) resize();   // growing
    
    // Copy the data from i to n.
    for (int j = top; j > i; --j) arr[j] = arr[j - 1];
    
    arr[i] = v;
    top++;
}

template <class T>
T
array_stack<T>::remove(int i)
{
    T ret = arr[i];
    for (int j = i; j < top - 1; ++j) arr[j] = arr[j + 1];
    top--;
    if (arr.size() >= 3 * top) resize();  // shrinking
    return ret;
}

template <class T>
void
array_stack<T>::resize()
{
    // Grows doubly or shrinks 1/3.
    array<T> a(std::max(2 * top, 1));
    for (int i = 0; i < top; ++i) a[i] = arr[i];
    arr = a;
}   // array<T> a would be free for it is automatic

/// XXX: Not on the book.
template <class T> inline
void
array_stack<T>::push(T v)
{
    add(top, v);
}

/// XXX: Not on the book.
template <class T> inline
T
array_stack<T>::pop()
{
    return remove(std::max(top - 1, 0));
}

} /* namespace myods */
