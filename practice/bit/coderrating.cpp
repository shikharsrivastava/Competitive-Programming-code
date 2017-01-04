/*
	First sort the ratings based on any one rating (in this case open rating (a))
	
	Update the ratings in other competetion (in thid case high cschool rating (h)) for this person in the bit by 1

	As we move in the sorted alist , at any position i

	Since all the coders ahead in the list are cannot be below the ith coder (as th a value is greater) 
	Only candidates are the coders before it in the sorted list , i.e. that are processed

	Out of the candidates the answer is the number of coders whose rating in (h) is below the rating in (h) of the ith coder (current coder)
	
	WE CAN DO THIS EASILY BY GETTING THE SUM IN BIT
	
	For ith coder in sorted list
   
	Case 1: rating[coder i].h is == 0 in bit , i.e that position is not set till now		
	It means this is the first coder in the sorted list to have this rating in h,
	We can find the answer easily by getting the sum in the bit i.e ans = sum(rating[coder i].h -1) = sum(rating[coder i].h) as positon rating[coder i].h is == 0 		in bit it will give us the number of coders which we have processed and have the ratings in h less than that of our current coder (ith coder) 

	Case 1 formula used 	ans =sum(rating[coder i].h) 

	Case 2:rating[coder i].h is > 0 in bit , i.e that position is already set in bt by someone
	
	2.a)  If is greater then 0 , it means that any coder j such that j<i also had that rating ,
	      but since j<i => we have to count coder j also for i's answer, so in this case ans = sum(rating[coder i]);

		formula ->1 -----used ans = sum(rating[coder i])

	2.b)  But if Two coders i-1 and i have exactly same ratings , rating[coder i].h is > 0 but we have to take sum till- > ans=sum(rating[coder i].h-1)
	      
		formula ->2 ---- used ans=sum(rating[coder i].h-1)

		Therfore just two formuales in two cases
		
		If i'th and i-1'th coders have all ratings same we use formuala ->2
		else we use formula ->1

		:) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) 
*/

#include<bits/stdc++.h>
using namespace std;

struct rating
{
	int a;
	int h;
	int id;
};

bool so(const rating x,const rating y)
{
	if(x.a==y.a)
	return x.h<y.h;
	return x.a<y.a;
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
	void reset(int s)
	{
		free(b);
		n=s;
		b=(int*)calloc(n+1,sizeof(int));
	}

	void update(int pos,int v=1)
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
	int n,*ans;
	rating *r,x;
	bit b(100000);
	int idx;
	scanf("%d",&n);
	
	r=(rating*)calloc(n+1,sizeof(rating));
	ans=(int*)calloc(n+1,sizeof(int));
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&r[i].a,&r[i].h);
		r[i].id=i;	
	}

	sort(r+1,r+n+1,so);
	int i=1;
	while(i<=n)
	{
		x=r[i];
		idx=i;
		while(i<=n && x.a == r[i].a && x.h == r[i].h)
		ans[r[i].id]=b.sum(r[i].h),i+=1;
		
		i=idx;
		while(i<=n && x.a == r[i].a && x.h == r[i].h)
		{b.update(r[i].h);i+=1;}
	}
	
	
	
	for(int i=1;i<=n;i++)
	printf("%d\n",ans[i]);
	
	free(ans);
	free(r);

}
