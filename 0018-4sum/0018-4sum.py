class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = set()
        n = len(nums)
        for i in range(n):
            for j in range(i+1,n):
                mem = {}
                for k in range(j+1,n):
                    rem = target - (nums[i] + nums[j] + nums[k])

                    if rem in mem:
                        current_sub = [nums[i] ,nums[j],nums[k],rem ]
                        current_sub.sort()
                        res.add(tuple(current_sub))

                    mem[nums[k]] = ''

        
    
        ans = []

        for row in res:
            ans.append(list(row))
        return ans