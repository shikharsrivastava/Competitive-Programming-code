//00:38
/*
	Grundy numbers
	Move from right to left in each row and calculate grundy number of the go
	finally xor all grundy numbers of subgames in all row
*/
#include<bits/stdc++.h>
#define N 100
#define M 100
using namespace std;

int main()
{

	int t,n,m,ans,a[N][M];
	scanf("%d",&t);
	while(t--)
	{
		ans = 0;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
	
		for(int i=1;i<=n;i++)
		{
			int gn = 0;	
			for(int j=m;j>=1;j--)
			{
				if(a[i][j] == 1 && gn >0)
				gn = 0;
				else if(a[i][j] != 0 && a[i][j] > gn)
				gn = a[i][j];
				else if(a[i][j] != 0 && a[i][j] <= gn)
				gn = a[i][j] - 1;
			}
			ans = ans ^ gn;
		}
		if(ans)
		printf("FIRST\n");
		else
		printf("SECOND\n");
	}
}
