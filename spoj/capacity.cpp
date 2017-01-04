//11:25
/*
	Take the transpose of the graph first
	a -> b is now b ->a
	in transpose graph b -> a means a is an answer for b

	Find all SCC in the transpose graph
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
} g[100001];
vector<int> lst;
int sccno[100001],cnt[100001],scc_counter;
bool vis1[100001],vis2[100001],inf[100001];
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
	int n,uid,m,u,v,scc,inc;
	
		scc_counter = scc = inc = 0;
		scanf("%d %d",&n,&m);
		for(int i=0;i<=n;i++)
		{
			vis1[i] = vis2[i] = inf[i] = false;
			g[i].in.clear();
			g[i].out.clear();
			cnt[i] = 0;
			lst.clear();
		}
		
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d",&v,&u);
			// taking graph input as transpose
			g[u].out.push_back(v);
			g[v].in.push_back(u);
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
		// inc = number of nodes in condensation graph with in degree >=1
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
		// now inc = number of nodes in condensation graph with in degree = 0;
		inc = scc - inc;
		if(inc > 1 || inc == 0)
		printf("0\n");
		else
		{
			printf("%d\n",cnt[uid]);
			for(int i=1;i<=n;i++)
			{
				if(sccno[i] == uid)
				printf("%d ",i);
			}
			printf("\n");
		}	
	return 0;

}
