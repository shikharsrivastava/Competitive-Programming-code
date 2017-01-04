//14:29
#include<bits/stdc++.h>
using namespace std;
#define N 100
char s[3][N];
int ans[3][N];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s %s",&s[1][1],&s[2][1]);
		for(int i=1;i<=n;i++)
		{
			if(s[1][i] == '#')
			ans[1][i] = ans[2][i] = ans[1][i-1] ;
			else if(s[2][i] == '#')
			ans[1][i] = ans[2][i] = ans[2][i-1];
			else
			{
				if(s[1][i-1] == '#')
				ans[1][i] = ans[1][i-1]+1 , ans[2][i] = ans[2][i-1];
				else if(s[2][i-1] == '#')
				ans[2][i] = ans[2][i-1]+1 , ans[1][i] = ans[1][i-1];
				else
				ans[1][i] = ans[1][i-1] +1 , ans[2][i] = ans[2][i-1]+1;
			}
		}
		printf("%d\n",max(ans[1][n],ans[2][n]));
	}
}
