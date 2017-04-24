#ifndef __MYPFDS__MYRASTACK_H
#define __MYPFDS__MYRASTACK_H

namespace mypfds {

template <typename T> class rastack;

template <typename T>
class rastack_node {
public:
    rastack_node(rastack_node<T>* n,
                 rastack_node<T>* l,
                 rastack_node<T>* r,
                 const T& v)
        : next(n), left(l), right(r), val(v)
    {
        size = left == nullptr || right == nullptr ? 1
            : left->size + right-> size;
    }

    ~rastack_node()
    {
        delete next;
        delete left;
        delete right;
    }

    friend rastack<T>;

    // Copy operator and assignment operator deleted.
    rastack_node(const rastack_node<T>&) = delete;
    rastack_node<T>& operator=(const rastack_node<T>&) = delete;
protected:
    int size;
    rastack_node<T>* next;
    rastack_node<T>* left;
    rastack_node<T>* right;
    T val;
};

/// Random access stack.
template <typename T>
class rastack {
public:
    rastack() : size(0), head(nullptr), tail(nullptr) { /* nop */ }
    ~rastack()
    {
        delete head;
        delete tail;
    }

    // O(log n).
    const T& get(int i);
    void set(int i, const T& v);

    // O(1).
    void push(const T& v);
    T& pop();

    inline T& get_head() { return head->val; }
    inline T& get_tail() { return tail->val; }

    // Likewise, copying and assignment not allowed due to complication.
    rastack(const rastack<T>&) = delete;
    rastack<T>& operator=(const rastack<T>&) = delete;
private:
    int size;
    rastack_node<T>* head;
    rastack_node<T>* tail;
};

} /* namespace mypfds */

#include "myrastack.tcc"

#endif /* !__MYPFDS__MYRASTACK_H */
