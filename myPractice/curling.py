#Code Written by : John Nixon
#Date: 29:10:2022  Time: 10:04:01
#Copyrights are applicable
import math
import sys
import os
sys.setrecursionlimit(10000)
try:
    sys.stdin = open('./input.txt', 'r')
    sys.stdout = open('./output.txt', 'w')
except:
    pass


for cases in range(1,int(input())+1):
    Rs,Rh = map(int,input().split())
    # Rh /= 1
    n = int(input())
    red_stones = []
    for _ in range(n):
        x,y = map(int,input().split())
        distance = math.sqrt(x**2 + y**2) - Rs
        if distance <= Rh:
            red_stones.append(distance)
        
    m = int(input())
    yellow_stones = []
    for _ in range(m):
        x,y = map(int,input().split())
        distance = math.sqrt(x**2 + y**2) - Rs
        if distance <= Rh:
            yellow_stones.append(distance)
     
    red_stones.sort(reverse=True)
    yellow_stones.sort(reverse=True)
    
    while(len(red_stones) > 0 and len(yellow_stones) > 0):
        if red_stones[0] > yellow_stones[0]:
            red_stones.pop(0)
        else:
            yellow_stones.pop(0)
        
    red_score = len(red_stones)
    yellow_score = len(yellow_stones)
    
    print(f"Case #{cases}: {red_score} {yellow_score}")