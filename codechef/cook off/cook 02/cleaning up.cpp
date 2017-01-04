//17:53 - 18:08
#include<bits/stdc++.h>

int main()
{
	int t,n,m,tmp,*a;
	scanf("%d",&t);
	while(t--)
	{	scanf("%d %d",&n,&m);
		a=(int*)calloc(n+1,sizeof(int));
		for(int i=1;i<=m;i++)
		{
		scanf("%d",&tmp);
		a[tmp] = 1;
		}
		bool flip =false;
		for(int i=1;i<=n;i++)
		{
			if(a[i] == 0)
			{		
				if(!flip)
				{
					printf("%d ",i);
					flip = true;	
					a[i] =1;			
				}
				else
				flip = false;
			}
		}
		printf("\n");
		for(int i=1;i<=n;i++)
		{
			if(a[i] == 0)
			{
				printf("%d ",i);
				a[i] = 1;
			}
		}
		printf("\n");
		free(a);
	}
}
