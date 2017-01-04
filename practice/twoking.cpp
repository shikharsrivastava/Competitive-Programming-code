#include<bits/stdc++.h>
#define N 102

int main()
{
	int t,n,k1,k2;
	char s[N];
	scanf("%d",&t);
	while(t--)
	{
		k1=k2=0;
		scanf("%d",&n);
		scanf("%s",&s[1]);
		for(int i=1;i<=n;i++)
		{
			if(s[i] != s[i-1] && s[i] == 'X')
			k1++;
			else if(s[i] != s[i-1] && s[i] == 'O')
			k2++;
		}
		if(k1>=k2)
		printf("X\n");
		else
		printf("O\n");
	}
}
