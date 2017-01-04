/*
	First sort all process according to burst time then according to id 
	
	Mark a bit with all positions as 1

	rc = cycle count , stores how many times we have cycled throught the que of process , i.e how many time we have done -1 from all process in queue
	time = total time passed from begining to completion of cycle deleting the p[i-1] process
	num = number of processes in the queue
	c= count of processes deleted / to be deleted before processing of next different process
	
	Initially rc=0,num=n,time=0.

	The smallest process will finish after p[1].bt loops or cycles		
	therefore execution time for the smallest process = num * p[1].bt - (number of process ahead of p[1] in queue)
	We can easily get number of process ahead any process using bit
	
	-> after this process completes , this proces has to be removed so b.update(p[i].id,-1)
	-> Now if the next process in sorted list is equal to the current process , that process is ahead the current process in queue and will
	   also complete in this cycle only , so all variables , time,num,rc are same for it but c++;
 
	-> if the next process is not equal to the current one
	  
	   time for p[i+1] , time = total time taken to complete rc cycles , because after that p[i] will be deleted and cycle will begin from
	   start of the queue again
		So base time for p[i+1]
		* time = time + num*(p[i]-rc) ------- time + time taken to complete p[i] ----- time + (number of process left)*(number of cycles left of p[i])
		* cycle count rc = p[i].bt for process p[i+1]
		* now since process p[i] is deleted num=num-c
		* c=1
	       
	
	 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct pro
{
	lli bt;
	int id;
};
bool so(const pro a, const pro b)
{	
		if(a.bt==b.bt)
		return a.id<b.id;
		return a.bt<b.bt;
}

struct bit
{
	int *b;
	int n;
	bit(int s)
	{
		n=s;
		b=(int*)calloc(n+1,sizeof(int));
	}
	void update(int pos,int v)
	{
		while(pos<=n)
		{
			b[pos]+=v;
			pos+=pos &-pos;
		}
	}
	int sum(int pos)
	{
		int ans=0;
		while(pos>0)
		{
		ans+=b[pos];
		pos-=pos &-pos;
		}
		return ans;
	}
};
int main()
{
	int n,num;
	lli time,rc;
	scanf("%d",&n);
	bit b(n);
	pro x;
	num=n;
	pro *p=(pro*)calloc(n+1,sizeof(pro));
	lli *ans=(lli*)calloc(n+1,sizeof(lli));
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i].bt);
		p[i].id=i;	
	}
	for(int i=1;i<=n;i++)
	b.update(i,1);
	
	sort(p+1,p+n+1,so);
	time=rc=0;
	int i=1,idx;
	num=n;
	while(i<=n)
	{
	idx=i;
	x=p[i];
	// To do use the same formula without any change for all process having same burst time
	while(i<=n && (p[i].bt == x.bt))
	{	
		ans[p[i].id]=time+num*(p[i].bt-rc)-(b.sum(n)-b.sum(p[i].id));
		i++;
	}
	i=idx;
	while(i<=n && (p[i].bt == x.bt))
	{	
		b.update(p[i].id,-1);
		i++;	
	}	
	time+=num*(p[idx].bt-rc);
	rc=p[idx].bt;
	num-=(i-idx);
	}
	for(int i=1;i<=n;i++)
	printf("%lld\n",ans[i]);
		
}
