#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
int temp,n,m,c,count=0;
scanf("%d %d %d",&n,&m,&c);
int* upper=(int*)calloc(c+1,sizeof(int));
int* lower=(int*)calloc(c+1,sizeof(int));
int* sphere=(int*)calloc(c+1,sizeof(int));
int** ans=(int**)calloc(c+2,sizeof(int*));
for(int i=0;i<c+2;i++)
ans[i]=(int*)calloc(c+1,sizeof(int));

int i;
for(int i=0;i<n;i++)
{
scanf("%d",&temp);
upper[temp]++;
}

for(int i=0;i<m;i++)
{
scanf("%d",&temp);
lower[temp]++;
}

for(int i=1;i<=c;i++)
{
sphere[i]=((long long)upper[i]*lower[i])%1000000007;
//cout<<"Spheres of radius "<<i<<" = "<<sphere[i]<<endl;
}
for(int i=1;i<=c;i++)
{
ans[1][i]=(ans[1][i-1]+sphere[i])%1000000007;
//cout<<"sum ["<<i<<"] = "<<ans[1][i]<<endl;
}



for(int i=2;i<=c;i++)
{
	for(int j=i;j<=c;j++)
	ans[i][j]=(ans[i][j-1]+(long long int)sphere[j]*ans[i-1][j-1])%1000000007;
	cout<<ans[i][c]<<" ";
}
cout<<"0\n";
free(upper);
free(lower);
free(sphere);
for(int i=0;i<c+1;i++)
free(ans[i]);
free(ans);
}
