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
    explicit array_stack() : arr(1), n(0) { /* nop */ };
    ~array_stack() { /* nop */ };

    inline int size() const { return n; }

    inline T get(int i) const;
    inline T set(int i, T v);

    virtual void add(int i, T v);
    virtual T remove(int i);

    // XXX: push() and pop() not on the book.
    inline void push(T v);
    inline T pop();

    virtual void resize();
protected:
    array<T> arr;   // i.e. backing array
    int n;
};

template <class T>
class fast_array_stack : public array_stack<T> {
public:
    void add(int i, T v) override;
    T remove(int i) override;
    void resize() override;
private:
    using array_stack<T>::arr;
    using array_stack<T>::n;
};

} /* namespace myods */

/// Template implementations.
#include "array.tcc"
#include "array_stack.tcc"
#include "fast_array_stack.tcc"

#endif /* !__MYODS__MYODS_H */
