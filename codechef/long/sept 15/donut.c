
#include<stdio.h>
#include<stdlib.h>

 int scanint()
    {
    int num=0;
    register int a=getchar_unlocked();
    while(a>47 && a<58)
	    {
		    num=(num<<1)+(num<<3)+a-48;
		    a=getchar_unlocked();
    		}
    	return num;
    	}	 

int main()
{
	int t,m,x,ans,i;
	int* a;
	t=scanint();
	while(t--)
	{
		ans=0;
		m=scanint();
		m=scanint();
		
		a=(int*)calloc(100001,sizeof(int));		
		for(i=0;i<m;i++)
		{
			x=scanint();
			a[x]++;
		}
		x=m-1;
		for(i=1;i<=100000;i++)
		{
			if(a[i]==0)
				continue;
			else
			{
				x--;
				a[i]--;
				ans+=i;
				x-=i;
				if(x==0)
					break;
				else if(x<0)
				{
					ans+=x+1;
					break;
				}
				if(a[i]>0)
				i--;
			}
		}
		free(a);
		printf("%d\n",ans);	
	}
}
