// 11:50
#include<bits/stdc++.h>

using namespace std;
int main()
{
	int a,b,c,n;
	scanf("%d %d %d %d",&n,&a,&b,&c);
	
	int ribbon[n+2];
	memset(ribbon,0,sizeof(ribbon));
	ribbon[0] = 1;
	for(int i=1;i<=n;i++)
	{
		if(i >= a && ribbon[i-a])
			ribbon[i] = max(ribbon[i],1+ ((i-a) == 0?0:ribbon[i-a]));
		if(i >= b &&  ribbon[i-b])
			ribbon[i] = max(ribbon[i],1+ ((i-b) == 0?0:ribbon[i-b]));
		if(i>=c && ribbon[i-c])
			ribbon[i] = max(ribbon[i],1+ ((i-c) == 0?0:ribbon[i-c]));		
	}
	printf("%d\n",ribbon[n]);
}
