template <typename K, typename V>
dict_hashtable<K, V>::~dict_hashtable()
{
    delete table;
    table = NULL;
}
