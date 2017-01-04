#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull choose[65][65];
ull k;
ull bc(ull num)
{
	ull ret =0;
	for(int i=63;i>=0;i--)
		if((num>>i)&1)
			ret++;
	return ret;
} 
ull ans(ull num)
{
	ull ret = 0;
	int c = 0;
	for(int i=63;i>=0;i--)
		if((num>>i)&(ull)1 && i>=k-c)
			ret += choose[i][k-c] , c++;
	if(bc(num) == k)
		ret++;
	return ret;
}
int main()
{
	/* building pascals triangle for nCr*/
	choose[0][0] = 1;
	for(int i=1;i<=64;i++)
	{
		choose[i][0] = 1;
		for(int j=1;j<=i;j++)
			choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
	}
	
	ull m,s,e,mid;
	cin>>m>>k;
	s = 1, e = 1000000000000000000;
	while(s<e)
	{
		mid = (s+e)>>1;
		if(ans(mid<<1)-ans(mid) >= m)
			e = mid;
		else
			s = mid+1;
	}
	cout<<s<<endl;
	
}
