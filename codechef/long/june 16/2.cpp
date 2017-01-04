#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%6 == 0)
		printf("Misha\n");
		else
		printf("Chef\n");
	}
}
