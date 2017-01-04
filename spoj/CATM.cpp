//10:45
#include<bits/stdc++.h>
using namepsace std;
#define mp(a,b) make_pair(a,b)
bool bfsm(int **mouse,boo ** vism,int n,int m,int r,int c)
{
	queue<pair<int,int> >q;
	q.push(mp(r,c));
	while(!q.empty())
	{
		r=q.front().first;
		c=q.front().second;
		q.pop();
		if(vism[r][c])
		continue;
		else
		vism[r][c]=true;
		
		if(r+1 <)
	}
}
bool bfsc(int **cat ,int **mouse,int n,int m,int r,int c)
{
}


int main()
{
	int n,m,mx,my,c1x,c1y,c2x,c2y;
	scanf("%d %d",&n,&m);
	int **mouse=(int**)calloc(n+1,sizeof(int*));
	int **cat1=(int**)calloc(n+1,sizeof(int*));
	int **cat2=(int**)calloc(n+1,sizeof(int*));
	bool **vism=(bool**)calloc(n+1,sizeof(bool*));
	bool **visc1=(bool**)calloc(n+1,sizeof(bool*));
 	bool **visc1=(bool**)calloc(n+1,sizeof(bool*));

	for(int i=0;i<=n;i++)
	{
		mouse[i]=(int*)calloc(m+1,sizeof(int));
		cat1[i]=(int*)calloc(m+1,sizeof(int));
		cat2[i]=(int*)calloc(m+1,sizeof(int));
		vism[i]=(bool*)calloc(m+1,sizeof(bool));
		visc1[i]=(bool*)calloc(m+1,sizeof(bool));
		visc2[i]=(bool*)calloc(m+1,sizeof(bool));

	}
	int k;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %d %d %d %d %d",&mx,&my,&c1x,&c1y,&c2x,&c2y);
		bfsm(mouse,n,m);
		
	}
}
