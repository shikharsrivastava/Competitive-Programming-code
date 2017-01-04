//9:58
#include<bits/stdc++.h>
using namespace std;

#define mp(a,b) make_pair(a,b)
int main()
{

	int n,m,u,l;
	queue <pair<int ,int > > q;
	scanf("%d %d",&n,&m);
	q.push(make_pair(0,n));
	bool *vis=(bool*)calloc(2*m+1,sizeof(bool));

	while(!q.empty())
	{
		u=q.front().second;
		l=q.front().first;
		q.pop();
		if(vis[u])
		continue;
		
		vis[u]=true;
		
		if(u==m)
		{
			printf("%d\n",l);
			break;
		}
		vis[u]=true;
		if(2*u < 2*m && !vis[2*u])
		q.push(make_pair(l+1,2*u));
		if(u-1 >=0 && !vis[u-1])
		q.push(make_pair(l+1,u-1));
	}
}
