#include<bits/stdc++.h>
using namespace std;

int g[1000000];
int intime[1000000];
int chain[1000000];
int timer= 0 , counter = 0 , ans = 0;
int dfs(int id)
{
	intime[id] = ++timer;
	chain[id] = counter;
	int sm = 1000000000;
	if(intime[g[id]] == 0)
	sm = dfs(g[id]);
	else if(intime[g[id]] <= intime[id] && chain[g[id]] == counter)
	sm = intime[g[id]];
	if(sm <= intime[id])
	ans++;
	return sm;
	
}
int main()
{
	int t,n,a;
	scanf("%d",&t);
	while(t--)
	{
		counter = timer = ans = 0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{scanf("%d",&a);g[i] = (i+a+1)%n;intime[i] = 0;chain[i] = 0;}
		
		for(int i=0;i<n;i++)
		{
			if(intime[i] == 0)
			{
				counter++;
				dfs(i);
			}
		}
		printf("%d\n",ans);
	}
}
