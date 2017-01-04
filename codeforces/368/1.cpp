#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pb push_back
#define mp make_pair


int main()
{
	int n,m;
	char c;
	bool f = false;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)	
			{
				scanf(" %c",&c);
				if(c == 'C' || c == 'M' || c == 'Y')
					f = true;
			}
	if(f)
		printf("#Color\n");
	else
		printf("#Black&White\n");
	return 0;
}
