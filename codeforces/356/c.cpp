#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool ip = true;
	int prime[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	char s[4];
	int c = 0;
	for(int i=0;i<15;i++)
	{
		printf("%d\n",prime[i]);
		fflush(stdout);
		scanf("%s",s);
		if(strcmp(s,"yes") == 0)
		{
			c++;
			if(c>=2)
		{
			ip = false;
			break;
		}
			if(prime[i]*prime[i]<=100)
			{
				printf("%d\n",prime[i]*prime[i]);
				fflush(stdout);
				scanf("%s",s);
				if(strcmp(s,"yes") == 0)
				c++;	
			}
		}
		if(c>=2)
		{
			ip = false;
			break;
		}
	}
	if(ip)
	printf("prime\n");
	else
	printf("composite\n");
	fflush(stdout);
}
