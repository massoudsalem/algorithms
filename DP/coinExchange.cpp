#include <bits/stdc++.h>
using namespace std;

int coins[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long mem[11][30000+1];
long long dp[11][30000+1];
long long ce(int idx=0,int rem=30000+1){
  if(rem==0)
    return 1;
  if(rem < 0||idx == 11)  // 11 is number of coins.
    return 0;
  long long &ret=mem[idx][rem];
  if(~ret) return ret;
  return ret=ce(idx+1,rem)+ce(idx,rem-coins[idx]);
}
