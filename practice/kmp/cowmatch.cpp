//00:27
/*
	The most important thig is to find when two sequencs a,b can be said to be equal

	We note the sequences
a->	1 4 5 2 1 1 3
b->	5 8 9 6 5 5 7
c->	3 8 9 5 3 3 6

	are euqal because they all can are same if we map the values of each element with its index in sorted order
	therefore

sequence	-> 		3 8 9 5 3 3 6		5 8 9 6 5 5 7		1 4 5 2 1 1 3
index in sorted order-> 	1 4 5 2 1 1 3		1 4 5 2 1 1 3		1 4 5 2 1 1 3


	Therefore all the equal sequence can be represented by any one of them 

	We use this idea in KMP

	Prefix function stores for an index i , the length of gretest proper prefix of s[1...i] that is also EQUAL to its suffix
	For checking this EQUALITY we will use the idea above instead of simple string equality and find the prefix function

	For string matching with KMP also we use the same idea for EQUALITY instead of simple string equality

	IMPLEMENTATION
	
	For implemnting this EQUALITY function we will maintain a dynamic set of two strings with the help of fenwik tree (bit)
	Every time before adding an element in the set we will check the index of that element in the sorted set previously present

	We will maintain two sets for comparing two strings, the first contains the elements of string in which pattern has to be found
	the second srtring will contain the pattern to be matched
	
	Of course in calculation of prefix function both these strings are the part of the same string (pattern).

	We will take necessary steps if the strings are equal or unequal according to KMP



*/
#include<bits/stdc++.h>
using namespace std;

struct bit
{
	int a[28];
	void add(int x,int v) //Adds the element x to the set
	{
	while(x<28)
	{
		a[x]+=v;
		x+=x&-x;
	}
	}
	int sum(int x)//Sum returns the number of elements currently present in the set which are less than or equal to x.
	{
		int ans=0;
		while(x>0)
		{
		ans+=a[x];
		x-=x&-x;
		}
		return ans;
	}
	void clear()
	{
		memset(a,0,sizeof(a));
	}
} set1,set2; //Two bits for our dynammic sets


int main()
{
	vector<int> ans; //Vector to store the answer
	int n,m,s;
	scanf("%d %d %d",&n,&m,&s);
	int *pat=(int*)calloc(m+2,sizeof(int));// arrays for pattern,cow and prefix function on patetrn
	int *cow=(int*)calloc(n+2,sizeof(int));
	int *pre=(int*)calloc(m+2,sizeof(int));

	for(int i=0;i<n;i++)
	scanf("%d",&cow[i]);
	
	for(int i=0;i<m;i++)
	scanf("%d",&pat[i]);

	//Calculating prefix function on pattern
	int j=0;
	for(int i=1;i<m;i++)
	{
		j=pre[i-1];
		/*Checking if the addition of elements pat[i] and pat[j] to their respective sets (set1,set2) will make them unequal*/
		while(j>0 && ( (set1.sum(pat[i]) != set2.sum(pat[j]) ) || (set1.sum(pat[i]-1) != set2.sum(pat[j]-1)) ) )
		{/*If the sets become unequal , we use the prefix function property j=pre[j-1]
		But since here it is not a string which can be indexed to ignore the elements , but a set ,
		We have to manually delete the values that will be gone when we put j=pre[j-1] from both the sets		
		*/
		for(int k=pre[j-1];k<j;k++)
		{	
			set2.add(pat[k],-1);
			set1.add(pat[i-j+k-pre[j-1]],-1);
		}	
		j=pre[j-1]; //Now changing the value of j
		}
		/**If now the addition of elements pat[i] and pat[j] to their respective sets (set1,set2) maintains their EQUALITY*/
		if((set1.sum(pat[i]) == set2.sum(pat[j]) ) && (set1.sum(pat[i]-1) == set2.sum(pat[j]-1)))
		{
			/*Since these are sets and simple increment in indexex i and j will nt include the values at i ad j 
			so manually adding these elements to their respective sets*/
			set1.add(pat[i],1);
			set2.add(pat[j],1);
			++j;
		}
		pre[i]=j;
	}
	/*Now prefix function is calculated so clearing the sets*/	
	set1.clear();
	set2.clear();

	/*Using KMP algorithm to search the string for pattern using the same EQUALITY laws and the prefix funcction just calculated*/
	j=0;
	for(int i=0;i<n;i++)
	{
		
		/*Again the same procedure to check the equality of groups*/
		while(j>0 && ( (set1.sum(cow[i]) != set2.sum(pat[j]) ) || (set1.sum(cow[i]-1) != set2.sum(pat[j]-1)) ) )
		{
		for(int k=pre[j-1];k<j;k++)
		{	/*Again manual deletion*/
			set2.add(pat[k],-1);
			set1.add(cow[i-j+k-pre[j-1]],-1); // No +1 because we are deleting values with respect to i-1 so i-1+1 = i (no +1)
		}	
		j=pre[j-1];
		}

		if((set1.sum(cow[i]) == set2.sum(pat[j]) ) && (set1.sum(cow[i]-1) == set2.sum(pat[j]-1)))
		{
			/*Again manual addition*/
			set1.add(cow[i],1);
			set2.add(pat[j],1);
			++j;
		}
		if(j==m)
		{
		/*Now here again we are changing the value of j so we have to manually delete ignored elements from the respective sets
		  these are sets , not strings which can be differently indexed to ignore the elements*/
		
		ans.push_back(i-m+2);  //Adding the answer to our answer vector
		for(int k=pre[j-1];k<j;k++)
		{
			set2.add(pat[k],-1);
			set1.add(cow[i-j+1+k-pre[j-1]],-1);	//this time extra +1 as we are deleting values with respect to i
		}
		
		j=pre[j-1];
		}
	}

	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	printf("%d\n",ans[i]);
	
}
