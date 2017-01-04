//11:52
#include<bits/stdc++.h>
using namespace std;
#define line false
#define vee true
struct node
{
	int no;
	vector<int> adj;
	int ans;
	bool type;
} g[10001];
vector<vector<int> > lst(10001);


void merge(int id1,int id2)
{
	//printf("Merging %d %d\n",id1,id2);
	id1=g[id1].no;
	id2=g[id2].no;
	g[id2].no = id1;
	reverse(lst[id1].begin(),lst[id1].end());
	for(int i=0;i<lst[id2].size();i++)
	{
		int j=lst[id2][i];
		//printf("pushing %d\n",j);	
		lst[id1].push_back(j);
	}
	lst[id2].clear();
}
void findans(int id,int parent)
{
	
	//printf("On %d\n",id);
	if(g[id].adj.size() == 1 && g[id].adj[0] == parent)
	{
		g[id].ans =1;
		g[id].type = line;
		return;
	}
	for(int i=0;i<g[id].adj.size();i++)
	{
		if(g[id].adj[i] != parent)
		{
			findans(g[id].adj[i],id);
			g[id].ans += g[g[id].adj[i]].ans;
		}
	}
	// Checking for line or vee connection with child
	int ans= 1,from,to;
	bool flag = false;
	for(int i=0;i<g[id].adj.size();i++)
	{
			from=g[id].adj[i];
		if(from != parent)
		{
			if(g[from].type == line)
			{	
				ans--;
				for(int j=i+1;j<g[id].adj.size();j++)
				{
					to=g[id].adj[j];
					if(to != parent)
					{
						if(g[to].type == line)
						{
							ans--;
							//printf("Merging second link\n");
							flag =true;
							merge (id,to);
							break;
						}
					}	
				}
				//printf("Merging first link\n");
				if(flag)
				merge(from,id);
				else
				merge(id,from);
				break;	
			}
		}
	}
		g[id].ans +=ans;
		if(ans <0)
		{
			//printf("%d is a vee\n",id);
			g[id].type = vee;
		}
		else
		{
			//printf("%d is a line\n",id);
			g[id].type = line;
		}
}

int main()
{
	int t,n,u,v,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);	
		for(int i=0;i<=n;i++)
		{
			g[i].adj.clear();
			lst[i].clear();
			lst[i].push_back(i);
			g[i].no = i;
			g[i].ans = 0;
			g[i].type = line;		
		}

		for(int i=0;i<n-1;i++)
		{
			scanf("%d %d",&u,&v);
			g[u].adj.push_back(v);
			g[v].adj.push_back(u);
		
		}
		findans(1,0);
		for(int i=1;i<=n;i++)
		{
			if(lst[i].size()>0)
			ans++;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		{
			if(lst[i].size() >0)
			{
				for(int j=0;j<lst[i].size()-1;j++)
				printf("%d ",lst[i][j]);
				printf("%d\n",lst[i][lst[i].size()-1]);
			}
		}	
	}
	return 0;
}
