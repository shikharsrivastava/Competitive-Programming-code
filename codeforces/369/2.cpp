#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
typedef long long int lli;

int main()
{

	int n,pi,pj;
	scanf("%d",&n);
	
	int g[n+1][n+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			{scanf("%d",&g[i][j]);if(g[i][j] == 0) pi = i, pj = j;}
		
	if(n == 1)
	{cout<<"1"<<endl;return 0;}
	
	lli colsum[n+1],rowsum[n+1];
	lli sum,ans;
	memset(colsum,0,sizeof(colsum));
	memset(rowsum,0,sizeof(rowsum));

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			colsum[j] += g[i][j];
			rowsum[i] += g[i][j];
		}
	if(pi == 1)
		sum = rowsum[2];
	else
		sum = rowsum[1];
		
	
	bool f = true;
	if(rowsum[pi] != colsum[pj])
		f = false;
	else
	{
		ans = sum - rowsum[pi];
		if(ans <=0)
			{f = false;}
		else
		{
			g[pi][pj] = ans;
			rowsum[pi] = colsum[pj] = sum;
			for(int i=1;i<=n;i++)
				if(rowsum[i] != sum || colsum[i] != sum)
					{f = false;break;}
			lli ds = 0;
			for(int i=1;i<=n;i++)
				ds += g[i][i];
			if(ds != sum)
			{f = false;}
			ds = 0;
			for(int i=n;i>=1;i--)
				ds += g[i][n-i+1];
			if(ds != sum)
			{f = false;}
		}
	}
	if (f)
	cout<<ans<<endl;
	else
	cout<<"-1"<<endl;;
	
		
	
}
