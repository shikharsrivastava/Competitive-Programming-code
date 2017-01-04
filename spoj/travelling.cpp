//14:14
#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define MX 1000000000000000000
#define current  0
#define next 1
#define MOD 1000000003
typedef long long int lli;
int **dp,**a,**b,*lp,*pn,*idx,n,m;
vector<vector<int> > adj(10000);
struct node
{
	lli min1;
	lli min2;
} *table;

void reset()
{
	for(int i=0;i<=10000;i++)
	table[i].min1 = table[i].min2 = MX;
}
int main()
{
	int s,p,q,r,w,x,y,z;
	scanf("%d %d",&n,&m);
	scanf("%d %d %d %d",&s,&p,&q,&r);
	scanf("%d %d %d %d",&w,&x,&y,&z);
	if(n == 1)
	{
		printf("0\n");
		return 0;
	}
	table = (node*)calloc(10001,sizeof(node));
	lp = (int*)calloc(m+1,sizeof(int));
	idx=(int*)calloc(100001,sizeof(int));
	int **a =(int**)calloc(n+1,sizeof(int*));
	int **b =(int**)calloc(n+1,sizeof(int*));
	lli **cost = (lli**)calloc(2,sizeof(lli*));
		cost[0] = (lli*)calloc(m+1,sizeof(lli));
		cost[1] = (lli*)calloc(m+1,sizeof(lli));
	
	for(int i=0;i<=n;i++)
	{
		a[i] = (int*)calloc(m+1,sizeof(int));
		b[i] = (int*)calloc(m+1,sizeof(int));
	}
	for(int i=0;i<n*m;i++)
	{
		s = (((((lli)p*s)%MOD)*s)%MOD + ((lli)q*s)%MOD + r)%MOD;
		a[(i/m)+1][(i%m)+1] = s;
		w = (((((lli)x*w)%MOD)*w)%MOD + ((lli)y*w)%MOD + z)%MOD;
		b[(i/m)+1][(i%m)+1] = w;
	}
	
	
	int cnt =0;
	lp[1] = 1;
	for(int i=2;i<=m;i++)
	{
		if(lp[i]>0)
		continue;
		lp[i] = i;
		cnt++;
		adj[cnt].push_back(1);
		adj[cnt].push_back(i);
		
		int mul = i;
		while((lli)mul*i <= (lli)m)
		{
			if(lp[mul*i] == 0)
			{
				lp[mul*i] = i;
				adj[cnt].push_back(mul*i);			
			}
			mul++;
		}
	}
	
	for(int i=1;i<=cnt;i++)
		for(int j=0;j<adj[i].size();j++)
				idx[adj[i][j]] = i;
			


	for(int i=0;i<=10001;i++)
	table[i].min1 = table[i].min2 = 0;
	
	
	for(int city=n-1;city>0;city--)
	{
	
		for(int i=0;i<=m;i++)
		{
			cost[next][i] = cost[current][i];
			cost[current][i] = 0;		
		}
		
		cost[current][1] = cost[next][1] + a[city][1];

		for(int place=2;place<=m;place++)
		{
			lli ans = MX;
			ans = min(ans,cost[next][place]+a[city][place]);
			int index = idx[place];
			if(table[index].min1 == cost[next][place])
			ans = min(ans,table[index].min2 + b[city][place]);
			else
			ans = min(ans,table[index].min1 + b[city][place]);
			cost[current][place] = ans;
		}
				
		reset();
		for(int i=1;i<=cnt;i++)
		{
			for(int j=0;j<adj[i].size();j++)
			{
				int place = adj[i][j];
				if(cost[current][place] <=  table[i].min1)
				table[i].min2 = table[i].min1 , table[i].min1 = cost[current][place];
				else if(cost[current][place] <= table[i].min2)
				table[i].min2 = cost[current][place];
			}
		}
	}
	long long int fans = MX;
	for(int i=1;i<=m;i++)
	fans = min(fans,cost[current][i]);
	printf("%lld\n",fans);	
	free(table);
	free(lp);
	free(idx);
	for(int i=0;i<=n;i++)
	{
		free(a[i]);
		free(b[i]);
	}
	free(cost[current]);
	free(cost[next]);
	free(a);
	free(b);
	free(cost);
}
