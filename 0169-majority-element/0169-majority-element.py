from collections import defaultdict
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        freq = defaultdict(int)

        for e in nums:
            freq[e] += 1

        for key in freq:
            if freq[key] > len(nums) // 2:
                return key

        