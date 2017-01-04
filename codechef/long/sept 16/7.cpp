    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int lli;
     
    int n,p;
    lli rowsum[501],colsum[501];
    int mat[2][501][501];
    bool hash[501];
    lli sumval[501];

	 void genrandom(bool *hashr)
    {
    	
    	memset(hashr,false,sizeof(hash));
    	hashr[n] = true;	
    	int pos = (rand()%(n-1)) + 1;
    	for(int i=1;i<p;i++)
    	{
    		while(hashr[pos])
    			pos = (rand()%(n-1)) +1 ;
    		hashr[pos] = true;	
    	}
     
    	/*for(int i=1;i<n;i++)
    		if(hash[i])
    			printf("%d ",i);
    	printf("\n");*/
    }


	lli getans(bool*hashrow,bool* hashcol)
    {
    	lli ans = -LLONG_MAX;
    	memset(sumval,0,sizeof(sumval));
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1,ind = 1;j<=n;j++)
    		{
    			sumval[ind] += mat[0][i][j];
    			if(hashcol[j])
    				ind++;
    		}
    		if(hashrow[i])
    		{
    			for(int j=1;j<=p;j++)
    			{
    				//printf("%lld ",sumval[j]);
    				ans = max(ans,sumval[j]);
    				sumval[j] = 0;
    			}
    			//printf("\n");
    		}
    	}
    	//printf("%lld\n",ans);
    	return ans;
    }
     
    bool canmake(lli *arr,lli k)
    {
    	memset(hash,0,sizeof(hash));
    	int done = 0;
    	lli sum = 0;
    	for(int i=1;i<=n;i++)
    	{
    		sum += arr[i];	
    		if(sum >k)
    		{
    			done++;
    			i--;
    			if(hash[i])
    				return false;
    			hash[i] = true;
    			sum = 0;
    		}
    	}		
    	if(done <= p-1)
    		return true;
    	else 
    		return false;
    }
     
    void makehash(lli *arr,lli k)
    {
    	memset(hash,0,sizeof(hash));
    	lli sum = 0;
    	int done;
    	for(int i=1;i<=n;i++)
    	{
    		sum += arr[i];	
    		if(sum >k || p-1-done > n-i)
    		{
    			done++;
    			i--;
    			hash[i] = true;
    			sum = 0;
    		}
    	}		
    	
    }
     
    void makeblockhash(lli k,bool *anshash,bool trnsp = false)
    {
    	memset(hash,false,sizeof(hash));
    	memset(sumval,0,sizeof(sumval));
    	int done = 0;
    	for(int i=1;i<=n;i++)
    	{
    		bool f = true;
    		int ind = 1;
    		for(int j=1;j<=n;j++)
    		{
    			sumval[ind] += mat[trnsp][i][j];
    			if(sumval[ind] > k || p-1-done > n-i)
    			{f = false;break;}
    			if(anshash[j])
    				ind++;
    		}
    		if(!f)
    		{
    			done++;
    			i--;
    			hash[i] = true;
    			for(int j=1;j<=p;j++)
    				sumval[j] = 0;
    		}
    	}
    	
    }
    bool canmakeblock(lli k,bool *anshash,bool trnsp = false)
    {
    	memset(hash,0,sizeof(hash));
    	memset(sumval,0,sizeof(sumval));	
    	int done = 0;
    	for(int i=1;i<=n;i++)
    	{
    		bool f = true;
    		int ind = 1;
    		for(int j=1;j<=n;j++)
    		{
    			
    			sumval[ind] += mat[trnsp][i][j];
    			if(sumval[ind] > k)
    			{f = false;break;}
    			if(anshash[j])
    				ind++;
    		}
    		if(!f)
    		{
    			i--;
    			done++;
    			if(hash[i])
    				return false;
    			hash[i] = true;
    			for(int j=1;j<=p;j++)
    				sumval[j] = 0;
    		}
    	}
     
    	if(done <=p-1)
    		return true;
    	
    	return false;
    }
    int main()
    {
		srand(time(NULL));
    	lli totsum = 0 , totrow = 0 , totcol = 0 ;
    	int ansid;
    	scanf("%d %d",&n,&p);
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<=n;j++)
    			{scanf("%d",&mat[0][i][j]);mat[1][j][i] = mat[0][i][j];}
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<=n;j++)
    			rowsum[i] += mat[0][i][j] , colsum[j] += mat[0][i][j] , totsum += mat[0][i][j];
     
    	// first for colsum
    	lli s = 1 , e = totsum;
    	while(s<e)
    	{
    		lli m = (s+e)>>1;
    		if(canmake(colsum,m))
    		e = m;
    		else
    		s = m+1;
    	}
     
    	
    	makehash(colsum,s);
     
    	bool vertical[2][501];
     
    	for(int i=1;i<=n;i++)
    		vertical[0][i] = hash[i];
    	
    	s = 1, e = totsum;
    	while(s<e)
    	{
    		lli m = (s+e)>>1;
    		if(canmakeblock(m,vertical[0]))
    			e = m;
    		else
    			s = m+1;
    	}
    	lli mn = s;
    	makeblockhash(s,vertical[0]);
     
     
    	bool horizontal[2][501];
    	for(int i=1;i<=n;i++)
    			horizontal[0][i] = hash[i];
     
    	// first row
    	s = 1, e = totsum;	
    	while(s<e)
    	{
    		lli m = (s+e)>>1;
    		if(canmake(rowsum,m))
    		e = m;
    		else
    		s = m+1;
    	}
    	makehash(rowsum,s);
    	for(int i=1;i<=n;i++)
    			horizontal[1][i] = hash[i];
     
    	s = 1, e = totsum;
    	while(s<e)
    	{
    		lli m = (s+e)>>1;
    		if(canmakeblock(m,horizontal[1],true))
    			e = m;
    		else
    			s = m+1;
    	}
    	makeblockhash(s,horizontal[1],true);
    	for(int i=1;i<=n;i++)
    			vertical[1][i] = hash[i];
	if(s<mn)
	{	for(int i=1;i<=n;i++)
			vertical[0][i] = vertical[1][i] , horizontal[0][i] = horizontal[1][i];
		mn = s;
	}
     
	bool hashrow[501],hashcol[501];
	for(int i=1;i<=1500;i++)
    	{
    		genrandom(hashrow);
    		genrandom(hashcol);
    		lli tmp = getans(hashrow,hashcol);
    		//printf("\n");
    		if(tmp < mn)
    		{
    			for(int j=1;j<=n;j++)
    				horizontal[0][j] = hashrow[j] , vertical[0][j] = hashcol[j];
    			mn = tmp;
    		}
			tmp = getans(hashcol,hashrow);
			if(tmp < mn)
    		{
    			for(int j=1;j<=n;j++)
    				horizontal[0][j] = hashcol[j] , vertical[0][j] = hashrow[j];
    			mn = tmp;
    		}
    		
    	}	

    	ansid = 0;
    	
    	
    	for(int i=1;i<=n;i++)
    		if(horizontal[ansid][i])
    			printf("%d ",i);
    	printf("\n");
    	for(int i=1;i<=n;i++)
    		if(vertical[ansid][i])
    			printf("%d ",i);
    	printf("\n");
    	
    	return 0;
    } 
