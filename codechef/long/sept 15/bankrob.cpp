#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int t,m;
double p,c,pm,pm1;
cin>>t;
while(t--)
{
cin>>m>>p;
pm=pow((-p),m);
pm1=pow((-p),(m-1));
if(p==0)
cout<<fixed<<(double)1000000000<<" "<<(double)0<<endl;
else if(p==1)
{
if(m%2==0)
cout<<fixed<<(double)0<<" "<<(double)1000000000<<endl;
else
cout<<fixed<<(double)1000000000<<" "<<(double)0<<endl;
}
else
cout<<fixed<<1000000000*((1-pm)/(1+p))<<" "<<1000000000*p*((1-pm1)/(1+p))<<endl;
}
}
