#include<iostream>
#include<cstdlib>
#include<cstdio>

int gcd(int m,int n)
{
	if(n%m==0)
	return m;
	return gcd(n%m,m);
}

int coprime(int m,int n)
{
if(gcd(m,n)>1)
return 0;
return 1;
}


using namespace std;
int main()
{
int t,c,k,n;


int* arr=(int*)calloc(5000001,sizeof(int));
for(int m=1;m<=2500;m++)
{	
	for(n=m+1;n<=2500;n++)
		{	
			if(coprime(m,n))
			{	
				c=m*m+n*n;
				if(c>5000001)
				break;
				
				if(arr[c]==1)
				continue;
				
				k=1;
				while(c*k<=5000001)
				{	cout<<"c*k = "<<c*k<<endl;
					getchar();
					arr[c*k]=1;
					k++;
				}

			}
		}
}
cin>>t;
while(t--)
{
cin>>n;
if(arr[n])
cout<<"YES\n";
else
cout<<"NO\n";
}
}
