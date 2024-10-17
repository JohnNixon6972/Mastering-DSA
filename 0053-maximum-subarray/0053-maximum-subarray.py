class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        glo_max = -float("inf")
        curr_sum = 0
        for num in nums:
            curr_sum += num
           

            glo_max = max(curr_sum,glo_max)
            if curr_sum < 0:
                curr_sum = 0

        return glo_max