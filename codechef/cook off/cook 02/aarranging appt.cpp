//18:08
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,k,temp,ans;
	char s[1<<16+1];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		scanf("%s",s);

		for(int i=0;i<(1<<k) ; i++)
		{
			ans =0;
			for(int j=0;j<k;j++)
				ans |= ((i>>j)&1)<<(k-j-1);
			printf("%c",s[ans]);
		}
		printf("\n");
	}
}
