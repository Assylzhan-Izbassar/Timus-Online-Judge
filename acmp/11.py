a = list(map(int,input().strip().split()))[:2]

k = a[0]
n = a[1]

dp = []

for i in range(0,n+1):
  dp.append(0)

dp[0] = 1

for i in range(1,n+1):
  for j in range(1,k+1):
    if(i-j >= 0):
      dp[i] = dp[i] + dp[i-j]

print(dp[n])
      
  
