#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Cmp(const string &s1,const string &s2)
{
  return s1+s2<s2+s1;
}
int main() {
  int N;
  cin >> N;
  vector<string> a(N);//小括号代表单个容器所开的大小
  //   vector<string> s[n];注意二者区别，注释掉的是数组用的中括号
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  sort(a.begin(),a.end(),Cmp);
  for (int i=0;i<N;i++) {
    cout<<a[i];
  }
  return 0;
}