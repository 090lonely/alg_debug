#include<bits/stdc++.h>
using namespace std;
const int N = 2010;
typedef pair<int, int> PII;//我想到了哈哈哈
int w[N], f[N];//w记录种植时间，f记录获得该种子所用的最短时间
bool have[N];//i号种子是否已经获得//******

vector<PII> fa[N];//一个种子可能有多种杂交方案

int dfs(int t)
{
    for(int i = 0; i < fa[t].size(); i++)//遍历所有杂交方案
    {
        int a = fa[t][i].first, b = fa[t][i].second;
        if(!have[a]) dfs(a);
        if(!have[b]) dfs(b);
        if(have[a] && have[b]) 
        {
            have[t] = true;
            f[t] = min(f[t], max(w[a], w[b]) + max(f[a], f[b]));//当有多种杂交方案时，我们会及时更新
        }//此处不需要回溯因为该种子获取之后并不需要置0，只需要更新最短时间即可
    }
    return f[t];
}
int main()
{
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    memset(f, 0x3f3f, sizeof f);//初始化所有最短时间为无限大
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        have[temp] = true;//***我自己的demo没有这项纪录***
        f[temp] = 0;
    }
    for(int i = 1; i <= k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        fa[c].push_back({a, b}); 
    }
    cout << dfs(t);
    return 0;
}