
// 暴力模拟
#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f//七个3f
using namespace std;
const int N = 5e5 + 10;//10代表上下浮动的范围
int a[N];//存储元素
bool st[N];//****标记某个数字是否被删除****很有用
void solve()
{
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	for(int i = 0; i < k; i ++)
	{
		int minv = INF;
		int pos = -1;
		//找最小值同时记录下标
		for(int j = 0; j < n; j ++)
		{
			if(minv > a[j] && !st[j])
			{
				minv = a[j];
				pos = j;
			}
		}

		st[pos] = true;

		//对左侧的数字进行操作
		for(int j = pos - 1; j >= 0; j --)
		{
			if(!st[j])
			{
				a[j] += minv;
				break;//注意这里是break，也就是结束循环
			}
		}
       //对右侧的数字进行操作
		for(int j = pos + 1; j < n; j ++)
		{
			if(!st[j])
			{
				a[j] += minv;
				break;
			}
		}
	}
    //最后的遍历，将所有剩下的结果进行输出
	for(int i = 0; i < n; i ++)
	{
		if(!st[i])
			cout << a[i] << " ";
	}
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);//关流的操作

	int t = 1;
	// cin >> t;
	while(t--)//laoyanyuanle
	solve();
};

//for(int i=0;i<n;i++){
//     cin>>temp;v.push_back(temp);
//   }
//   while(k--){
//   int min=INF;int pos=-1;
//   for(int i=0;i<n;i++){
//     if(min>v[i]){min=v[i];pos=i;}//找到最小元素
//   }
//   v.erase(min);
//   if((pos-1>=0)&&(pos+1<=n-1)){
//     v[pos-1]+=min;v[pos+1]+=min;
//   }
  

//   }
//   for(int i=0;i<v.size();i++){
//     cout<<v[i]<<" ";
//   } 
// cout<<endl;
//   return 0;