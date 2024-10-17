class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []

        for i in range(1,numRows+1):
            # if i == 1:
            #     res.append([1,1])
            #     continue
                

            sub = []
            for j in range(i):
                if j == 0 or j == i -1:
                    sub.append(1)
                else:
                    sub.append(res[-1][j-1] + res[-1][j])

            res.append(sub)
        return res
