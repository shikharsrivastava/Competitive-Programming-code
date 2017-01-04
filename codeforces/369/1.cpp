#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int main()
{
	int n;
	scanf("%d",&n);
	char s[n+1][7];
	for(int i=1;i<=n;i++)
		scanf("%s",&s[i][0]);
	bool f = false;
	for(int i=1;i<=n;i++)
	{
		if(s[i][0]== 'O' && s[i][1] == 'O')
			{f = true;s[i][0]= '+', s[i][1] = '+';break; }
		else if(s[i][3]== 'O' && s[i][4] == 'O')
			{f = true;s[i][3]= '+', s[i][4] = '+';break;}
	}
	if(f)
	{
		printf("Yes\n");
		for(int i=1;i<=n;i++)
			printf("%s\n",s[i]);
		
	}
	else
		printf("No\n");
}
