#Code Written by : John Nixon
#Date: 29:10:2022  Time: 09:56:32
#Copyrights are applicable
import sys
import os
from collections import defaultdict
sys.setrecursionlimit(10000)
try:
    sys.stdin = open('./input.txt', 'r')
    sys.stdout = open('./output.txt', 'w')
except:
    pass


for case in range(1,int(input())+1):
    m,n,p = map(int ,input().split())
    
    mapd = defaultdict(list)
    for player in range(1,m+1):
        day = list(map(int,input().split()))
        mapd[player] = day
    req = 0
    
    john = mapd[p]
    # print(mapd)
    for day in range(n):
        day_max = -1
        
        for player in range(1,m+1):
            if player != p:
                day_max = max(day_max,mapd[player][day])
        
        johns_score = john[day]
        
        if johns_score < day_max:
            req += abs(johns_score - day_max)
            
    print(f"Case #{case}: {req}")
        