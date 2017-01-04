#include<bits/stdc++.h>
#define MOD 1000000007
struct matrix
{
	long long int **mat;
	int r,c;
	
	matrix(int m,int n)
	{
	r=m;
	c=n;
	mat=(long long int**)calloc(m+1,sizeof(long long int*));
	for(int i=0;i<=m;i++)
	mat[i]=(long long int*)calloc(n+1,sizeof(long long int));
	}
	
	matrix operator*(matrix &m2)
	{
		matrix ans(r,m2.c);

		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=m2.c;j++)
			{
			for(int k=1;k<=c;k++)
			ans.mat[i][j]+=(mat[i][k]*m2.mat[k][j])%MOD;
			}
		}
		return ans;
	}
	void display()
	{
		for(int i=1;i<=r;i++)
		{
		for(int j=1;j<=c;j++)
		printf("%lld ",mat[i][j]);
		printf("\n");
		}
	}
};

matrix power(matrix m,int n)
{
	matrix ans(m.r,m.c);
	for(int i=1;i<=m.r;i++)
	ans.mat	[i][i]=1;

	int j=2,base=1;
	while(n>0)
	{

		if(n%2==1)
		ans=ans*m;
		m=m*m;
		n/=2;
	}
	return ans;
}

int main()
{
	matrix t(2,2),m1(2,1);
	m1.mat[1][1]=0;
	m1.mat[2][1]=1;
	t.mat[1][1]=0;
	t.mat[1][2]=1;
	t.mat[2][1]=1;
	t.mat[2][2]=1;
	
	int n;
	scanf("%d",&n);
	if(n==1)
	printf("0\n");
	else{
	matrix pw=power(t,n-1);
	printf("%lld\n",(pw*t).mat[2][1]);
	}
	
	
}
