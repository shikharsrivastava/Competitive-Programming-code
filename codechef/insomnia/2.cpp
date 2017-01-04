#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
typedef long long lli;
#define MOD 1000000007

lli powmon(int a,int b)
{
	lli ans = 1;
	while(b>0)
	{
		if(b&1)
			ans = (ans*a)%MOD;
		a = ((lli)a*a)%MOD;
		b /= 2;
	}
	return ans;
}

int main()
{
	int t;
	lli ans;
	scanf("%d",&t);
	int f[27];
	char s[101];
	while(t--)
	{
		ans = 0;
		memset(f,0,sizeof(f));
		scanf("%s",s);
		for(int i=0;i<strlen(s);i++)
			f[s[i]-'a']++;

		for(int i=0;i<26;i++)
			ans = (ans + powmon(2,f[i]) - 1)%MOD;
		printf("%lld\n",ans);
	}
}
