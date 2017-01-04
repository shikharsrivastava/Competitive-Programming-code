//20:47

#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define VALID(a,b) (a<64 && a>=0 && b<64 && b>=0)
#define isValid(a,b,c)  (VALID(a,b) && abs((a/8) - (b/8)) == level[c])

int main()
{

	int from,to;
	char inp[3];
	scanf("%s",inp);
	from=(inp[1]-'1')*8+(inp[0]-'a');
	scanf("%s",inp);
	to=(inp[1]-'1')*8+(inp[0]-'a');
	if(from == to)
	printf("0\n");
	else
	{
	priority_queue<pair<int,int> > q;
	
	int d[64],p[64];
	bool visited[64];
	for(int i=0;i<63;i++)
	{d[i]=1000000;p[i]=0;visited[i]=false;}

	d[to]=0;	
	q.push(mp(0,to));
	int inc[8]={1,8,9,7,-1,-8,-9,-7};
	int level[8]={0,1,1,1,0,1,1,1};	

	while(! q.empty())
	{
		int sq=q.top().second;
		q.pop();
		if(visited[sq])
		continue;
		visited[sq]=true;
		for(int i=0;i<8;i++)
		{
			int v=sq+inc[i];
			if(isValid(sq,v,i))
			{
				if(d[sq]+1 < d[v])
				{
					d[v]=d[sq]+1;
					p[v]=sq;
					q.push(mp(-d[v],v));
				}
			}
		}
	}

	int c=0;
	int fr=from;
	
	while(1)
	{
		c++;
		if(p[fr] == to)
		break;
		fr=p[fr];
	}
	
	printf("%d\n",c);
	while(1)
	{
		c++;
		if(p[from] - from == 1)
		printf("R\n");
		else if(p[from] - from == -1)
		printf("L\n");
		else if(p[from] - from == 8)
		printf("U\n");
		else if(p[from] - from == -8)
		printf("D\n");
		else if(p[from] - from == 9)
		printf("RU\n");
		else if(p[from] - from == -9)
		printf("LD\n");
		else if(p[from] - from == 7)
		printf("LU\n");
		else
		printf("RD\n");
		if(p[from] == to)
		break;
		from=p[from];
	}
	}

}
