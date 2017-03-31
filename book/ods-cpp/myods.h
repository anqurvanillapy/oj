#ifndef __MYODS__MYODS_H
#define __MYODS__MYODS_H

#include <iostream>
#include <algorithm>
#include <cassert>

namespace myods {

/// Pre-declared classes for friendship.
template <class T> class dual_array_deque;

/* Array-based lists. */

template <class T>
class array {
public:
    explicit array(int len);
    ~array() { /* nop */ }

    constexpr int size() { return length; }

    T& operator[](int i);
    array<T>& operator=(array<T> &a);
	T* operator+(int i);
protected:
    T* arr;
    int length;
};

template <class T>
class array_stack {
public:
    array_stack() : arr(1), top(0) { /* nop */ }
    ~array_stack() { /* nop */ }

    constexpr int size() { return top; }

    inline T const get(int i);
    inline T set(int i, T v);

    virtual void add(int i, T v);
    virtual T remove(int i);

    virtual void resize();

    // XXX: push() and pop() not on the book.
    inline void push(T v);
    inline T pop();
protected:
    friend class dual_array_deque<T>;
    // Backing array.
    array<T> arr;
    // top is also the stack size, and arr[0] is the stack base.
    int top;
};

template <class T>
class fast_array_stack : public array_stack<T> {
public:
    void add(int i, T v) override;
    T remove(int i) override;
    void resize() override;
private:
    using array_stack<T>::arr;
    using array_stack<T>::top;
};

template <class T>
class array_queue {
public:
    array_queue() : arr(1), n(0), tail(0) { /* nop */ }
    ~array_queue() { /* nop */ }

    constexpr int size() { return n; }

    void add(T v);
    T remove();

    // XXX: enqueue() and dequeue() not on the book. Simply some aliases.
    inline void enqueue(T v) { add(v); }
    inline T dequeue() { return remove(); }

    void resize();
protected:
    array<T> arr;
    int tail, n;
};

template <class T>
class array_deque : public array_queue<T> {
public:
    inline T const get(int i);
    inline T set(int i, T v);

    void add(int i, T v);
    T remove(int i);

    using array_queue<T>::resize;

    // XXX: The methods below not on the book.
    inline void enqueue(T v) { add(n, v); }
    inline T dequeue() { return remove(0); }
    inline void push(T v) { add(n, v); }
    inline T pop() { return remove(std::max(n - 1, 0)); }
private:
    using array_queue<T>::arr;
    using array_queue<T>::tail;
    using array_queue<T>::n;
};

template <class T>
class dual_array_deque {
public:
    dual_array_deque() { /* nop */ }
    ~dual_array_deque() { /* nop */ }

    constexpr int size() { return front.size() + back.size(); }

    const T get(int i);
    T set(int i, T v);

    void add(int i, T v);
    T remove(int i);

    void balance();

    // XXX: The methods below not on the book.
    inline void enqueue(T v) { add(size(), v); }
    inline T dequeue() { return remove(0); }
    inline void push(T v) { add(size(), v); }
    inline T pop() { return remove(size() - 1); }
private:
    array_stack<T> front;
    array_stack<T> back;
};

} /* namespace myods */

/// Template implementations.
#include "array.tcc"
#include "array_stack.tcc"
#include "fast_array_stack.tcc"
#include "array_queue.tcc"
#include "array_deque.tcc"
#include "dual_array_deque.tcc"

#endif /* !__MYODS__MYODS_H */
