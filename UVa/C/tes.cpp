
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=4100;
const int inf=1e9;
struct HeapNode
{
	int d,u;
	bool operator<(const HeapNode& rhs)const
	{
		return d>rhs.d;
	}
};
struct Edge
{
	int from,to,dist,id;
};
struct Dijkstra 
{
	int n,m;
	vector<Edge>edges;
	vector<int>G[maxn];
	bool done[maxn];
	int d[maxn],p[maxn]; 
	
	void init(int n)
	{
		this->n=n;
		for(int i=0;i<n;i++)G[i].clear();
		edges.clear();
	}
	void AddEdge(int from,int to,int dist,int id)
	{
		edges.push_back((Edge){from,to,dist,id});
		m=edges.size();
		G[from].push_back(m-1);
	}
	void dij(int s)
	{
		priority_queue<HeapNode>Q;
		for(int i=1;i<=n;i++)d[i]=inf;
		d[s]=0;
		memset(done,0,sizeof(done));
		Q.push((HeapNode){0,s});
		while(!Q.empty())
		{
			HeapNode x=Q.top();Q.pop();
			int u=x.u;
			if(done[u])continue;
			done[u]=true;
			for(int i=0;i<G[u].size();i++)
			{
				Edge& e=edges[G[u][i]];
				if(d[e.to]>d[u]+e.dist)
				{
					d[e.to]=d[u]+e.dist;
					p[e.to]=G[u][i];
					Q.push((HeapNode){d[e.to],e.to});
				}
			}
		}
	}
	void print(int s,int t)
	{
		stack<int>stk;
		while(t!=s)
		{
			stk.push(edges[p[t]].id);
			t=edges[p[t]].from;
		}
		while(!stk.empty())
		{
			printf(" %d",stk.top());
			stk.pop();
		}
		printf("\n");
	}
}solver;
int id[12][410],res;		
vector<int>ticket[21];
map<int,int>mp;
int ID(int a,int b)
{
	if(id[a][b]==0)
	id[a][b]=++res;
	return id[a][b];
}
int main()
{
	int n,m,q,u,v,money,kase=0;
	while(~scanf("%d",&n)&&n)
	{
		int tot=0;
		int cost[21];
		mp.clear();
		for(int i=1;i<=n;i++)
		{
			ticket[i].clear(); 
			scanf("%d%d",&cost[i],&m);
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&u);
				if(!mp[u])mp[u]=++tot;
				ticket[i].push_back(mp[u]);
			}
		}
		kase++;
		scanf("%d",&q);
		vector<int>line;
		for(int p=1;p<=q;p++)
		{
			int num;
			line.clear();
			memset(id,0,sizeof(id));
			res=0;
			scanf("%d",&num);
			for(int i=1;i<=num;i++)
			{
				scanf("%d",&u);
				line.push_back(mp[u]);
			}
			solver.init(num*tot+1);
			for(int tic=1;tic<=n;tic++)
			for(int pos=1;pos<num;pos++)
			{
				int next=pos;
				for(int i=1;i<ticket[tic].size();i++)
				{
					if(ticket[tic][i]==line[next])next++;
					solver.AddEdge(ID(pos,ticket[tic][0]),ID(next,ticket[tic][i]),cost[tic],tic);
					if(next==num)
					break;
				}
			}
			solver.dij(ID(1,line[0]));
			int ans=solver.d[ID(num,line[num-1])];
			printf("Case %d, Trip %d: Cost = %d\n",kase,p,ans);
			printf("  Tickets used:");
			solver.print(ID(1,line[0]),ID(num,line[num-1]));
		}
	}
}