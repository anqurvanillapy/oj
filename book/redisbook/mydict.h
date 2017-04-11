#ifndef __MYDICT_H
#define __MYDICT_H

#include <random>

#include "smhasher/src/MurmurHash3.h"

template <typename K, typename V>
class dict_entry {
public:
    dict_entry(K k, V v);
    ~dict_entry();

    void push(dict_entry<K, V>& node);
    inline void set(K k, V v);
private:
    K key;
    V val;
};

template <typename K, typename V>
class dict_hashtable {
public:
    dict_hashtable();
    ~dict_hashtable();

    inline dict_entry<K, V>& operator[](const unsigned& index);
private:
    std::vector<dict_entry<K, V>>* table;
    unsigned long size;
    unsigned long sizemask;
    unsigned long used;
};

template <typename K, typename V>
class dict {
public:
    dict();
    ~dict();

    V get(const K& key);
    void set(K key, V val);
private:
    unsigned hash_index(const K& key);

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
