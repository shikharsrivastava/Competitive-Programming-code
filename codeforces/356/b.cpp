#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a;
	scanf("%d %d",&n,&a);
	int arr[n+1];
	for(int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	int ans = 0;
	int st = a-1;
	int en = a+1;
	while(st >=1 && en <=n)
	{
		if(arr[st] == 1 && arr[en] == 1)
		ans+=2;
		st--;
		en++;
	}
	while(st>=1)
	{
		if(arr[st] == 1)
		ans++;
		st--;	
	}
	while(en<=n)
	{
		if(arr[en] == 1)
		ans++;
		en++;
	}
	if(arr[a] == 1)
	ans++;
	printf("%d\n",ans);

}
