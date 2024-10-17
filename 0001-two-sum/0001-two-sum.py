class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        buf = {}

        for index, num in enumerate(nums):
            diff = target - num
            if diff in buf:
                return [index, buf[diff]]
            if num not in buf:
                buf[num] = index
            