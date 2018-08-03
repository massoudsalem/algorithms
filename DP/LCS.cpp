#include <bits/stdc++.h>
using namespace std;

int mem[1000+5][1000+5];
string s1,s2;
int LCS(unsigned int p1=0,unsigned int p2=0){
  if(p1==s1.size()||p2==s2.size())
    return 0;
  int &ret=mem[p1][p2];
  if(~ret) return ret;
  if(s1[p1]==s2[p2])
    ret=1+LCS(p1+1,p2+1);
  else
    ret=max(LCS(p1+1,p2),LCS(p1,p2+1));
  return ret;
}
