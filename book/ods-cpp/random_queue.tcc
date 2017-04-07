namespace myods {

template <class T>
void
random_queue<T>::swap_tail()
{
    // Uniformly pick an element to the tail.
    if (n > 1) {
        // Possibly the tail is picked.
        int i;
        std::uniform_int_distribution<> dis(0, n - 1);
        if ( (i = dis(gen))) {
            i = (tail + i) % arr.size();
            T tmp = arr[i];
            arr[i] = arr[tail];
            arr[tail] = tmp;
        }
    }
}

} /* namespace myods */
