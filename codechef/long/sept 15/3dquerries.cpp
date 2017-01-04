
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

struct arr
{
int x;
int y;
int z;
};
int main()
{

int n,q,A,B,C,D,i,j,k;
long double sum;
int div;
scanf("%d %d",&n,&q);
div=(n*(n-1));
struct arr* a=(struct arr*)calloc(n+1,sizeof(struct arr));
for(i=0;i<n;i++)
cin>>a[i].x>>a[i].y>>a[i].z;

for(=0;i<q;i++)
{
sum=0;
scanf("%d %d %d %d",&A,&B,&C,&D);
for(j=0;j<n;j++)
for(k=0;k<n;k++)
{
if(j==k)
continue;
sum+=abs(A*(a[j].x-a[k].x)+B*(a[j].y-a[k].y)+C*(a[j].z-a[k].z)+D)/sqrt(pow((a[j].x-a[k].x),4)+pow((a[j].y-a[k].y),4)+pow((a[j].z-a[k].z),4));
}

printf("%.15Lf\n",sum/div);
}
free(a);
}
