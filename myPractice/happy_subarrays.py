#Code Written by : John Nixon
#Date: 29:10:2022  Time: 10:36:19
#Copyrights are applicable
import sys
import os
sys.setrecursionlimit(10000)
try:
    sys.stdin = open('./input.txt', 'r')
    sys.stdout = open('./output.txt', 'w')
except:
    pass

for cases in range(1,int(input())+1):
    n = int(input())
    numbers = list(map(int,input().split()))
    
    dp = [0]*n
    
    dp[0] = numbers[0]
    
    
    for i in range(1,n):
        if numbers[i] >= 0:
            dp[i] = (dp[i-1] + (numbers[i] * (i+1)))
        
    print(dp)
    # print(f"Case #{cases}: {result}")