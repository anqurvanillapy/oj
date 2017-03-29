namespace myods {

template <class T>
void
fast_array_stack<T>::add(int i, T v)
{
    if (n + 1 > arr.size()) resize();
    std::copy_backward(arr + i, arr + n, arr + n + i);
    arr[i] = v;
    n++;
}

template <class T>
T
fast_array_stack<T>::remove(int i)
{
    T ret = arr[i];
    std::copy(arr + i + 1, arr + n, arr + i);
	n--;
	if (arr.size() >= 3 * n) resize();
	return ret;
}

template <class T>
void
fast_array_stack<T>::resize()
{
    array<T> a(std::max(2 * n, 1));
    std::copy(arr + 0, arr + n, a + 0);
    arr = a;
}

} /* namespace myods */
