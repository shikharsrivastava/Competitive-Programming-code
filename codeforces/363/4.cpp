
#include<bits/stdc++.h>

#define INF 1000000000
#define mp make_pair()
#define pb push_back
#define gym 0
#define code 1

using namespace std;

struct node
{
	int parent;
	int rank;

} *st;
int findset(int x)
{
	if(st[x].parent == x)
	return x;
	st[x].parent = findset(st[x].parent);
 	return st[x].parent;
}

void makeset(int x)
{
	st[x].parent = x;
	st[x].rank =0;
}

void un(int x ,int y)
{
	x=findset(x);
	y=findset(y);
	if(x  == y)
	return;
	if(st[x].rank < st[y].rank)
	swap(x,y);
	st[y].parent = x;
	if(st[y].rank == st[x].rank)
	st[x].rank++;
	return;
}
int main()
{
	set<int> ch;
	int n;
	scanf("%d",&n);
	int p[n+1];
	for(int i=1;i<=n;i++)
	scanf("%d",&p[i]);
	
	int ans[n+10];
	for(int i=1;i<=n;i++)
	ans[i] = p[i];

	st = (node*)calloc(n+10,sizeof(node));
	for(int i=1;i<=n;i++)
	makeset(i);
	
	for(int i=1;i<=n;i++)
	{
		if(findset(i) != findset(p[i]))
		un(i,p[i]);
		else
		{
			
		}
	}
	
}
