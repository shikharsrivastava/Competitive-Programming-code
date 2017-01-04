#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define max(a,b) a>b?a:b
using namespace std;


struct Node
{
struct Node* lchild;
struct Node* rchild;
};

struct ARR
{
int data;
unsigned int maxx;
unsigned int revmax;
};
unsigned int *power;
unsigned int insert(struct Node*,struct Node*,int,int);
void simpleinsert(struct Node*,int,int);
unsigned int scanint()
    {
    unsigned int num=0;
    register int a=getchar_unlocked();
    while(a>47 && a<58)
    {
    num=(num<<1)+(num<<3)+a-48;
    a=getchar_unlocked();
    }
    return num;
    } 
int main()
{
	
	power=(unsigned int*)calloc(34,sizeof(unsigned int));
	power[0]=1;
	for(int i=1;i<33;i++)
	power[i]=power[i-1]<<1;
	struct Node *rootfront,*rootback;
	struct ARR* a;	
	unsigned int n,p,q,var,level,maxx=0,sum=0;
	maxx=0,sum=0;
	n=scanint();
	a=(struct ARR*)calloc(n,sizeof(struct ARR));

	rootfront=(struct Node*)calloc(1,sizeof(struct Node));
	rootback=(struct Node*)calloc(1,sizeof(struct Node));
	rootfront->lchild=rootfront->rchild=rootback->lchild=rootback->rchild=NULL;
	

	for(int i=0;i<n;i++)
	{
		a[i].data=scanint();
		if(a[i].data>maxx)
		maxx=a[i].data;
	}

	level=floor(log2(maxx));
	simpleinsert(rootfront,0,level);
	simpleinsert(rootback,0,level);
	p=0;
	q=0;
	var=0;
	for(int i=0;i<n;i++)
	{
		q=p^a[i].data;
		a[i].maxx=max(var,(q^insert(rootfront,rootfront,q,level)));
		var=a[i].maxx;
		p=q;
	}
	p=0;
	q=0;
	var=0;
	for(int i=n-1;i>=0;i--)
	{
		q=p^a[i].data;	
		a[i].revmax=max(var,(q^insert(rootback,rootback,q,level)));
		var=a[i].revmax;
		p=q;
	}
	sum=0;
	maxx=0;
	for(int i=0;i<=n-2;i++)
	{
		sum=a[i].maxx+a[i+1].revmax;
		if(sum>maxx)
		maxx=sum;
	}
	cout<<maxx<<endl;
	free(a);
	return 0;
}

	unsigned int insert(struct Node* nodeins,struct Node* nodequer,int n,int level)
{
	if(level<0)
	return 0;
	unsigned int x=((n>>level)&1);
	
	if(x)
	{
		if(nodeins->rchild==NULL)
		{
		nodeins->rchild=(struct Node*)calloc(1,sizeof(Node));
		nodeins->rchild->lchild=nodeins->rchild->rchild=NULL;
		}
		if(nodequer->lchild==NULL)
			return power[level]+insert(nodeins->rchild,nodequer->rchild,n,level-1);

		else
			return insert(nodeins->rchild,nodequer->lchild,n,level-1);
		
		
	}
	else
	{
		if(nodeins->lchild==NULL)
		{
		nodeins->lchild=(struct Node*)calloc(1,sizeof(Node));
		nodeins->lchild->lchild=nodeins->lchild->rchild=NULL;
		}
		if(nodequer->rchild==NULL)
			return insert(nodeins->lchild,nodequer->lchild,n,level-1);

		else
			return power[level]+insert(nodeins->lchild,nodequer->rchild,n,level-1);	
			
	}
	
}

	void simpleinsert(struct Node* node,int n,int level)
{
	if(level<0)
	return;
	unsigned int x=((n>>level)&1);
	
	if(x)
	{
		if(node->rchild==NULL)
		{
		node->rchild=(struct Node*)calloc(1,sizeof(Node));
		node->rchild->lchild=node->rchild->rchild=NULL;
		}
		simpleinsert(node->rchild,n,level-1);
		
	}
	else
	{
		if(node->lchild==NULL)
		{
		node->lchild=(struct Node*)calloc(1,sizeof(Node));
		node->lchild->lchild=node->lchild->rchild=NULL;
		}
		simpleinsert(node->lchild,n,level-1);
			
	}
	return;
}

