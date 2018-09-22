#include <bits/stdc++.h>
using namespace std;

int mem[1000+5][1000+5];
int dp[2][2000000+5];
int kdp[20000+5];
int w,n,price[1000+5],weight[1000+5];
int LKS(int curr=0,int rem=w){  //multi-items mem
  if(rem<0)
    return -1e9;
  if(!rem||curr==n)
    return 0;
  int &ret = mem[curr][rem];
  if(~ret) return ret;
  ret=max(price[curr]+LKS(curr,rem-weight[curr]),LKS(curr+1,rem));
  return ret;
}
int LKS(){  //single item dp
  for(int i=0;i<=n;++i)
    for(int j=0;j<=w;++j){
      dp[i&1][j]=dp[!(i&1)][j];
      if(j>=weight[i])
        dp[i&1][j]=max(dp[i&1][j],price[i]+dp[!(i&1)][j-weight[i]]);
    }
    return dp[!(n&1)][w];
}
int LKSOptimized(){  //single item dp
  for(int i=0;i<=n;++i)
    for(int j=20000;j>=weight[i];--j){
        kdp[j]=max(kdp[j],price[i]+kdp[j-weight[i]]);
    }
    return kdp[w];
}
