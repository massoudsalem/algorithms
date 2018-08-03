#include <bits/stdc++.h>
using namespace std;

int mem[1000+5][1000+5];
int w,n,price[1000+5],weight[1000+5];
int napsack(int curr=0,int rem=w){
  if(rem<0)
    return -1e9;
  if(!rem||curr==n)
    return 0;
  int &ret = mem[curr][rem];
  if(~ret) return ret;
  ret=max(price[curr]+napsack(curr,rem-weight[curr]),napsack(curr+1,rem));
  return ret;
}
