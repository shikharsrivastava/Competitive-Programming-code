#include<bits/stdc++.h>
using namespace std;

int ma[10010];
int req = (1 << 26) - 1;
int main()
{
	int n1,n2;
	scanf("%d %d",&n1,&n2);

	char s[1001];

	for(int i=1;i<=n1;i++)
	{
		scanf("%s",s);
		int l = strlen(s);
		for(int j=0;j<l;j++)
			ma[i] |= (1<<(s[j]-'A'));
		
	}
	int ans = 0;
	
	for(int i=1;i<=n2;i++)
	{
		scanf("%s",s);
		int m = 0; 
		int l = strlen(s);
		for(int j=0;j<l;j++)
			m |= (1<<(s[j]-'A'));
		for (int j = 1; j <= n1; j++) {
			if ((m | ma[j]) == req)
				ans++;
		}
	}
	printf("%d\n",ans);
}
