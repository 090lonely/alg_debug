# 蓝桥杯基础知识和算法总结
## 大名鼎鼎的STL  查看文章"【C++】蓝桥杯必备 算法竞赛常用STL万字总结"
写几个非常重要的函数：sort(a.begin(),a.end()),reverse(a.begin(),a.end());
## 搜索--bfs
1.青蛙跳杯子2.迷宫问题
<!-- void bfs(int u) {
queue<int> q;
q.push(u);
while (!q.empty()) {
u = q.front();
q.pop();
for (int v: e[u]) {
q.push(v);
}
}
} -->
## 搜索--dfs
void dfs(int u) {
if (vis[u]) {
return;
}
vis[u] = true;
for (int v: e[u]) {
dfs(v);
}
}
## dp
## 简单数学和数论
gcd
<!-- int gcd_my(int a,int b){//最大公约数
  while(a!=b){
    if(a>b)a-=b;
    else b-=a;
    //更相减损术
  }
  return a;
  } -->
lcm
<!-- int main()
{
    int a, b;
    while(cin >> a >> b)//最小公倍数
    {
        //最小公倍数 = 两数之积除以最大公约数
        cout << a * b / gcb_my(a, b) << endl;
    }
    return 0;
} -->
*质因子分解*
### 快速幂
<!-- long long pow(long long a, long long b, long long mod) {//求a的b次幂再对mod取模
long long res = 1;
while (b) {
if (b & 1) {//如果 b 的最低位是 1（通过 b 与 1 进行位与操作判断）
res = res * a % mod;
}
a = a * a % mod;
b >>= 1;//将 b 右移一位，相当于将 b 除以 2。
}
return res;
} -->//时间复杂度是 O(logb)
### 逆元

<!-- long long inv(long long a, long long mod) {
return pow(a, mod - 2, mod);
} -->
## 简单字符串处理
string s;s.size();s.find();s.concat(yangjinbo);//连接
## 简单图论
单源最短路径
### 迪杰斯特拉，bellman-ford
### 最小生成树：kruskal，prim
## 基本算法
### 双指针
1.盛水最多的容器
### 二分
<!-- bool check(int x) {
}
int find(int l, int r) {
while (l + 1 < r) {
int mid = (l + r) / 2;
if (check(mid)) {
l = mid;
} else {
r = mid;
}
}
return l;
} -->
### 差分
### 贪心
### 排序
sort(a.begin(),a.end(),cmp);
## 基本数据结构
### 栈stack，队列queue，链表list，二叉树，优先级队列（堆），并查集，集合
1. 栈；s.push(),s.pop();
2. 优先级队列：（1）默认大根堆
（2）修改为小根堆：  priority_queue<string,vector<string>,greater<string>>;
（3）两者区别：
队列：
q.front();// 返回队头元素
q.back(); //返回队尾元素
优先队列：
q.top();// 返回堆顶元素
3.双向队列deque
4.并查集
（1）int fa[100010]; // fa[i]表示i的父亲
（2）int find(int x){
	// 如果i的父亲是他自己，那么返回自己
	if(x==fa[x]) return x;
	// 如果不是的话
	else{
	// 找到他的父亲
	// 并且令他的父亲为他父亲的父亲
	// 即路径压缩
	fa[x]=find(fa[x]);
	// 返回他的父亲
	return fa[x];
}
（3）void unity(int x,int y){
	// 将y的父亲指向x的父亲，即合并xy
	// 这里x和y可以互换位置，不影响最终结果
	fa[find(y)]=find(x);
}
（4）例题：洛谷P3367
### STL
1.set容器自动排好序s。insert（）；
2.string.substr()***求子字符串十分有用！！！！！！ ***  push_back() 和insert();

## 骗分技巧
1.填空题  直接输入答案，编程过程不必要，也不一定要体现在提交的code里
2.程序设计题 对于不会的题，要求输入“YES”“NO”的可以直接输出骗分，没有结果的输出-1也可以混分哈哈哈
3.自己编写测试用例，以便程序设计题在本地检查运行是否成功
# 心得    2024.4.8（一堆期中与比赛的ddl快要砸死我了）
在准备蓝桥杯的过程中，我也发现了自己的问题和优点。
首先，准备不够充分。其实这些比赛不能临近比赛才去准备，那时候往往来不及，你还有其他事情。一定要早做准备，比如寒暑假，这就是最好的时间，可以不用着急的去认真学习每一个知识点，扎实巩固自己的能力。
其次，*计划*不够明确，导致心里头总是很乱，你既然有电脑，为什么不做一个完备的计划呢？后面去补充改进就行了。
然后，能学得下去，但是在计算机的赛道上面，卷成为了必然，你要多努力学习知识，丰富自己的见识！
最后也是最重要的，认清自己现阶段什么最重要，也就是权衡利弊，要找出自己现阶段的*最优解*。
### 学习记录
我很懒，我也不想要再这么忙的情况下学这么累，之后还有机会。
2024.4.11 看视频加入advice。txt，然后计蒜客视频stl部分看完，学会了map，set，priority_queue的使用
2024.4.12 已经打算放弃了，事情太多了，在力扣上还看到一个1200道题的研究生大佬我靠，针灸离谱了，暑假也要刷题了 
但是现在，我是则很难的没有时间