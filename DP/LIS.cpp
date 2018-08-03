#include <bits/stdc++.h>
using namespace std;
int mem[5000+5][5000+5];
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
