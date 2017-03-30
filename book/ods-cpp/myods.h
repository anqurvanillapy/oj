#ifndef __MYODS__MYODS_H
#define __MYODS__MYODS_H

#include <iostream>
#include <algorithm>
#include <cassert>

namespace myods {

/* Array-based lists. */

template <class T>
class array {
public:
    explicit array(int len);
    ~array() { /* nop */ };

    inline int size() const { return length; }

    T& operator[](int i);
    array<T>& operator=(array<T> &a);
	T* operator+(int i);
private:
    T* arr;
    int length;
};

template <class T>
class array_stack {
public:
    array_stack() : arr(1), top(0) { /* nop */ };
    ~array_stack() { /* nop */ };

    inline int const size() { return top; }

    inline T const get(int i);
    inline T set(int i, T v);

    virtual void add(int i, T v);
    virtual T remove(int i);

    // XXX: push() and pop() not on the book.
    inline void push(T v);
    inline T pop();

    virtual void resize();
protected:
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
    array_queue() : arr(1), n(0), tail(0) { /* nop */ };
    ~array_queue() { /* nop */ };

    inline int const size() { return n; }

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
    inline void enqueue(T v);
    inline T dequeue();
    inline void push(T v);
    inline T pop();
private:
    using array_queue<T>::arr;
    using array_queue<T>::tail;
    using array_queue<T>::n;
};

} /* namespace myods */

/// Template implementations.
#include "array.tcc"
#include "array_stack.tcc"
#include "fast_array_stack.tcc"
#include "array_queue.tcc"
#include "array_deque.tcc"

#endif /* !__MYODS__MYODS_H */
