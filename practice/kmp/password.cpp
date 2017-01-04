//15:34

#include<bits/stdc++.h>
using namespace std;
/*Calculate prefix function of s in pre*/
void calpre(int *pre,string s)
{
	int n=s.length();
	for(int i=1;i<n;i++)
	{
		int j=pre[i-1];
		while(j>0 && s[j]!=s[i])
		j=pre[j-1];
		if(s[j]==s[i])
		++j;
		pre[i]=j;
	}

}

/*Function to find if the pattern patt exists in the string s*/
bool find(string &patt,string &s)
{
	int *pre=(int*)calloc(patt.length()+1,sizeof(int));
	calpre(pre,patt);
	int n=s.length();
	int j=0;
	for(int i=0;i<n;i++)
	{
		while(j>0 && patt[j] !=s[i])
		j=pre[j-1];

		if(patt[j]==s[i])
		++j;
		if(j==patt.length())
		{
		free(pre);
		return true;
		}
	}
	free(pre);
	return false;
}
int main()
{
	string s;
	cin>>s;
	int n=s.length()-1;
	if(n<2)
	printf("Just a legend\n");
	else
{
	int *pre=(int*)calloc(s.length()+1,sizeof(int));
	calpre(pre,s);

	vector<int> l;


	/*Pushes all the prefix that are also suffix of string s in list l in descending order*/
	while(pre[n]>0)
	{
		l.push_back(pre[n]);
		n=pre[n]-1;	
	}

	string s2=s.substr(1,s.length()-2);
	string temp;
	int st=0,e=l.size()-1,m;
	int mx=0;
	/*Longest answer is found through Binary search in the lsit which is in descending order of prefix sufix lengths*/
	while(st<=e)
	{
		m=(st+e)/2;
		temp=s.substr(0,l[m]);/*prefix of length l[m] i.e string temp is searched in s2*/
		if(find(temp,s2))
		{
		mx=max(mx,l[m]);
		e=m-1;
		}
		else
		st=m+1;
	}
	if(mx==0)
	printf("Just a legend\n");
	else
	cout<<s.substr(0,mx)<<endl;
	free(pre);
}
}

