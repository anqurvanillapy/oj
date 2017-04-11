template <typename K, typename V>
V
dict<K, V>::get(const K& k)
{
    unsigned index = hash_index(k);

    return ht[0][index];
}

template <typename K, typename V>
void
dict<K, V>::set(K k, T v)
{
    unsigned index = hash_index(k);
    // If it is not being incrementally rehashed.
    if (rehashidx < 0) {
    }
}

template <typename K, typename V>
unsigned
dict<K, V>::hash_index(const K& k)
{
    __int128_t hash;
    MurmurHash3_x64_128(k, sizeof(k), seed, &hash);

    // TODO: check the rehashing.
    return hash & ht[0].sizemask;
}
