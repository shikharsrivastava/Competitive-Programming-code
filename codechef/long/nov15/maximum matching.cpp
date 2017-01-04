#include<cstdio>
#include<cstdlib>
#define M(a,b) a<b?a:b
int **capacity,**flow,*visited,n;

/*For fulkersen algorithm for finding maximum flow
* s-> current vertex
* t -> sink vertex
* min-> current minimum in partial augmented path
*/

int ford(int s,int t,int min)
{

	if(visited[s]==0) // Prevents loop
	visited[s]=1;
	else
	return -1;	
	if(s==t) // Reached the sink
	return min;
	
	int newmin=min;  // newmin stores the minimum including the current path
	int newmin2;  // newmin2 stores the minimum in the entire path
	for(int i=0;i<=2*n+1;i++)
	{
	if(capacity[s][i]>flow[s][i])	// If there is a path in the residual graph
	{
	newmin2=M(min,capacity[s][i]-flow[s][i]);
	newmin=ford(i,t,newmin2); 	// travelling the augmented path in the residual graph
	if(newmin==-1) 		// If we cant reach the sink through this path
	continue;
	flow[s][i]+=newmin;	// Else increasing flow by (flow (up arrow) flow) i.e increasig the flow in this edge after travelling the augmented path
	return newmin;
	}
	else
	{
	if(flow[i][s]==0)	// If we cannot go from vertex i to s
	continue;
	
	newmin2=M(min,flow[i][s]);
	newmin=ford(i,t,newmin2);
	if(newmin==-1)
	continue;
	flow[i][s]-=newmin; // Travelling the opposite path so decreasing the flow
	return newmin;
	}
	
	}
	return -1;	// If no path exists return -1

}

int main()
{
int t,m,u,v,ans;
scanf("%d",&t);
while(t--)
{
scanf("%d %d",&n,&m);

capacity=(int**)calloc(2*n+3,sizeof(int*));
flow=(int**)calloc(2*n+3,sizeof(int*));
visited=(int*)calloc(2*n+3,sizeof(int));
for(int i=0;i<=2*n+2;i++)
{
capacity[i]=(int*)calloc(2*n+3,sizeof(int));
flow[i]=(int*)calloc(2*n+3,sizeof(int));
}
for(int i=1;i<=m;i++)
{
scanf("%d %d",&u,&v);
capacity[u][n+v]=1;
}

for(int i=1;i<=n;i++)
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
printf("%d\n",n-ans);	// Konigs Theorem


}
return 0;
}
