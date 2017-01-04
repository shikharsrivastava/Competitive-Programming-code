#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define mp make_pair()
#define pb push_back


int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	char s[n+4][m+4];	
	for(int r=1;r<=n;r++)
	scanf("%s",s[r]);
	
	int *rw = (int*)calloc(n+5,sizeof(int));
	int *col = (int*)calloc(m+5,sizeof(int));
	int cnt = 0;
	for(int r=1;r<=n;r++)
	{
		for(int c=0;c<m;c++)
		{
			if(s[r][c] == '*')
			{
				cnt++;
				rw[r]++;
				col[c]++;
			}
		}
	}
	
	int ansr = -1,ansc = -1;
	for(int r=1;r<=n;r++)
		for(int c=0;c<m;c++)
			if(rw[r] + col[c] - (s[r][c] == '*' ?1:0) == cnt)
					{ansr = r , ansc = c+1;}
				

	if(ansr != -1)
	printf("YES\n%d %d\n",ansr,ansc);
	else
	printf("NO\n");
	
	
}

