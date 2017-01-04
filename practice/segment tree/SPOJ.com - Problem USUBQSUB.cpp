#include<bits/stdc++.h>
typedef long long int lli;
int n;
void updatey(lli** b,int x,int y,lli v)
{
	while(y<=n)
	{
	b[x][y]+=v;
	y+=y&-y;
	}
}

void rangeupdatey(lli** b1,lli **b2,int x,int y1, int y2,lli val)
{
		updatey(b1,x,y1,val);
		updatey(b1,x,y2+1,-val);
		updatey(b2,x,y1,(y1-1)*val);
		updatey(b2,x,y2+1,-y2*val);
}


lli gety(lli **b,int x,int y)
{
	lli ans=0;
	while(y>0)
	{
	ans+=b[x][y];
	y-=y&-y;
	}
	return ans;
}

lli rangesumy(lli** b1,lli **b2,int x,int y1,int y2)
{
	lli sy2=gety(b1,x,y2)*y2-gety(b2,x,y2);
	lli sy1=gety(b1,x,(y1-1))*(y1-1)-gety(b2,x,(y1-1));
	return sy2-sy1;

}
void updatex(lli** b1,lli** b2,int x,int y1,int y2,lli val)
{
	while(x<=n)
	{
		rangeupdatey(b1,b2,x,y1,y2,val);
		x+=x&-x;
	}
}

lli getx(lli** b1,lli **b2,int x,int y1,int y2)
{
	lli ans=0;
	while(x>0)
	{
		ans+=rangesumy(b1,b2,x,y1,y2);
		x-=x&-x;	
	}
	return ans;
}

int main()
{
	int m,c,x1,y1,x2,y2;
	lli**bit1,**bit2,**bit3,**bit4,v,sx2,sx1;

	scanf("%d %d",&n,&m);
	bit1=(lli**)calloc(n+1,sizeof(lli*));
	bit2=(lli**)calloc(n+1,sizeof(lli*));
	bit3=(lli**)calloc(n+1,sizeof(lli*));
	bit4=(lli**)calloc(n+1,sizeof(lli*));

	for(int i=1;i<=n;i++)
	{
	bit1[i]=(lli*)calloc(n+1,sizeof(lli));
	bit2[i]=(lli*)calloc(n+1,sizeof(lli));
	bit3[i]=(lli*)calloc(n+1,sizeof(lli));
	bit4[i]=(lli*)calloc(n+1,sizeof(lli));
	}

	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d %d",&c,&x1,&y1,&x2,&y2);
		if(c==2)
	{
		scanf("%lld",&v);
		updatex(bit1,bit2,x1,y1,y2,v);
		updatex(bit1,bit2,x2+1,y1,y2,-v);

		updatex(bit3,bit4,x1,y1,y2,(x1-1)*v);
		updatex(bit3,bit4,x2+1,y1,y2,-x2*v);
	}
	else
	{
		sx2=getx(bit1,bit2,x2,y1,y2)*x2-getx(bit3,bit4,x2,y1,y2);
		sx1=getx(bit1,bit2,x1-1,y1,y2)*(x1-1)-getx(bit3,bit4,x1-1,y1,y2);
		printf("%lld\n",sx2-sx1);
	}
	}
	
	for(int i=1;i<=n;i++)
	{
	free(bit1[i]);
	free(bit2[i]);
	free(bit3[i]);
	free(bit4[i]);
	}
	free(bit1);
	free(bit2);
	free(bit3);
	free(bit4);
return 0;
}
