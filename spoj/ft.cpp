//11:25
/*
	Find all SCC
	Count the number of SCC with in degree  = 0 , let it be c
	if c > 1
	it means there are >=2 SCC that cant be reached from anywhere , so they cant be reached from each other , so ans = 0
	if c == 1
	it means we have it means we form a drected tree in SCC , i.e condensation graph
	number of nodes in the the root of this tree is the answer as we can go anywhere from the root
	if c == 0
	it means no scc has formed , impossible case , ans = 0 
*/
#include<bits/stdc++.h>
using namespace std;
struct graph
{
	vector<int> in;
	vector<int> out;
} g[1001];
vector<int> lst;
int sccno[1001],cnt[1001],scc_counter;
bool vis1[1001],vis2[1001],inf[1001];
void dfs1(int id)
{
	for(int i=0;i<g[id].out.size();i++)
	{
		int to= g[id].out[i];
		if(!vis1[to])
		{
			vis1[to] = true;
			dfs1(to);
		}
	}
	lst.push_back(id);
}

void dfs2(int id)
{
	sccno[id] = scc_counter;
	cnt[scc_counter]++;
	for(int i=0;i<g[id].in.size();i++)
	{
		int to = g[id].in[i];
		if(!vis2[to])
		{
			vis2[to] = true;
			dfs2(to);
		}
	}
}
int main()
{
	int t,n,uid,m,v,scc,inc;
	scanf("%d",&t);
	while(t--)
	{
		scc_counter = scc = inc = 0;
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
		{
			vis1[i] = vis2[i] = inf[i] = false;
			g[i].in.clear();
			g[i].out.clear();
			cnt[i] = 0;
			lst.clear();
		}
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&v);
				g[v].out.push_back(i);
				g[i].in.push_back(v);
			}
		}
	
		for(int i=1;i<=n;i++)
		{
			if(!vis1[i])
			{
				vis1[i] = true;
				dfs1(i);
			}
		}
		reverse(lst.begin(),lst.end());

		for(int i=0;i<lst.size();i++)
		{

			int id = lst[i];
			if(!vis2[id])
			{
				vis2[id] = true;
				dfs2(id);
				scc++;
				scc_counter++;
			}
		}
		
		for(int i =1;i<=n;i++)
		{
			int ts = sccno[i];
			if(!inf[ts])
			{
				for(int j=0;j<g[i].in.size();j++)
				{
					int fs = sccno[g[i].in[j]];
					if(fs != ts)
					{
						inf[ts] = true;
						inc++;
						break;
					}
					if(inf[ts])
					break;
				}
			}
			if(!inf[ts])
			uid = ts;
		}
		inc = scc - inc;
		if(inc > 1 || inc == 0)
		printf("0\n");
		else
		printf("%d\n",cnt[uid]);
		
	}

}
