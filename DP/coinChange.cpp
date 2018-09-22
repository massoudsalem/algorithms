#include <bits/stdc++.h>
using namespace std;

long long mem[100000][5];
long long dp[100000];
long long coins[5]={1,5,10,25,50};
long long n;
long long CEX(int coin=10000,int exchage=0){  //single item dp
    if(!coin)
      return 1;
    if(coin<0)
      return 0;
    long long &ret=mem[coin][exchage];
    if(~ret) return ret;
    ret=0;
    for(int i=exchage;i<5;++i)
      ret+=CEX(coin-coins[i],i);
    return ret;
}
long long CEXitr(int n=0){
  memset(dp,0,sizeof dp);
  dp[0]=1;
  for(int j=0;j<5;++j){
  for(int i=coins[j];i<100000;++i){
      dp[i]+=dp[i-coins[j]];
    }
  }
  return dp[n];
}
