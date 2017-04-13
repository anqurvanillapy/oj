template <typename K, typename V>
dict<K, V>::dict()
: ht{4, 0}, rehashidx(-1), seed(rd())
{
    /* nop */
}

template <typename K, typename V>
dict<K, V>::~dict()
{
    /* nop */
}

template <typename K, typename V>
const V&
dict<K, V>::get(K k)
{
    unsigned index = hash_index(k);
    std::vector<dict_entry<K, V>>& entry = ht[0].table[index];

    std::reverse_iterator<typename std::vector<dict_entry<K, V>>::iterator> rit
        = entry.rbegin();

    for (; rit != entry.rend(); ++rit) if (rit->key == k) return rit->val;

    throw std::runtime_error("key error");
}

template <typename K, typename V>
void
dict<K, V>::set(K k, V v)
{
    unsigned index = hash_index(k);

    ht[0].table[index].emplace_back(k, v);
    ht[0].used++;
}

template <typename K, typename V>
unsigned
dict<K, V>::hash_index(K k)
{
    __int128_t hash;
    MurmurHash3_x64_128(static_cast<void *>(&k), sizeof(k), seed, &hash);

    return hash & ht[0].sizemask;
}
