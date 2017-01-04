//13:46
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,t,s,ak;
	int *a=(int*)calloc(100002,sizeof(int));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			printf("%d ",i);
			printf("\n");
		}
		else
		{
			if(n % (2*k) != 0)
			printf("-1\n");
			else
			{
				s=1;
				ak=k;
				while(s<=n)
				{
					for(int i=1;i<=k;i++,s++)
						a[s]=s+ak;
				
						ak=-ak;
				}
					for(int i=1;i<=n;i++)
					printf("%d ",a[i]);
					printf("\n");
			}
		}
	
	}
}
