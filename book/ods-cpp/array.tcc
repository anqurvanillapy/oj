namespace myods {

template <class T>
array<T>::array(int len)
{
    length = len;
    arr = new T[length];
}

template <class T>
T&
array<T>::operator[](int i)
{
    assert(i >= 0 && i < length);
    return arr[i];
}

template <class T>
array<T>&
array<T>::operator=(array<T> &a)
{
    if (arr != NULL) delete[] arr;
    arr = a.arr;
    a.arr = NULL;
    length = a.length;

    return *this;   // for multiple assignments
}

template <class T>
T*
array<T>::operator+(int i) {
    return &arr[i];
}

} /* namespace myods */
