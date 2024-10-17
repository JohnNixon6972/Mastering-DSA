class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        nums = list(set(nums))    
        nums.sort()
        glo_max = 1
        curr = 1
        for i in range(1,len(nums)):
            print(nums[i],nums[i-1])
            if nums[i]-1 == nums[i-1]:
                curr += 1
                glo_max = max(glo_max,curr)
            else:
                curr = 1

        return glo_max



        