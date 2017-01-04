//13:46
/*
	Simple kmp used 
	Consider each column of the pattern as a single alphabet and calculate prefix function for the pattern
	For comparing the alphabets represented by each column we compare the corresponding columns with each other using (function matchcolumn(int a,int b))
	

	if pattern is 
	abca
	abac
	aabc

	its prefixes are	
	a	ab	abc	abca
	a	ab	aba	abac
	a	aa	aab	aabc

	We calculate prefix function for these prefixes considering the pattern as a 1D string of alphabets

	Two columns are equal if all characters in those columns are equal and so the alphabets representing those columns are also equal 			     
	(function matchcolumn(int a,int b))

	After making the prefix function we use KMP substring search algorithm on the text (mp) in blocks of n1*m2
	n1*m2 is considered as a 1D string of length m2 where each column is represented by some alphabet and for comparing alphabets of this psuedo 1D string we 	  compare the corresponding columns with corresponding columns of the pattern using (function matchcolumn(int row,int k,int j)).If the columns are equal
	the correspondig alphabets are also equal


	Simply it is the idea of KMP extended in 2D and in place of comparing charecters at position i and j, we compare the respective columns at i and j 
*/
#include<bits/stdc++.h>
using namespace std;
int n1,n2,m1,m2;
char **marsh,**mp;
int *pre;


bool matchcolumn(int a,int b)	// Function to campare two column of the pattern , returns true if two columns are entirely same therefore 
{
	for(int i=0;i<n1;i++)
		if(marsh[i][a] !=marsh[i][b])
			return false;
	return true;
}
bool matchcolumn(int row,int k,int j)
{	
		for(int i=0;i<n1;i++)
		if(marsh[i][k] != mp[row+i][j])
		return false;
		return true;
}
void calpre()	//calculating prefix function for the pattern
{

	int i=0,j=1;
	bool match=false;
	pre[0]=0;	//pre[i] stores the longest suffix prefix of prefix pattern[1..i]
	for(i=1;i<n2;i++)
	{
		j=pre[i-1];
		match=matchcolumn(i,j);
		while(j>0 && !match)	// same as 1D calculation in place of s[i]!=s[j] we use machcolumn(i,j) to match entire column
		{
			j=pre[j-1];
			match=matchcolumn(i,j);
		}
		
		if(match)
		++j;
		pre[i]=j;
	}
}

void KMP()
{
	bool flag=false;
	int lim=m1-n1;	// lines from where bloack of size n1*m2 can be formed
	for(int i=0;i<=lim;i++)
	{
		int k=0;
		bool match=false;
		for(int j=0;j<m2;j++)	// simple KMP substring searching algorithm , instead of pat[k]!=s[j] we use matchcolumn(i,k,j) ,where i is the string in which
					//pattern has to be found
		{

			match=matchcolumn(i,k,j);
			//printf("K = %d j = %d match = %d\n",k,j,match);
			while(k>0 && !match)
			{
			k=pre[k-1];
			match=matchcolumn(i,k,j);
			}			
			if(match)
			++k;

			if(k==n2)
			{
				printf("(%d,%d)\n",i+1,j-n2+2);
				k=pre[k-1];
				flag=true;
			}
		}
	}
	if(flag==false)
	printf("NO MATCH FOUND...\n");
}

int main()
{

	scanf("%d %d",&n1,&n2);
	pre=(int*)calloc(n2+1,sizeof(int));
	marsh=(char**)calloc(n1+1,sizeof(char*));
	for(int i=0;i<=n1;i++)
	marsh[i]=(char*)calloc(n2+1,sizeof(char));

	for(int i=0;i<n1;i++)
	scanf("%s",marsh[i]);

	
	scanf("%d %d",&m1,&m2);
	mp=(char**)calloc(m1+1,sizeof(char*));
	for(int i=0;i<=m1;i++)
	mp[i]=(char*)calloc(m2+1,sizeof(char));

	for(int i=0;i<m1;i++)
	scanf("%s",mp[i]);

	calpre();
	KMP();



}
