class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        pres = [False] * len(nums)

        for num in nums:
            if pres[num-1]:
                return num

            pres[num-1] = True

        