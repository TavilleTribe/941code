#include<stdio.h>
int n,m,x,y;
int h[100005],vis[100005];
long long ans,z;

long long max(long long x,long long y)
{
	if(x>y)
		return x;
	return y;
}

//邻接表存图
struct Edge{
	int ne,to;
	long long w;
}edge[200005];//无向边，开两倍大小

int idx;

void add(int x,int y,long long z)
{
	edge[++idx].ne=h[x];
	edge[idx].to=y;
	edge[idx].w=z;
	h[x]=idx;
}

int qd,mx;

void dfs(int x,int f,long long d)//当前房间，上一个房间，当前收集的金币
{
	vis[x]=1;//对这棵树打上标记
	if(d>mx)//找到一条路径收集的金币更多
	{
		qd=x;//换房间
		mx=d;//更新金币
	}
	for(int i=h[x];i;i=edge[i].ne)
		if(edge[i].to!=f)//不往回走
			dfs(edge[i].to,x,d+edge[i].w);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
	scanf("%d %d %lld",&x,&y,&z);
	add(x,y,z);
	add(y,x,z);
	}
	for(int i=1;i<=n;i++)
	{
	if(!vis[i])//还没遍历过这棵树
		{
		mx=0;
		qd=i;//先假设 i 为一端
		dfs(qd,0,0);
		//跑完第一个 dfs 后，qd 会变为直径的一端
		dfs(qd,0,0);
		ans=max(ans,mx);
		}
	}
	printf("%lld",ans);
	return 0;
}
