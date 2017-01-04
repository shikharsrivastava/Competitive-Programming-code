#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

struct mat
{
int x;
int y;
};
int main()
{
int a,t,n,ans;
struct mat* matrix;
cin>>t;
while(t--)
{
ans=0;
cin>>n;
matrix=(struct mat*)calloc(n*n+1,sizeof(struct mat));
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
{
cin>>a;
matrix[a].x=j;
matrix[a].y=i;
}
for(int i=2;i<n*n+1;i++)
ans+=abs(matrix[i-1].x-matrix[i].x)+abs(matrix[i-1].y-matrix[i].y);
cout<<ans<<endl;
free(matrix);
}
return 0;
}
