namespace myods {

template <class T>
const T
dual_array_deque<T>::get(int i)
{
    // Front queue stores data inversely.
    if (i < front.size()) return front.get(front.size() - i - 1);
    else return back.get(i - front.size());
}

template <class T>
T
dual_array_deque<T>::set(int i, T v)
{
    if (i < front.size()) return front.set(front.size() - i - 1, v);
    else return back.set(i - front.size(), v);
}

template <class T>
void
dual_array_deque<T>::add(int i, T v)
{
    if (i < front.size()) return front.add(front.size() - i, v);
    else return back.add(i - front.size(), v);
    balance();
}

template <class T>
T
dual_array_deque<T>::remove(int i)
{
    T ret = (i < front.size()) ? front.remove(front.size() - i - 1)
        : back.remove(i - front.size());
    balance();

    return ret;
}

template <class T>
void
dual_array_deque<T>::balance()
{
    if (front.size() * 3 < back.size() || back.size() * 3 < front.size()) {
        int n = size();

        // New a front backing array.
        int nf = n / 2;    // new front size
        array<T> _front(std::max(2 * nf, 1));
        for (int i = 0; i < nf; ++i) _front[nf - i - 1] = get(i);

        // New a back backing array.
        int nb = n - nf;    // new back size
        array<T> _back(std::max(2 * nb, 1));
        for (int i = 0; i < nb; ++i) _back[i] = get(nf + i);

        front.arr = _front;
        front.top = nf;
        back.arr = _back;
        back.top = nb;
    }
}

} /* namepsace myods */
