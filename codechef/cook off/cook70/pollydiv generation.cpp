//10:25
#include<bits/stdc++.h>
using namespace std;
int cnt[17][40];

int mod(int base,int length,int *current)
{

	int val=0;
	for(int i=0;i<length;i++)
		val=(val*base +current[i]) % length;
	return val;
}
void polydivnum(int base,int length,int *current)
{
	for(int i=0;i<base;i++)
	{
		current[length] = i;
		if(mod(base,length+1,current) == 0)
		{
			cnt[base][length+1]++;
			polydivnum(base,length+1,current);
		}	
	}
}
int main()
{
	int t,b,d;
	for(int i=0;i<17;i++)
	{
		for(int j=0;j<50;j++)
		cnt[i][j] = 0;
	}
	
	int *current =(int*)calloc(1000,sizeof(int));
	printf("{ ");
	for(int b=2;b<=16;b++)
	{
		for(int i=1;i<b;i++)
		{
			current[0] = i;
			if(mod(b,1,current) == 0)
			{
				cnt[b][1]++;
				polydivnum(b,1,current);
			}
		}
	}

	for(int i=0;i<=16;i++)
	{
		printf("{ ");
		for(int l=0;l<=40;l++)
		printf("%d,",cnt[i][l]);
		printf("},\n");
	}
	printf("};");
	return 0;
}
	
