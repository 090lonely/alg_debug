#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=110;
typedef pair<int,int> PII;//存储坐标注意pair的使用：p.first,p.second
int map[N][N],mark[N][N];//map记录地图和mark元素是否已经经过
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},n,m,ans;//方向向量
void bfs()
{
    memset(mark,-1,sizeof mark);//初始化为-1
    queue<PII>q;//队列中的每一个元素都是一个pair
    q.push({0,0});
    mark[0][0]=0;//起点入队列
    while(!q.empty())
    {
        PII top=q.front();
        for(int i=0;i<4;i++)//以队列首元素向四个方向展开搜索
        {
            int nex=top.first+dx[i],ney=top.second+dy[i];//
            if(nex>=0&&nex<n&&ney>=0&&ney<m&&mark[nex][ney]==-1&&map[nex][ney]==0)
            {
                mark[nex][ney]=mark[top.first][top.second]+1;//记录最短路径
                q.push({nex,ney});
            }
        }
        q.pop();//完成搜索之后，即可出队列
    }
    cout<<mark[n-1][m-1];//该点记录的是到达此点的最短路径长度
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    bfs();
}
//5 5
//0 1 0 0 0
//0 1 0 1 0
//0 0 0 0 0 
//0 1 1 1 0
//0 0 0 1 0