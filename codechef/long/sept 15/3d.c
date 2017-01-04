#include<stdio.h>
#include<math.h>
#include<stdlib.h>


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

struct arr
{
int x;
int y;
int z;
};
int main()
{

int n,q,A,B,C,D,i,j,k,val,multiplier;
long double sum;
int div;
n=scanint();
q=scanint();
div=(n*(n-1));
struct arr* a=(struct arr*)calloc(n+1,sizeof(struct arr));
for(i=0;i<n;i++)
{
a[i].x=scanint();
a[i].y=scanint();
a[i].z=scanint();
}




int diff[79][78][78];

for(multiplier=0;multiplier<78;multiplier++)
for(i=0;i<78;i++)
for(j=0;j<78;j++)
diff[multiplier][i][j]=multiplier*(i-j);

int power[78];
for(i=0;i<78;i++)
power[i]=pow(i,4);

double sq[78][78][78];
for(k=0;k<78;k++)
for(i=0;i<78;i++)
for(j=0;j<78;j++)
sq[k][i][j]=sqrt(power[k]+power[i]+power[j]);


for(i=0;i<q;i++)
{
sum=0;
A=scanint();
B=scanint();
C=scanint();
D=scanint();
for(j=0;j<n;j++)
{
for(k=j;k<n;k++)
{
val=abs(diff[A][a[j].x][a[k].x]+diff[B][a[j].y][a[k].y]+diff[C][a[j].z][a[k].z]);

if(j==k)
continue;
if(val>D)
sum+=(val)/sq[abs(diff[1][a[j].x][a[k].x])][abs(diff[1][a[j].y][a[k].y])][abs(diff[1][a[j].z][a[k].z])];
else
sum+=D/sq[abs(diff[1][a[j].x][a[k].x])][abs(diff[1][a[j].y][a[k].y])][abs(diff[1][a[j].z][a[k].z])];
}
}
printf("%.15Lf\n",2*sum/div);
}
free(a);
}
