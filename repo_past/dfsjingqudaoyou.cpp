//暴力代码：DFS
#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << '\n';
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int N = 2e5 + 10;

typedef pair<int,int> pii;

map<pii, int>st;//记录从{x, y}的距离是多少,例如从1到3的距离是4这样子map[{1,3}]=3;
int a[N];


vector<pii>edge[N];//存图  这里的pii为{目的点，权值}

//s表示你要求的路径的起点
//v表示你要求的路径的终点
//u表示你当前走到了哪个点
//father表示你当前这个点的父亲节点是谁。避免重复走造成死循环
//sum表示从s走到u的路径花费总和。//权值总和
bool dfs(int s, int u, int father, int v, int sum)
{
	if(u == v)
	{
		st[{s, v}] = sum;
		st[{v, s}] = sum;
		// cout << s << " " << v << " " << sum << endl;
		return true;//返回true说明当前搜索合法，结果是正确的
	}

	for(int i = 0; i < edge[u].size(); i ++)//获取u的各个邻接点
	{
		int son = edge[u][i].first;//获取u的各个邻接点
		if(son == father)//****避免进入死循环*****
			continue;
		int w = edge[u][i].second;//获取这条边的权值
		if(dfs(s, son, u, v, sum + w))
			return true;
	}

	return false;//false说明没有找到终点，也就是本条路的终点不是你想求的
}

void solve()
{
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n - 1; i ++)
	{
		int x, y, t;//起点，终点，权值
		cin >> x >> y >> t;
		edge[x].push_back({y, t});
		edge[y].push_back({x, t});//无向图的表示方法就是存两条边
	}
    //读入完整的路线
	for(int i = 0; i < k; i ++)//例子中k=4，，路径如下：2 6 5 1
		cin >> a[i];

	//求出完整路线的总花费

	//O(k * n)
	int ans = 0;
	for(int i = 0; i < k - 1; i ++)
	{
		dfs(a[i], a[i], -1, a[i + 1], 0);//递归求解

		ans += st[{a[i] ,a[i + 1]}];
	}


	for(int i = 0; i < k; i ++)//模拟题干过程：挨个删除
	{
		int tmp = ans;
		if(i == 0)//起点
			tmp -= st[{a[i], a[i + 1]}];
		else if(i == k - 1)//终点
			tmp -= st[{a[i - 1], a[i]}];
		else
		{
			tmp -= st[{a[i - 1], a[i]}];
			tmp -= st[{a[i], a[i + 1]}];
			dfs(a[i - 1], a[i - 1], -1, a[i + 1], 0);
			tmp += st[{a[i - 1], a[i + 1]}];
		}
		cout << tmp << endl;
	}
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--)
	solve();
}
