template <typename K, typename V>
V
dict<K, V>::get(const K& key)
{
    unsigned int index = hash_index(key);
    // If it is not being incrementally rehashed.
    if (rehashidx >= 0) {
        ht[0] 
    }
}

template <typename K, typename V>
void
dict<K, V>::set(K key, T val)
{
}

template <typename K, typename V>
unsigned
dict<K, V>::hash_index(const K& key)
{
    __int128_t hash;
    MurmurHash3_x64_128(key, sizeof(key), seed, &hash);

    // TODO: check the rehashing.
    return hash & ht[0].sizemask;
}
