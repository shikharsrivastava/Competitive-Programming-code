#include<iostream>
#include<cmath>
using namespace std;
int main()
{
long long int i,k,s;
double a,b;
cin>>i>>k>>s;
cin>>a>>b;
if((k-i)%2==0)
cout<<fixed<<(a+b)*pow(2,(2*(k-i)-s))<<endl;
else
cout<<fixed<<2*sqrt(2.0)*(a+sqrt(3.0)*b)*pow(2,(2*(k-(i+1))-s))<<endl;
}
