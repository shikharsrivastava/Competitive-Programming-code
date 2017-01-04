#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;

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
	int t,n,m,x,count,ans,links;
	int* a;
	t=scanint();
	while(t--)
	{
		ans=0;
		n=scanint();
		m=scanint();
		links=m-1;
		a=(int*)calloc(100001,sizeof(int));		
		for(int i=0;i<m;i++)
		{
			x=scanint();
			a[x]++;
		}
		for(int i=1;i<=100000;i++)
		{
			if(a[i]==0)
			continue;
			else
			{
			links--;
			a[i]--;
			ans+=i;
			links-=i;
			if(links==0)
			break;
			else if(links<0)
			{
			ans+=links+1;
			break;
			}
			if(a[i]>0)
			i--;
			}
		}
		free(a);
		cout<<ans<<endl;	
	}
}
