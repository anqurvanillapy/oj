# === solution === #

class Solution:
    def twoSum(self, nums, target):
        """\
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        vi = {} # value-index store
        for i, v in enumerate(nums):
            c = target - v  # complement
            if c in vi: return [vi[c], i]
            else: vi[v] = i
        return [0, 0]

# === EOS === #

s = Solution()

list(map(lambda l: print(l, '->', s.twoSum(l, 6)),
    [list(range(10)), [], [0, 1], [-3, 4, 9, 90]]))
