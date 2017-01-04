//15:41

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q,temp;
	scanf("%d %d",&n,&q);
	int mn = 1000000001,mx = -1000000001;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		mn = min(mn,temp);
		mx = max(mx,temp);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&temp);
		if(temp >= mn && temp <= mx)
		printf("Yes\n");
		else
		printf("No\n");
	}
}
