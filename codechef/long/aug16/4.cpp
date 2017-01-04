//13:48
#include<bits/stdc++.h>
using namespace std;
#define INF -1000000007
int h[15],s[15],st,en;
void printrange(int st,int en)
{
	printf("%d ",st);
	if(en == INF)
	printf("Inf\n");
	else
	printf("%d\n",en);
}
bool checkinc(int i)
{
		bool f = true;
		if(s[i] == s[i+1])
		{
			if(h[i+1] <= h[i])
			f = false;
		}
		else if(s[i+1] > s[i])
		{
			int tm = floor(((double)h[i]-h[i+1])/(s[i+1]-s[i])) + 1;
			st = max(st,tm);
		}
		else
		{
			if(h[i+1] > h[i])
			{
				int tm = ceil(((double)h[i]-h[i+1])/(s[i+1]-s[i])) - 1;
				if(en == INF)
				en = tm;
				else
				en = min(tm,en);
			}
			else
			f = false;	
		}
	//printrange();
	if(!f)	
	return f;
	else if(en != INF && en <st)
	return false;
	else
	return true;
	
}

bool checkdec(int i)
{
	bool f = true;
	if(s[i] == s[i+1])
	{
		if(h[i+1]>= h[i])
		f = false;
	}
	else if(s[i+1] > s[i])
	{
		if(h[i+1] < h[i])
		{
			int tm = ceil(((double)h[i]-h[i+1])/(s[i+1]-s[i])) - 1;
			if(en == INF)
			en = tm;
			else
			en = min(en,tm);
		}
		else
		f = false;
	}
	else
	{
		if(h[i+1] >= h[i])
		{
			int tm = floor(((double)h[i]-h[i+1])/(s[i+1]-s[i])) + 1;
			st = max(st,tm);
		}
	}
	//printrange();
	if(!f)
	return f;
	else if(en != INF && en <st)
	return false;
	else
	return true;
	
}
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int ans,st1,st2,en1,en2;
		for(int i=1;i<=n;i++)
			scanf("%d %d",&h[i],&s[i]);
		if(n == 1)
		{printf("1\n0 Inf\n");continue;}
		// increasing
		st = st1 = st2 = en1 = en2 = 0 , en = INF;
		bool f1 = true, f2 = true;
		ans = 0;
		for(int i=1;i<n;i++)
		{
			if(i%2 != 0)
					{if(!checkinc(i))
					{f1 = false ; break;}}
			else
				{if(!checkdec(i))
					{f1 = false ; break;}}
		}
		if(f1)
		{ans++ , st1=st,en1=en;}
		// decreasing
		st = 0 , en = INF;
		for(int i=1;i<n;i++)
		{
			if(i%2 == 0)
					{if(!checkinc(i))
					{f2 = false ; break;}}
			else
				{if(!checkdec(i))
					{f2 = false ; break;}}
		}
		if(f2)
		{ans++,st2=st,en2=en;}

		if(f1 && f2)
		{
			if(st1 < st2)
			{
				if(en1 == st2 -1)
				{
					printf("1\n");
					printrange(st1,en2);
				}
				else
				{
					printf("2\n");
					printrange(st1,en1);
					printrange(st2,en2);
				}
			}
			else
			{
				if(en2 == st1-1)
				{
					printf("1\n");
					printrange(st2,en1);
				}
				else
				{
					printf("2\n");			
					printrange(st2,en2);
					printrange(st1,en1);
				}
			}
		}
		else if(f1)
		{printf("1\n");printrange(st1,en1);}
		else if(f2)
		{printf("1\n");printrange(st2,en2);}
		else
		printf("0\n");
	}
}
