/*

First solve the 1D version , given an array a find the number of subarrays whose sum lies between A and B Using Divide and Conquer or bit
You have an array of n numbers a1, a2, a3, ... an. And you want to know how many sub-array's are there, which sum is between A and B.
Now, we can make a new array:

F1, F2, F3, F4... F(n+2).

Where

. F1 = 0
. F2 = F1 + a1
. F3 = F2 + a2
. ...
. F(n+1) = Fn + an
. F(n+2) = INF ( i think i used INT_MAX, c++ ).

Now, the idea is use merge-sort to order this array counting "on the fly" the number of subarrays that sum between A and B.

Before you do the merge between 2 arrays arr1 and arr2 ( in a step of the merge sort ), you can iterate in each Fi of arr2, looking which subarray of arr1 contains numbers Fj such that A <= Fi-Fj <= B ( which means A <= A(j+1)+A(j+2)+...+A(i) <= B ). The endpoints of the subarray (of arr1 ) needed for the iteration of Fi can be used to calculate the endpoints of the subarray corresponding to the next iteration ( for F(i+1). This will give you an amortized time to get what we want. 


Now to extend it in 2D , Consider any matrix of ixj as a 1D array of j elements , where each element is a[x] = a[x][1]+a[x][2]...+a[x][j]
And use the same method for it , it wil give the number of submatrix starting at row i and ending at row j with summ betwennn A and B :)

Implement it by making prefix sum for the 1D array just created (of matrix ixj) and using the same method :)
	
*/
#include<bits/stdc++.h>
using namespace std;

int A,B;
int sol;
	
void findans(int *a,int s,int e)
{
	if(s==e)
	return;
	int m=(s+e)/2;
	findans(a,s,m);
	findans(a,m+1,e);
	
	int l=s,r=l;
	for(int j=m+1;j<=e;j++)
	{
		while(l<=m && a[j]-a[l] >B)
		l++;
		while(r<=m && a[j]-a[r]>=A)
		r++;
		sol+=r-l;
	}
	sort(a+s,a+e+1);	
}

int main()
{
	int n,m;
	sol=0;
	scanf("%d %d",&n,&m);

	int** a=(int**)calloc(n+1,sizeof(int*));
	int** sm=(int**)calloc(n+1,sizeof(int*));
	int** psm=(int**)calloc(n+1,sizeof(int*));	
	for(int i=0;i<=n;i++)
	{
	a[i]=(int*)calloc(m+1,sizeof(int));
	sm[i]=(int*)calloc(m+1,sizeof(int));
	psm[i]=(int*)calloc(m+1,sizeof(int));	
	}

	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
		scanf("%d",&a[i][j]);
		psm[i][j]=psm[i][j-1]+a[i][j];
		sm[i][j]=sm[i-1][j]+psm[i][j];
		}
	}

	scanf("%d %d",&A,&B);

	int tmp=0;

	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=0;k<=m;k++)
				sm[j][k]=sm[j-1][k]+psm[j][k];
		}	
		for(int j=i;j<=n;j++)
			findans(sm[j],0,m);		
		
		for(int j=0;j<=m;j++)
		sm[i][j]=0;
	}
	
	printf("%d\n",sol);
	for(int i=0;i<=n;i++)
	{
		free(a[i]);
		free(sm[i]);
		free(psm[i]);
	}
	free(a);
	free(sm);
	free(psm);
	return 0;
	
}
