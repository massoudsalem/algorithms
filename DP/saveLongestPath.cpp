#include <bits/stdc++.h>
using namespace std;
int mem[100+5][100+5];
int dp[100+5][100+5];
int n,arr[100+5][100+5];
int t,x,y;
// saving longest path below
bool valid(int tx,int ty){//tx is row //ty is column
    return (tx>=0&&tx<x&&ty>=0&&ty<y);  //check validation and return
}
int SLP(int i,int j){
  if(i==x) return 0;
  int &ret=mem[i][j];
  if(~ret) return ret;
  ret=arr[i][j]+SLP(i+1,j);
  if(valid(i+1,j+1))
    ret=max(ret,arr[i][j]+SLP(i+1,j+1));
  if(valid(i+1,j-1))
    ret=max(ret,arr[i][j]+SLP(i+1,j-1));
  return ret;
}
int SLP(){
  for(int i=x-1;i>=0;--i)
    for(int j=0;j<=y;++j){
      dp[i][j]=arr[i][j]+dp[i+1][j];
      if(valid(i+1,j+1))
        dp[i][j]=max(dp[i][j],arr[i][j]+dp[i+1][j+1]);
      if(valid(i+1,j-1))
        dp[i][j]=max(dp[i][j],arr[i][j]+dp[i+1][j-1]);
    }
    return dp[0][0];
}
