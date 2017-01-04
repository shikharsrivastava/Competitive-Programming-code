//11:30
#include<bits/stdc++.h>
using namespace std;

vector<vector <int > > g(100001);
int *vc;
int vCover(int id)
{
	if(vc[id] == -1)
	{
		//Including the root
		int incl=1,nincl=0;
		for(int i=0;i<g[id].size();i++)
		incl+=vCover(g[id][i]);
		
		//Not including
		for(int i=0;i<g[id].size();i++)
		{
			nincl+=1;
			int v=g[id][i];
			for(int j=0;j<g[v].size();j++)
			nincl+=vCover(g[v][j]);
		}
		vc[id]=min(incl,nincl);
	}
	return vc[id];
}
int main()
{
	int n,u,v;
	scanf("%d",&n);

		vc=(int*)calloc(n+1,sizeof(int));
		for(int i=0;i<=n;i++)
		vc[i]=-1;
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
		}
	
		printf("%d\n",vCover(1));

}
