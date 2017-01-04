#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
int t;
float a,r,angle,error=(float)1/120;
scanf("%d",&t);
while(t--)
{
scanf("%f",&a);
for(int hr=0;hr<12;hr++)
for(int min=0;min<60;min++)
{
angle=abs((float)6*min-(((float)60*hr+min)/2));
if(angle==a || angle==360-a)
printf("%02d:%02d\n",hr,min);
else if(fabs(angle-a)<error ||fabs(angle-(360-a))<error)
printf("%02d:%02d\n",hr,min);

}
}
}
