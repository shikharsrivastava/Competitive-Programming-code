#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,*a,sum;
	float avg;
	bool f,fu;
	scanf("%d",&t);
	while(t--)
	{
		sum = 0;
		f = fu = false;
		scanf("%d",&n);
		a = (int*)calloc(n+2,sizeof(int));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
			if(a[i] == 2) f = true;
			if(a[i] == 5) fu = true;
		}
		avg = ((float)sum)/n;
		if(f)
		printf("No\n");
		else if(!fu)
		printf("No\n");
		else if(avg < 4.0)
		printf("No\n");
		else
		printf("Yes\n");
		free(a);
	}
}
