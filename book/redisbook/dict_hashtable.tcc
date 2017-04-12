template <typename K, typename V>
dict_hashtable<K, V>::dict_hashtable(size_t s)
: table(s, std::vector<dict_entry<K, V>>(0)), size(s), sizemask(s - 1), used(0)
{
    /* nop */
}

template <typename K, typename V>
dict_hashtable<K, V>::~dict_hashtable()
{
    /* nop */
}
