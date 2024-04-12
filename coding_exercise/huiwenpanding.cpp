#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s,t;//这道题主要是你要学会STL里面的一些非常好的函数
  cin>>s;t=s;
  reverse(s.begin(),s.end());
  cout<<(s==t?"Y":"N");
  return 0;
}