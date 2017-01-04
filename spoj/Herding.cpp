
//8:32
#include<bits/stdc++.h>
using namespace std;
char s[1001][1001];
int ans=0,n,m;
int vis[1001][1001];

void dfs(int i,int j,int pno)
{
	if(vis[i][j] == 0)
		vis[i][j]=pno;

	else if(vis[i][j] == pno)
	{
		ans++;
		return;
	}
	else if(vis[i][j] != pno)
	return; 
	
	if(s[i][j] == 'W' && j-1>=0)
	dfs(i,j-1,pno);
	if(s[i][j] == 'N' && i-1 >=0)
	dfs(i-1,j,pno);
	if(s[i][j] == 'S' && i+1 <n)
	dfs(i+1,j,pno);
	if(s[i][j] == 'E' && j+1<m)
	dfs(i,j+1,pno);
	
}

int main()
{
	int pno=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			dfs(i,j,++pno);
	}
	printf("%d\n",ans);
}
