//23:17
#include<bits/stdc++.h>
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
	int n;
	scanf("%d",&n);
	st=(node*)calloc(n+1,sizeof(node));
	
}
