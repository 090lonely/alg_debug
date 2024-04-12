// #include <bits/stdc++.h>
// #define int long long
// const int N=2e5+20;
// using namespace std;
// signed main()
// {
//   // 请在此输入您的代码
// int n;int sum=0;int a[N];
// cin>>n;
// for(int i=0;i<n;i++){
//   cin>>a[i];
// }
// for(int i=0;i<n;i++){//暴力
//   for(int j=i+1;j<n;j++){//注意这里不要乘自己啊！
//     sum+=a[i]*a[j];
//   }
// }
// cout<<sum<<endl;
//   return 0;
// }
#include <iostream>
using namespace std;
typedef long long ll;
int a[200005];
int main()
{
  // 请在此输入您的代码
  int n;ll sum=0,ans=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
    sum+=a[i];
  }
  for(int i=0;i<n;i++)//*****乘法分配律，在每一次减掉这个数的时候，去乘sum也就是剩下的所有数
  {
    sum-=a[i];
    ans+=a[i]*sum;
  }
  printf("%lld",ans);
  return 0;
}