//23:01
#include<bits/stdc++.h>
using namespace std;

bool checkpalin(int n,int k)
{
	int rev = 0;
	int temp = n;
	int ans
	while(temp >n)
	{
		c = temp %10;
		rev = rev*10+c;
		temp/=10;
	}
	temp = n;
	while(temp >0)
	{
		if(temp %10 != rev %10)	
		ans++;
		temp /= 10;
		rev /= 10;
	}
	if(ans >k)
	return false;	
	return true;	
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	if(checkpalin(n,k))
	{
	}
	else
	printf("-1\n");
}
