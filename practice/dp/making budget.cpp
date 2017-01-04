#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mem[25][10000];
int m[25];
int n,h,sal,ser;
ll dp(int index,int count)
{
	if(index == n)
		return count*sal;

	if(mem[index][count] != -1)
		return mem[index][count];

	ll ans = 100000000000000;	
	if(m[index+1] >= count)
		ans = min(ans,(m[index+1]-count)*h + count*sal + dp(index+1,m[index+1]));
	if(m[index+1] < count)
		{
			for(int i=count-m[index+1];i>= 0;i--)
				ans = min(ans, i*ser + count*sal + dp(index+1,count-i));
		}
	mem[index][count] = ans;
	return ans;
}
int main()
{
	
	scanf("%d",&n);
	int c = 0;
	while(n)
	{
		c++;
		memset(mem,-1,sizeof(mem));
		scanf("%d %d %d",&h,&sal,&ser);
		for(int i=1;i<=n;i++)
			scanf("%d",&m[i]);
		
		printf("Case %d, cost = $%lld\n",c,dp(0,0));
		scanf("%d",&n);	
	}
	
}
