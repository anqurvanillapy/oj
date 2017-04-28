#ifndef __MYDICT_H
#define __MYDICT_H

#include <random>
#include <iterator>

#include "smhasher/src/MurmurHash3.h"

template <typename K, typename V> class dict;

template <typename K, typename V>
class dict_entry {
public:
    dict_entry() { /* nop */ }
    dict_entry(K k, V v);
    ~dict_entry();

    friend dict<K, V>;
private:
    K key;
    V val;
};

template <typename K, typename V>
class dict_hashtable {
public:
    // `explicit' constructor is unnecessary here, while it is better to have it
    // in the top-level class exposed to the users.
    //
    // NOTE: Given `explicit' the compiler would raise the error that looks like
    // it triggers the default copy constructor.
    dict_hashtable(unsigned s);
    ~dict_hashtable();

    friend dict<K, V>;
private:
    std::vector<std::vector<dict_entry<K, V>>> table;
    // No need to use std::size_t, which is a constant returned by operator
    // `sizeof' (BTW, sizeof cannot be overloaded).
    unsigned long size;
    unsigned long sizemask;
    unsigned long used;
};

template <typename K, typename V>
class dict {
public:
    dict();
    ~dict();

    const V& get(K key);
    void set(K key, V val);
private:
    unsigned hash_index(K k);

    dict_hashtable<K, V> ht[2];
    int rehashidx;

    // Random device for generating seeds.
    std::random_device rd;
    unsigned seed;
};

/// Implementations.
#include "dict_entry.tcc"
#include "dict_hashtable.tcc"
#include "dict.tcc"

#endif /* !__MYDICT_H */
