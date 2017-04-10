#ifndef __MYODS__MYODS_H
#define __MYODS__MYODS_H

#include <algorithm>
#include <random>
#include <cmath>
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

    inline int size() { return length; }

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

    inline int size() { return top; }

    inline const T get(int i);
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

    inline int size() { return n; }

    void add(T v);
    T remove();

    void resize();
protected:
    array<T> arr;
    int tail, n;
};

template <class T>
class array_deque : public array_queue<T> {
public:
    array_deque() { /* nop */ }
    ~array_deque() { /* nop */ }

    inline const T get(int i);
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

    inline int size() { return front.size() + back.size(); }

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

template <class T>
class rootish_array_stack {
public:
    rootish_array_stack() : n(0) { /* nop */ }
    ~rootish_array_stack() { /* nop */ }

    inline int size() { return n; }

    inline int itob(int i);
    T get(int i);
    T set(int i, T v);

    void add(int i, T v);
    T remove(int i);

    void grow();
    void shrink();

    // XXX: push() and pop() not on the book.
    inline void push(T v) { add(n, v); }
    inline T pop() { return remove(std::max(n - 1, 0)); }
private:
    array_stack<T*> blocks;
    int n;
};

/// Exercise 2.2
template <class T>
class random_queue : public array_queue<T> {
public:
    random_queue() : rd(), gen(rd()) { /* nop */ }
    ~random_queue() { /* nop */ }

    using array_queue<T>::add;
    using array_queue<T>::remove;

    void swap_tail();
    inline void enqueue(T v) { add(v); }
    inline T dequeue() { swap_tail(); return remove(); }
private:
    using array_queue<T>::arr;
    using array_queue<T>::tail;
    using array_queue<T>::n;

    std::random_device rd;
    std::mt19937 gen;
};

} /* namespace myods */

/// Template implementations.
#include "array.tcc"
#include "array_stack.tcc"
#include "fast_array_stack.tcc"
#include "array_queue.tcc"
#include "array_deque.tcc"
#include "dual_array_deque.tcc"
#include "rootish_array_stack.tcc"
#include "random_queue.tcc"

#endif /* !__MYODS__MYODS_H */
