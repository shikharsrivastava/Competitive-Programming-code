#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
#define max(a,b) a>b?a:b

using namespace std;
int *a;
vector<int> *vec;
int ***DP;

int findans(int current,int msk,int difference)
{
	if(current<0)
	return 0;

	if(DP[current][difference][msk] !=0)
	return DP[current][difference][msk];

	int ans=findans(current-1, msk,difference+1);
	int var;
	for(int i=0;i<vec[difference].size();i++)
	{
	if(!(msk&vec[difference][i]))
{

	var=a[current]+findans(current-1,msk|vec[difference][i],1);
	ans=max(ans,var);
}

	}

	DP[current][difference][msk] = ans;
	return DP[current][difference][msk];
}

int main()
{

int t,n,m,msk,sm,c,p;
scanf("%d",&t);
while(t--)
{
sm=0;

vec=(vector<int> *)calloc(16,sizeof(vector<int>));
DP=(int***)calloc(16,sizeof(int**));
for(int i=0;i<16;i++)
{
DP[i]=(int**)calloc(16,sizeof(int*));
for(int j=0;j<16;j++)
DP[i][j]=(int*)calloc(1<<16,sizeof(int));
}

scanf("%d",&n);

a=(int*)calloc(n,sizeof(int));
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
sm+=a[i];
}

scanf("%d",&m);


for(int i=0;i<m;i++)
{
scanf("%d",&c);
msk=0;
for(int j=0;j<c;j++)
{
scanf("%d",&p);
msk|=(1<<(p-1));
}
vec[c].push_back(msk);

}


sort(a,a+n);

printf("%d\n",sm-findans(n-1,0,1));

free(a);
free(vec);
for(int i=0;i<16;i++)
{
for(int j=0;j<16;j++)
free(DP[i][j]);
free(DP[i]);
}
free(DP);

}

return 0;
}
