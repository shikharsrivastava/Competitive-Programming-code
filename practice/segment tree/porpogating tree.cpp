#include<bits/stdc++.h>

using namespace std;

class node
{
	public:
	int w;
	int beg;
	int end;
	int cbeg;
	int cend;
	int level; 
	vector<int> adj;
};

class snode
{
	public:
	int lazy;
};


	/*
		Split the tree into two arrays using dfs.
		Odd array stores values of vertices at odd level and so for even.
		Since we use dfs for any given node all its children (with same odd or even level) will be in continious sequence in corresponfing array
		We can find this range by and store it during dfs and then add val and -val to the respective ranges of odd and even array.
	
		:) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) 
	*/
snode *otree,*etree;
int n;
node *tree;
int *odd,*even;
int nextodd,nexteven;
void dfs(int level,int index,int prev)
{
	if(level%2==0)
	{
	tree[index].beg=nexteven+1;
	even[++nexteven]=tree[index].w;
	if(tree[index].adj.size()>1)
	tree[index].cbeg=nextodd+1;
	else
	tree[index].cbeg=-1;
	}
	else
	{
	tree[index].beg=nextodd+1;
	if(tree[index].adj.size()>1)
	tree[index].cbeg=nexteven+1;
	else
	tree[index].cbeg=-1;
	odd[++nextodd]=tree[index].w;
	}

	tree[index].level=level;

	for(int i=0;i<tree[index].adj.size();i++)
	{
	if(tree[index].adj[i] !=prev)
	{
	dfs(level+1,tree[index].adj[i],index);
	}
	}
	if(level%2==0)
	{
	tree[index].end=nexteven;	
	if(tree[index].adj.size()>1)
	tree[index].cend=nextodd;
	else
	tree[index].cend=-1;
	}
	else
	{
	tree[index].end=nextodd;
	if(tree[index].adj.size()>1)
	tree[index].cend=nexteven;
	else
	tree[index].cend=-1;
	}
}

void update(snode *tree,int l,int r,int val,int start=1,int end=n,int i=1)
{

	printf("start = %d ,end = %d\n",start,end);
	
	if (tree[i].lazy != 0) {
		if (start != end) {
			printf("old lazy  = %d\n",tree[i].lazy);
			printf("propogating lazy\n");
			tree[2*i].lazy += tree[i].lazy;
			tree[2*i+1].lazy += tree[i].lazy;
			tree[i].lazy = 0;
		}
		
		
	}

	if (start > r || end < l)
		return;
	
	else if (start >= l && end <= r) {
		tree[i].lazy += val;
		printf("new lazy =%d\n",tree[i].lazy);
	}
	else {
		int mid = (start + end - 1) /2;
		update(tree, l, r, val, start, mid, 2*i);
		update(tree, l, r, val, mid+1, end, 2*i+1);
	}
	
}

int get(snode* tree, int l, int start = 1, int end = n, int i = 1) {
	printf("start = %d ,end = %d\n",start,end);

	if (tree[i].lazy != 0) {
		if (start != end) {
		printf("old lazy = %d\n",tree[i].lazy);
		printf("propogating lazy\n");
			tree[2*i].lazy += tree[i].lazy;
			tree[2*i+1].lazy += tree[i].lazy;
			tree[i].lazy = 0;
		}
	}
	printf("new lazy = %d\n",tree[i].lazy);
	if (start == end && start == l)  
		{
	printf("returning %d\n",tree[i].lazy);	
	return tree[i].lazy;
	}
	else {
		int mid = (start + end - 1) / 2;
		if (l <= mid)
			return get(tree, l, start, mid, 2*i);
		else
			return get(tree, l, mid+1, end, 2*i+1);
	}
}

int main()
{

	int m,u,v;
	nextodd=nexteven=0;
	scanf("%d %d",&n,&m);
	tree=(node*)calloc(n+1,sizeof(node));
	odd=(int*)calloc(n+1,sizeof(int));
	even=(int*)calloc(n+1,sizeof(int));
	otree=(snode*)calloc(4*n,sizeof(snode));
	etree=(snode*)calloc(4*n,sizeof(snode));
	
	
	for(int i=1;i<=n;i++)
	scanf("%d",&tree[i].w);

	for(int i=1;i<=n-1;i++)
	{
	scanf("%d %d",&u,&v);;
	tree[u].adj.push_back(v);
	tree[v].adj.push_back(u);
	}

	dfs(0,1,-1);

	
	for(int i=1;i<=nexteven;i++)
	printf("%d ",even[i]);
	printf("\n");

	for(int i=1;i<=nextodd;i++)
	printf("%d ",odd[i]);	
	printf("\n");

	int a,x,val;
	while(m--)
{
	scanf("%d %d",&a,&x);
	switch(a)
	{
	case 1:{
		scanf("%d",&val);

		printf("beg =%d , end =%d ,cbeg =%d ,cend = %d\n",tree[x].beg,tree[x].end,tree[x].cbeg,tree[x].cend);
		printf("In Update\n");
		if(tree[x].level%2==0)
		{
			
			update(etree,tree[x].beg,tree[x].end,val);
			if(tree[x].adj.size()>1)
			{
			printf("In update\n");
			update(otree,tree[x].cbeg,tree[x].cend,-val);
			}		
		}
		else
		{
			update(otree,tree[x].beg,tree[x].end,val);
			if(tree[x].adj.size()>1)
			{
			printf("In update\n");
			update(etree,tree[x].cbeg,tree[x].cend,-val);
			}		
		}

	break;	
	}
	case 2:{
			printf("beg =%d , end =%d\n",tree[x].beg,tree[x].end);
			printf("In get\n");
			if(tree[x].level%2==0)
			printf("%d\n",tree[x].w + get(etree,tree[x].beg));
			else
			printf("%d\n",tree[x].w + get(otree,tree[x].beg));
	
		break;
	}
	}
}
free(otree);
free(etree);
free(tree);
free(odd);
free(even);
return 0;
	



}	
