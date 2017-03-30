namespace myods {

template <class T>
void
fast_array_stack<T>::add(int i, T v)
{
    if (top + 1 > arr.size()) resize();
    std::copy_backward(arr + i, arr + top, arr + top + i);
    arr[i] = v;
    top++;
}

template <class T>
T
fast_array_stack<T>::remove(int i)
{
    T ret = arr[i];
    std::copy(arr + i + 1, arr + top, arr + i);
	top--;
	if (arr.size() >= 3 * top) resize();
	return ret;
}

template <class T>
void
fast_array_stack<T>::resize()
{
    array<T> a(std::max(2 * top, 1));
    std::copy(arr + 0, arr + top, a + 0);
    arr = a;
}

} /* namespace myods */
