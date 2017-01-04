#include<bits/stdc++.h>
using namespace std;
int *t,j,*a,*mp,sz;

/*
	Using co-ordinate compression make an array of all elements that present any time in the set (At max 100000)
	Make an epmty array and operate segment tree on that array.
	Segment tree on that array stores the gcd of a segment l,r on that array.If an element is completely removed or added 
	for the first time ,update the segment tree respectively (del or add functions) for the index (id) of that element in the
	co-ordinate compressed array.The answer is the gcd of the complete array on which segtree was built.t[1].
	If left segment is empty the gcd of parent is the gcd of right segment and vice versa
*/
struct query
{
	char c;
	int x;
};

int gcd(int a,int b)
{
	if(a==0)
	return b;
	if(b==0)
	return a;

	int temp;
	while(a%b >0)
	{
	temp=a%b;
	a=b;
	b=temp;	
	}
	return b;
}
int bs(int num,int s=1,int e=j)
{
	int m;
	while(s<e)
	{
		m=(e+s)/2;
		if(a[m]>num)
		e=m-1;
		else if(a[m]<num)
		s=m+1;
		else
		return m;
	}
	return s;
}

// Non rcursive update and delete as recursive one is giving tle

void add(int i,int id)
{
	t[i]=a[id];
	i/=2;
	while(i>0)
	{
	t[i]=gcd(t[i*2],t[i*2+1]);
	i/=2;
	}
	return;
}

void del(int i)
{
	t[i]=0;
	i/=2;
	while(i>0)
	{
	t[i]=gcd(t[i*2],t[i*2+1]);
	i/=2;
	}
	return;
}


int main()
{
	int nq,*freq,id;
	map<int,bool> check;
	scanf("%d",&nq);
	query *q=(query*)calloc(nq+1,sizeof(query));
	a=(int*)calloc(nq+1,sizeof(int));
	j=0;
	for(int i=1;i<=nq;i++)
	{
		scanf(" %c %d",&q[i].c,&q[i].x);
		if(q[i].c=='+')
		{
		if(check.find(q[i].x)==check.end())
		{
		a[++j]=q[i].x;
		check[q[i].x]=true;		
		}
		}
	}
	sort(a+1,a+j+1);
	sz=pow(2,ceil(log2(j))+1);
	
	t=(int*)calloc(sz,sizeof(int));
	freq=(int*)calloc(j+1,sizeof(int));


	for(int i=1;i<=nq;i++)
	{
		id=bs(q[i].x);
		if(q[i].c=='+')
		{
		freq[id]++;
		if(freq[id]==1)
		add(sz/2+id-1,id);
		}
		else
		{
		freq[id]--;
		if(freq[id]==0)
		del(sz/2+id-1);
		}
		if(t[1]==0)
		printf("1\n");
		else
		printf("%d\n",t[1]);
	}

return 0;
	
}

