#ifndef __MYDICT_H
#define __MYDICT_H

#include <string>
#include <random>

#include "smhasher/src/MurmurHash3.h"

template <typename K, typename V>
class dict_entry {
public:
    dict_entry(K k, T v) : key(k), val(v), next(nullptr)
    { /* nop */ }
    ~dict_entry() { /* nop */ }
    void push(dict_entry<K, V>& node);
private:
    K key;
    T val;
    dict_entry<K, V>* next;
};

template <typename K, typename V>
class dict_hashtable {
public:
    dict_hashtable() : table(nullptr), size(0), sizemask(0), used(0)
    { /* nop */ }
    ~dict_hashtable() { /* nop */ }
private:
    dict_entry<K, V>* table;
    unsigned long size;
    unsigned long sizemask;
    unsigned long used;
};

template <typename K, typename V>
class dict {
public:
    dict() : rehashidx(-1), seed(rd()) { /* nop */ }
    ~dict() { /* nop */ }

    T get(const K& key);
    void set(K key, V val);
private:
    unsigned int hash_index(const K& key);

    dict_hashtable<K, V> ht[2];
    int rehashidx;

    // Random device for generating seeds.
    std::random_device rd;
    unsigned int seed;
};

/// Implementations.
#include "dict.tcc"

#endif /* !__MYDICT_H */
