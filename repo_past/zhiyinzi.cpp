#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > GetPrimeFactor(long long x) {
  vector<pair<int, int> > ret;
  for (int i = 2; i * i <= x; i++) {//确定初始值2和结束值根号x
    if (x % i == 0) {
      int cnt = 0;
      while (x % i == 0) {
        cnt++;
        x /= i;
      }
      // x的质因子i出现了cnt次
      ret.push_back(make_pair(i, cnt));//构造函数来构造pair
    }
  }
  if (x > 1) {//最后如果x仍然大于一，说明还剩一个最大的因子
    ret.push_back(make_pair(x, 1));
  }
  return ret;
}
void PrintAns(long long x, const vector<pair<int, int>> ans) {
  printf("%d = ", x);
  for (int i = 0; i < ans.size(); i++) {
    if (i != 0) {
      printf(" + ");
    }
    printf("%d^%d", ans[i].first, ans[i].second);//控制格式    ^  
  }
  printf("\n");
}
int main(){
    long long x=2021041820210418;
    //vector<pair<int, int>> ret=GetPrimeFactor(x);
    //PrintAns(x,ret);
    cout<<(int)x;



    return 0;
}