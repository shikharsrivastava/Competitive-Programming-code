//9:42
#include<bits/stdc++.h>
using namespace std;

/*Using Deque to find the maximum in every subarray of size ln in array a and storing it in array mx*/
void findmin(vector<int> &a,vector<int> &mx,int ln)
{
	mx.clear();
	deque<int> q(ln+1);
	int i;
	for(i=0;i<ln;i++)
	{
		while(!q.empty() && a[i] >= a[q.back()])
		q.pop_back();
		q.push_back(i);
	}
	mx.push_back(a[q.front()]);

	for(;i<a.size();i++)
	{
		while(!q.empty() && q.front() <= i-ln)
		q.pop_front();
		while(!q.empty() && a[i] >= a[q.back()])
		q.pop_back();
		q.push_back(i);
		mx.push_back(a[q.front()]);
	}	
}

void findsum(vector<int> &a, vector<int> &sm,int ln)
{
	sm.clear();
	int s = 0;
	int st = 0 , en = 0;
	for(;en<ln;en++)
	s+=a[en];
	sm.push_back(s);

	for(;en<a.size();en++,st++)
	{
		s+=a[en];
		s-=a[st];
		sm.push_back(s);
	}
}
int main()
{
	int n,m,q,elem,a,b;
	scanf("%d %d",&n,&m);
	
	vector<vector<int> > row(1001);
	vector<vector<int> > column(1001);
	vector<vector<int> > columnmax(1001);
	vector<vector<int> > columnsum(1001);

	// find rowsum and columnsum
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<m;j++)
		{
			scanf("%d",&elem);
			row[i].push_back(elem);
			column[j].push_back(elem);
		}
	}
	scanf("%d",&q);
	int ans;
	while(q--)
	{
		ans = 1000000002;
		scanf("%d %d",&a,&b);

	/*Compressing all submatrices in array , each column of submatrice is converted to a sinle number in the array*/
	/*There are two arrays , one is sum which contains sum of all elements of the column in the submatrix*/
	/*Other is max which contains the maximum of all elements in the column*/

	/*
		Therefore all submatrices of axb starting in row 0 are compressed in columnsum[0..m][0] and columnmax[0..m][0] respectively
			  all submatrices of axb starting in row 1 are compressed in columnsum[0..m][1] and columnmax[0..m][1] respectively and so on for row 2...n
	*/
		for(int i=0;i<m;i++)
			{findmin(column[i],columnmax[i],a);findsum(column[i],columnsum[i],a);}

		for(int r=0;r+a<=n;r++)
		{

		/*
			Applying the same algorithm of finding maximum for all subarrays of length a using dequq in all compressed arrays to find maximuum in 				corresponding submatrix , and using columnsum to find sum of submatrix effectively.
		*/
			deque<int> qu(n+1);
			int c,s=0,st=0,mx;
			for(c=0;c<b;c++)
			{
				s+=columnsum[c][r];
				while(!qu.empty() && columnmax[c][r] >=columnmax[qu.back()][r])
				qu.pop_back();
				qu.push_back(c);
			}
			mx = columnmax[qu.front()][r];
			ans = min(ans,a*b*mx - s);
	
			for(;c<m;c++,st++)
			{

				s += columnsum[c][r];
				s -= columnsum[st][r];
				while(!qu.empty() && qu.front() <= c-b)
				qu.pop_front();
				while(!qu.empty() && columnmax[c][r] >= columnmax[qu.back()][r])
				qu.pop_back();
				qu.push_back(c);
				mx = columnmax[qu.front()][r];
				ans = min(ans,a*b*mx - s);

			}			
		}
		printf("%d\n",ans);
	}
	return 0;
}	
