 #다이나믹 프로그래밍
 #2839번 , 설탕 배달
 
n=int(input())
dp=[5001]*(n+5)

dp[3]=1
dp[5]=1

for i in range(6,n+1):
   dp[i]=min(dp[i-3],dp[i-5])+1

if dp[n]<5001:
    print(dp[n])
else:
    print(-1)