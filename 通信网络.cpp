
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
const int N=1000+10;
vector<int> g[N],g0[N];
bool vis[N],vis0[N];
int n,m;
int main()
{
	int a,b,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g0[b].push_back(a);
	}
	for(int k=1;k<=n;k++)
	{
	memset(vis,false,sizeof(vis));
	memset(vis0,false,sizeof(vis0));
	queue<int> q;
	q.push(k);
	vis[k]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		int l=g[u].size();
		for(int i=0;i<l;i++)
		{
			if(!vis[g[u][i]])
			{
				vis[g[u][i]]=true;
				q.push(g[u][i]);
			}
		}
	}
	q.push(k);
	vis0[k]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		int l=g0[u].size();
		for(int i=0;i<l;i++)
		{
			if(!vis0[g0[u][i]])
			{
				vis0[g0[u][i]]=true;
				q.push(g0[u][i]);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	if(vis[i]||vis0[i]) cnt++;
	if(cnt==n) ans++;
	}
	printf("%d\n",ans);
	return 0;
}

// 详解 : https://blog.csdn.net/wl16wzl/article/details/79265465