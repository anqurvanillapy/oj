"""A magical trie"""

from collections import defaultdict


class Trie:
    def __init__(self, *vals):
        _trie = lambda: defaultdict(_trie)
        self._trie = _trie()

        cur = self._trie
        for val in vals:
            cur = self._trie
            for v in val:
                cur = cur[v]
            cur.setdefault(None)

    def exists(self, word):
        cur = self._trie
        for c in word:
            if c not in cur:
                return False
            cur = cur[c]
        return None in cur


trie = Trie("aaa", "bbb", "ccc")
print(trie.exists("aaa"))
print(trie.exists("ddd"))
