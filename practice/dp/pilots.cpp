#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
int mem[10000/2+1][10001];
// 11:36
int captain[10001],pilot[10001];
int n;

int dp(int pno ,int index)
{
	if(index >n)
		return 0;
	int ret = 0;
	if(mem[pno][index] != 0)
		return mem[pno][index];
	
	
	if(pno == 0)
		{
			int val =  dp(pno+1,index+1);
			
			mem[pno][index] = pilot[index] + val;
			return pilot[index] + val;
		}
	else if(pno == n-index+1)
	{
		for(int i=index;i<=n;i++)
			ret += captain[i];
		mem[pno][index] = ret;
		return ret;
	}	
	else
	{
		ret = INF;
		ret = min(ret,pilot[index] + dp(pno+1,index+1));
		ret = min(ret,captain[index] + dp(pno-1,index+1));
	}
	mem[pno][index] = ret;
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&captain[i],&pilot[i]);
	printf("%d\n",dp(0,1));
}
