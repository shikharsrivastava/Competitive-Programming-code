//20:29
/*Simply aply kmp on the difference array as the difference will be same irrespective of the values if the patterns match*/
#include<bits/stdc++.h>
using namespace std;

void calcpre(int *pre, int *s, int n)
{
	int j;
	for(int i=1;i<n;i++)
	{
		j=pre[i-1];
		while(j>0 && s[i] != s[j])
		j=pre[j-1];
		
		if(s[i]==s[j])
		++j;
		pre[i]=j;
	}
}
int main()
{
	int b,e,ans=0;
	scanf("%d %d",&b,&e);
	int *bear=(int*)calloc(b+1,sizeof(int));
	int *elep=(int*)calloc(e+2,sizeof(int));
	
	int *db=(int*)calloc(b+3,sizeof(int));
	int *de=(int*)calloc(e+3,sizeof(int));


	for(int i=0;i<b;i++)
	scanf("%d",&bear[i]);

	for(int i=0;i<e;i++)
	scanf("%d",&elep[i]);

	if(e==1)
	ans=b;
	else
{
	for(int i=0;i<b-1;i++)
	db[i]=bear[i]-bear[i+1];

	for(int i=0;i<e-1;i++)
	de[i]=elep[i]-elep[i+1];


	int* pre=(int*)calloc(e+3,sizeof(int));
	calcpre(pre,de,e-1);
	


	int j=0;
	for(int i=0;i<b-1;i++)
	{
		while(j>0 && de[j] != db[i])
		j=pre[j-1];
		
		if(de[j]==db[i])
		++j;
		if(j==e-1)
		{
			
			ans++;
			j=pre[j-1];
		}
	}

	}
	printf("%d\n",ans);
	return 0;
}
