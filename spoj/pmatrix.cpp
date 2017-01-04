//23:32
#include<bits/stdc++.h>
using namespace std;

struct graph
{
	vector<int> in;
	vector<int> out;
} g[20001];
int tr,sccno;
bool vis1[20001],vis2[20001],inc[20001],outc[20001];
int setno[20001];

struct otime
{
	int out;
	int id;
} tout[20001];

void dfs1(int id)
{
	for(int i=0;i<g[id].out.size();i++)
	{
		int to = g[id].out[i];
		if(!vis1[to])
		{
			vis1[to] = true;
			dfs1(to);
		}
	}
	
	tout[id].id = id;
	tout[id].out = ++tr;
}


void dfs2(int id,int p)
{
	setno[id] = sccno;
	for(int i=0;i<g[id].in.size();i++)
	{
		int to = g[id].in[i];
		if(!vis2[to])
		{
			vis2[to] = true;
			dfs2(to,id);
		}
	}
}


bool so(const otime &a, const otime &b)
{
	return a.out > b.out;
}

int scanint()
{
	register int num = 0;
	register char c;
	c = getchar_unlocked();
	while(c >= '0' && c<= '9')
	{
		num = num *10 + c -'0';	
		c=getchar_unlocked();
	}
	return num;
}

int main()
{
	int t,n,m,u,v,ans,in,ot,scc;
	t = scanint();
	while(t--)
	{
		/*Finding strongly connected components*/
		tr = ot = in = scc = sccno = 0;
		n = scanint();
		m = scanint();
		for(int i=0;i<=n;i++)
		{
			g[i].in.clear();
			g[i].out.clear();
			vis1[i] = vis2[i] = inc[i] = outc[i] = false;
		}
	
		for(int i=1;i<=m;i++)
		{
			u = scanint();
			v = scanint();
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
		sort(tout+1,tout+n+1,so);

		for(int i=1;i<=n;i++)
		{
			int id = tout[i].id;
			if(!vis2[id])
			{
				vis2[id] = true;
				dfs2(id,id);
				scc++;
				sccno++;
			}
		}
		/*Found all strongly connected component*/
		/*Vertices of a SCC have the same setno (SCCno), i.e for all u belong to component Ci setno[u] are same*/
		
		if(scc == 1)
		{
			//Edge Cases
			printf("0\n");
			continue;
		}
		/*Finding the in degree and out degree of all SCC*/
		/*in  = number of SCC with in degree > = 1*/
		/*out = number of SCC with out degree >= 1*/
		for(int u=1;u<=n;u++)
		{
			/*fs is the sccno of SCC containing u*/
			int fs = setno[u];
			/*outc[Ci] = true means SCC Ci has out degree >= 1*/
			if(!outc[fs])
			{
				for(int j=0;j<g[u].out.size();j++)
				{
					/*ts is the sccno of SCC containing g[u].out[j]*/
					int ts = setno[g[u].out[j]];
					if(fs != ts)
					{
						outc[fs] = true;
						ot++;
						break;
					}
					if(outc[fs])
					break;
				}
			}
			/*inc[Ci] = true means SCC Ci has in degree >= 1*/
			if(!inc[fs])
			{
				for(int j=0;j<g[u].in.size();j++)
				{
					/*ts is the sccno of SCC containing g[u].out[j]*/
					int ts = setno[g[u].in[j]];
					if(fs != ts)
					{
						inc[fs] = true;
						in++;
						break;
					}
					if(inc[fs])
					break;
				}
			}
		}
		/*scc - in  = number of SCC with in degree = 0*/
		/*scc - out = number of SCC with out degree = 0*/
		ans = max(scc-in,scc-ot);
		printf("%d\n",ans);
	}
}
