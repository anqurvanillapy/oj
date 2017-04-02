namespace myods {

template <class T>
constexpr int
rootish_array_stack<T>::itob(int i)
{
    // b is the smallest integer such that (b + 1)(b + 2)/2 >= i + 1.
    double _b = (-3.0 + std::sqrt(9 + 8 * i)) / 2.0;
    return (int)std::ceil(_b);
}

template <class T>
T
rootish_array_stack<T>::get(int i)
{
    int b = itob(i);                // in which block
    int j = i - b * (b + 1) / 2;    // location in the block
    return blocks.get(b)[j];
}

template <class T>
T
rootish_array_stack<T>::set(int i, T v)
{
    int b = itob(i);
    int j = i - b * (b + 1) / 2;
    T ret = blocks.get(b)[j];
    blocks.get(b)[j] = v;
    return ret;
}

template <class T>
void
rootish_array_stack<T>::add(int i, T v)
{
    int b = blocks.size();
    if (b * (b + 1) / 2 < n + 1) grow();
    n++;
    for (int j = n - 1; j > i; --j) set(j, get(j - 1));
    set(i, v);
}

template <class T>
T
rootish_array_stack<T>::remove(int i)
{
    int b = blocks.size();
    T ret = get(i);

    for (int j = i; j < n - 1; ++j) set(j, get(j + 1));
    n--;
    if ((b - 2) * (b - 1) / 2 >= n) shrink();

    return ret;
}

template <class T>
void
rootish_array_stack<T>::grow()
{
    blocks.add(blocks.size(), new T[blocks.size() + 1]);
}

template <class T>
void
rootish_array_stack<T>::shrink()
{
    int b = blocks.size();
    while (b > 0 && (b - 2) * (b - 1) / 2 >= n) {
        delete[] blocks.remove(blocks.size() - 1);
        b--;
    }
}

} /* namespace myods */
