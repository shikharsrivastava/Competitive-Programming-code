//14:50
#include<bits/stdc++.h>
using namespace std;
int nxt = 2,n,h,d;
void printedge(int id)
{
	int temp = id;
	// printf(left)
	for(int i=0;i<h;i++)
	{
		printf("%d %d\n",temp,nxt++);
		temp = nxt-1;	
	}
	temp = id;
	for(int i=0;i<d-h;i++)
	{
		printf("%d %d\n",temp,nxt++);
		temp = nxt-1;	
	}
	temp = id;
	while(nxt <= n)
		printf("%d %d\n",id,nxt++);	
	
}

int main()
{	
	scanf("%d %d %d",&n,&d,&h);
	if(d<n && h<n && h<=d && 2*h >= d)
	printedge(1);
	else
	printf("-1\n");
}
