#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;
bool f2;
typedef long long lli;
typedef double db;
char s[200005];
set<int> rst;
int roundpos,decpos,n;
bool f;
void add(int id)
{
	f = f2 = false;
	int carry = 1;
	for(int i=id;i>=0;i--)
	{	
		if(i == decpos)
			continue;
		int num = s[i]-'0';
		int newnum = num+carry;
		
			carry = newnum/10 , s[i] = '0'+(newnum%10);

		if(s[i] >='5' && s[i] <= '9')
			{roundpos = i-1, f= true;}
		if(roundpos == decpos)
			{roundpos--;f2 = true;}
		if(!carry)
			break;
	}
	/*for(int i=1;i<=n;i++)
		printf("%c",s[i]);
	printf("\n");*/
}

int main()
{
	int t;
	scanf("%d %d",&n,&t);
	f = false;
	scanf("%s",s+1);
	s[0] = '0';

	for(int i=1;i<=n;i++)
		if(s[i] == '.')
		{decpos = i;break;}
	
	for(int i=decpos+1;i<=n;i++)
		if(s[i] >= '5' && s[i] <= '9')
			{
				if(i-1 == decpos)
				i--;
				roundpos = i-1 , f = true;break;
			}
	
	while(f && t)
	{
		t--;
		
		s[roundpos+1] = '#';
		add(roundpos);

		if(t && (roundpos < decpos) && f2)
		{
			s[roundpos+1] = '#';
			add(roundpos);
			s[decpos] = '#';
			break;
		}
		if(!t || roundpos < decpos)
			break;
		
	}
	
	if(s[0] >'0' && s[0] <= '9')
		printf("%c",s[0]);
	f = false;
	for(int i=1;i<decpos;i++)
	{
		if(f)
			printf("0");
		else if(s[i] == '#')
		{printf("0"); f = true;}
		else
		printf("%c",s[i]);
	}
	if(!f && s[decpos] != '#')
	{
		printf(".");
		for(int i=decpos+1;i<=n && s[i] != '#';i++)
		printf("%c",s[i]);
	}
	printf("\n");
	
	
	return 0;
}
