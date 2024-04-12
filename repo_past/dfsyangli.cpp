#include<iostream>
using namespace std;
const int N=10;
int ans[N];
bool mark[N];
int n;
void dfs(int u)
{
    //"回头"的条件
    if(u==n)
    {
        for(int i=0;i<n;i++)cout<<ans[i]<<" ";
        cout<<endl;
        return;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(mark[i]==false)
        {
            mark[i]=true;
            ans[u]=i;
            dfs(u+1);
            //复原
            mark[i]=false;
            ans[u]=0;
        }
    }
}

int main()
{
    cin>>n;//注意这里有输入的，别在那里愣着，笨蛋
    dfs(0);
    return 0;
}
