//12:17
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
int main()
{
	int r,c,nr,br,bc,nb,sc,sr,dc,dr;
	int **a,**d;
	queue<pii >q;
	scanf("%d %d",&r,&c);
	while(r+c>0)
	{
	a=(int**)calloc(r+1,sizeof(int*));
	d=(int**)calloc(r+1,sizeof(int*));
	for(int i=0;i<=r;i++)
	{
		a[i]=(int*)calloc(c+1,sizeof(int));
		d[i]=(int*)calloc(c+1,sizeof(int));
	}

	scanf("%d",&nr);
	while(nr--)
	{
		scanf("%d",&br);
		scanf("%d",&nb);
		while(nb--)
		{
			scanf("%d",&bc);
			a[br][bc]=1;
		}
	}
	
	scanf("%d %d",&sr,&sc);
	scanf("%d %d",&dr,&dc);
	
	

	q.push(mp(sr,sc));
	while(!q.empty())
	{
		int row=q.front().first;
		int col=q.front().second;
		q.pop();
	
		//printf("On %d %d\n",row,col);
		if(col+1 <c && a[row][col+1] ==0 && d[row][col+1] ==0)
		{
			d[row][col+1] =d[row][col]+1;
			q.push(mp(row,col+1));
		}
		if(col-1 >=0 && a[row][col-1] ==0 && d[row][col-1] ==0)
		{
			d[row][col-1] =d[row][col]+1;
			q.push(mp(row,col-1));
		}
		if(row+1 <r && a[row+1][col] ==0 && d[row+1][col] ==0)
		{
			d[row+1][col] =d[row][col]+1;
			q.push(mp(row+1,col));
		}
		if(row-1 >=0 && a[row-1][col] ==0 && d[row-1][col] ==0)
		{
			d[row-1][col] =d[row][col]+1;
			q.push(mp(row-1,col));
		}
	}
	//printf("Going to %d %d\n",dr,dc);
	printf("%d\n",d[dr][dc]);
	for(int i=0;i<=r;i++)
	{
		free(a[i]);
		free(d[i]);
	}
	free(a);
	free(d);
	scanf("%d %d",&r,&c);
	}
}
