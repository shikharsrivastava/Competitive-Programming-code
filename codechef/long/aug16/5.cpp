//11:09
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct Matrix
{
	ull rowg[10][501];
	ull colg[501][10];
	int nr,nc;
	
	 Matrix(bool **mat,int row,int col)
	{
		nr = row;
		nc = col;
		memset(rowg,0,sizeof(rowg));
		memset(colg,0,sizeof(colg));
		// building column group
		for(int r=1;r<=nr;r++)
			for(int c=1;c<=nc;c++)
				colg[r][(c-1)/64+1] |= (((ull)mat[r][c]) << (64-c));
		for(int c=1;c<=nc;c++)
			for(int r=1;r<=nr;r++)
				rowg[(r-1)/64+1][c] |= (((ull)mat[r][c]) << (64-r));
	}
	Matrix operator* (const Matrix &mat2)
	{
		int ansr = nr;
		int ansc = mat2.nc;
		bool **ansmat = (bool**)calloc(ansr+1,sizeof(bool*));
		for(int i=0;i<=ansr;i++)
		ansmat[i] = (bool*)calloc(ansc+1,sizeof(bool));

		for(int r=1;r<=nr;r++)
			for(int c=1;c<=mat2.nc;c++)
				for(int k=1;k<=ceil((nc/64.0));k++)
						if((colg[r][k] & mat2.rowg[k][c]) > (ull)0)
							{ansmat[r][c] = true;break;}
	
	
		Matrix matobj(ansmat,ansr,ansc);	
		return matobj;
	}
	void print()
	{
		int ans = 0;
		for(int c=1;c<=nc;c++)
		if(rowg[1][c])
			ans++;
		printf("%d\n",ans);
		if(ans == 0)
		{printf("-1\n");return;}
		for(int c=1;c<=nc;c++)
		if(rowg[1][c])
			printf("%d ",c);
		printf("\n");
	}
	
};


void calculatepower(Matrix a,Matrix *p)
{
	p[0] = a;
	int power = 1; 
	while(power<=30)
	{
		p[power] = p[power-1]*p[power-1];
		power++;
	}
}

int main()
{
	int n,m,tmp,s;
	unsigned int k;
	scanf("%d",&n);

	bool **tm = (bool**)calloc(n+1,sizeof(bool*));
	for(int i=0;i<=n;i++)
	tm[i] = (bool*)calloc(n+1,sizeof(bool));

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			{scanf("%d",&tmp);tm[i][j] = tmp&1;}
	Matrix transition(tm,n,n);


	Matrix *p = (Matrix*)calloc(35,sizeof(Matrix));
	calculatepower(transition,p);
	scanf("%d",&m);

	bool **st = (bool**)calloc(2,sizeof(bool*));
	for(int i=0;i<=1;i++)
	st[i] = (bool*)calloc(501,sizeof(bool));

	while(m--)
	{
		scanf("%u %d",&k,&s);
		st[1][s] = true;
		Matrix start(st,1,n);
		int bit = 0;
		while(k>0)
		{
			if(k&1)
				start = start * p[bit];
			k =k>>1;
			bit++;
		}	
		start.print();
		st[1][s] = false;	
	}

}

