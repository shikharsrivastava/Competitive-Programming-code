#include<cstdio>
#include<cstdlib>
#define M(a,b) a<b?a:b
int **capacity,**flow,*visited,n;


int ford(int s,int t,int min)
{
	if(visited[s]==0)
	visited[s]=1;
	else
	return -1;	
	if(s==t)
	return min;
	
	int newmin=min;
	int newmin2;
	for(int i=0;i<=2*n+1;i++)
	{
	if(capacity[s][i]>flow[s][i])
	{
	newmin2=M(min,capacity[s][i]-flow[s][i]);
	newmin=ford(i,t,newmin2);
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
	newmin=ford(i,t,newmin2);
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
int t,m,u,v,ans;
sacnf("%d",&t);
while(t--)
{
scanf("%d %d",&n,&m);

capacity=(int**)calloc(2*n+3,sizeof(int*));
flow=(int**)calloc(2*n+3,sizeof(int*));
visited=(int*)calloc(2*n+3,sizeof(int));
for(int i=1;i<=n;i++)
{
capacity[i]=(int*)calloc(2*n+3,sizeof(int));
flow[i]=(int*)calloc(2*n+3,sizeof(int));
}
for(int i=1;i<=m;i++)
{
scanf("%d %d",&u,&v);
capacity[u][n+v]=1;
}

for(i=1;i<=n;i++)
{
capacity[0][i]=1;
capacity[i+n][2*n+1]=1;
}

while(ford(0,2*n+1,3) != -1)
{
free(visited);
visited=(int*)calloc(2*n+3,sizeof(int));
}
ans=0;
for(int i=1;i<=n;i++)
ans+=flow[0][i];

if(ans==n)
printf("1\n");
else
printf("%d\n",n-ans);





}
}
