#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	char *a =(char*)calloc(1000001,sizeof(char));
	char *b =(char*)calloc(1000001,sizeof(char));
	
	int one,oc,zc,zero,swap,ans;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s",a,b);
		one = zero = ans = oc = zc = 0;
	
		for(int i=0;i<strlen(a);i++)
		{
			if(a[i] != b[i])
			{
				if(a[i] == '1')
				one++;
				else
				zero++;
			}
			if(a[i] == '0')
			zc++;
			else
			oc++;
		} 
			swap = min(zero,one);
			if(swap == zero)		// Some one needs replacement
			{
				if(zc >0)
				{printf("Lucky Chef\n");printf("%d\n",one);}
				else
				printf("Unlucky Chef\n");				
			}
			else
			{				// Some zero needs replacement
				if(oc >0)
				{printf("Lucky Chef\n");printf("%d\n",zero);}
				else
				printf("Unlucky Chef\n");
			}
	}
	free(a);
	free(b);
}
