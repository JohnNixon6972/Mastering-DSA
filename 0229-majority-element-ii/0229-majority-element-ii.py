from collections import defaultdict
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        freq = defaultdict(int)

        for num in nums:
            freq[num] += 1

        res = []
        for key in freq:
            if freq[key] > len(nums) // 3:
                res.append(key)

        return res

            

        