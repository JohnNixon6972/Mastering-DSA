class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        cache = [[float("inf")]* (len(word2)+1) for _ in range(len(word1)+1)]
        for col in range(len(word2)+1): 
            cache[len(word1)][col] = len(word2) - col 
        for row in range(len(word1)+1): 
            cache[row][len(word2)] = len(word1) - row
        for i in range(len(word1) - 1, -1, -1):
            for j in range(len(word2)-1,-1,-1):
                if word1[i] == word2[j]: 
                    cache[i][j] = cache[i+1][j+1]
                else: 
                    cache[i][j] = min(cache[i+1][j],cache[i][j+1],cache[i+1][j+1])+1

        return cache[0][0]
