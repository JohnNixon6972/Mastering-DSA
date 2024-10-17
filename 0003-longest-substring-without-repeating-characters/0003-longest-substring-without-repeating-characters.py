class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        seen = {}
        glo_max = 0
        curr_max = 0

        left = -1 

        for i in range(len(s)):
            if s[i] in seen:
                if left < seen[s[i]]:
                    left = seen[s[i]]
                    curr_max = i - seen[s[i]]
                else:
                    curr_max += 1
                seen[s[i]] = i

            else:
                curr_max += 1
                seen[s[i]] = i
            glo_max = max(glo_max,curr_max)

            # print(seen)
            # print(curr_max)

        return glo_max