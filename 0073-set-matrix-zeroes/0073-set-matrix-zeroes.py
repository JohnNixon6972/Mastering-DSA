
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows = defaultdict(bool)
        cols = defaultdict(bool)
        
        nr = len(matrix)
        nc = len(matrix[0])

        for r in range(nr):
            for c in range(nc):
                if matrix[r][c] == 0:
                    rows[r] = True
                    cols[c] = True

        for r in range(nr):
            for c in range(nc):
                if rows[r] or cols[c]:
                    matrix[r][c] = 0