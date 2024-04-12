//本题最大收获：当数据量很小时，往往就是暴力，而且一般都是dfs
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=10+20;
struct plane{
int t,d,l;//最早开始时间，油耗时间，降落时间
}p[N];
bool st[N];//记录飞机状态
int n;//记录飞机个数
//以上内容都应该是全局变量，否则递归函数无法修改
bool dfs(int u,int time){//u代表已经有u架飞机降落，time代表当前的时间(其实也是前一架飞机降落的时间)
  if(u>=n){
    return true;//当前的方案合法
  }
  for(int i=0;i<n;i++){
   if(!st[i]){
     st[i]=true;
     if(p[i].t+p[i].d<time){//合法性检查
       st[i]=false;//回溯
       return false;//当前及以后的方案都不合法，直接return
     }
    int t=max(time,p[i].t)+p[i].l;//开始降落时间+当前飞机降落所需要的时间
     if(dfs(u+1,t)){
       return true;
     }
     st[i]=false;//这里也要回溯，在同一层的各方案之间切换时需要将本方案中的第一架飞机置为false
   }
   
  }
  return false;//如果都没有返回真，那就说明没有合法方案
}

void solve(){
  cin>>n;
  for(int i=0;i<n;i++){

    cin>>p[i].t>>p[i].d>>p[i].l;
  }
  if(dfs(0,0))
  cout<<"YES"<<endl;
  else
  cout<<"NO"<<endl;
  for(int i=0;i<n;i++){
    st[i]=false;
  }//以防万一，将所有飞机状态置为0；

}
signed main()
{
  // 请在此输入您的代码
 int t=1;
 cin>>t;//测试用例的个数，这个需要审题
 while(t--){
   solve();
 }
  return 0;
}