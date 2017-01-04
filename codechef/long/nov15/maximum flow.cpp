#include<cstdio>
#include<cstdlib>
#define M(a,b) a<b?a:b

int **flow,**capacity,n,*visited;
int path_found(int s,int t,int min)
{	
	if(visited[s]==0)
	visited[s]=1;
	else
	return -1;
	if(s==t)
	return min;

	int newmin=min;
	int newmin2;
	for(int i=1;i<=n;i++)
	{
	
	if(capacity[s][i] > flow[s][i])
	{
	newmin2=M(min,capacity[s][i]-flow[s][i]);
	newmin=path_found(i,t,newmin2);
	if(newmin==-1)
	continue;
	flow[s][i]+=newmin;
	return newmin;
	}
	else
	{
	if(flow[i][s]==0)
	continue;
	newmin2=M(min,flow[i][s]);
	newmin=path_found(i,t,newmin2);
	if(newmin==-1)
	continue;
	flow[i][s]-=newmin;
	return newmin;
	}
	}
	return -1;
	

}

int main()
{
int t,e,u,v,c,ans;
scanf("%d",&t);
while(t--)
{
scanf("%d %d",&n,&e);
flow=(int**)calloc(n+1,sizeof(int*));
capacity=(int**)calloc(n+1,sizeof(int*));
visited=(int*)calloc(n+1,sizeof(int));
for(int i=0;i<=n;i++)
{
flow[i]=(int*)calloc(n+1,sizeof(int));
capacity[i]=(int*)calloc(n+1,sizeof(int));
}
for(int i=1;i<=e;i++)
{
scanf("%d %d %d",&u,&v,&c);
capacity[u][v]=c;
}

while(path_found(1,n,10000) != -1)
{
free(visited);
visited=(int*)calloc(n+1,sizeof(int));
}
ans = 0;
for(int i=1;i<=n;i++)
ans+=flow[1][i];

printf("answer = %d\n",ans);

}

}
