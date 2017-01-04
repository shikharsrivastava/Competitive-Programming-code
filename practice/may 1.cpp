//21:28
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,ans1,ans2,n;
	char st1,st2;
	scanf("%d",&t);
	char *s=(char*)calloc(2000005,sizeof(char));
	while(t--)
	{
		ans1=0,ans2=0;
		scanf("%d",&n);
		scanf("%s",s);
		st1='B',st2='G';
		for(int i=0;i<2*n;i++)
		{
			if(s[i] != st1)
			ans1++;
			else
			ans2++;
			swap(st1,st2);	
		}
		printf("%d\n",min(ans1,ans2)/2);
	}
}
