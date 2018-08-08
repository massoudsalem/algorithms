#include <bits/stdc++.h>
using namespace std;
int mem[5000+5][5000+5],dp[5000+5][5000+5];
int n,arr[5000+5];
int LIS(int idx=0,int last=n){
  if(idx==n) return 0;
  int &ret=mem[idx][last];
  if(~ret) return ret;
  ret=LIS(idx+1,last);
  if(arr[idx]>arr[last])
    ret = max(ret , 1 + LIS(idx+1,idx));
  return ret;
}
int LIS(){
	for(int i=n-1;i>=0;--i)
		for(int j=0;j<=n;++j){
			dp[i][j]=dp[i+1][j];
			if(arr[i]>arr[j])
				dp[i][j]=max(dp[i][j],dp[i+1][i]+1);
		}
		return dp[0][n];
}
