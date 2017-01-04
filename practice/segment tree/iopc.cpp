#include<bits/stdc++.h>
typedef long long int lli;

struct node
{
	int lazy;
	int red;
	
};
node *tx,*ty,*tz;

void invert(node* t,int l,int r,int s,int e,int i=1)
{
	
	if(t[i].lazy %2==1)
	{
		t[i].red=(e-s+1)-t[i].red;
		if(s!=e)
		{
			t[i*2].lazy+=t[i].lazy;
			t[i*2+1].lazy+=t[i].lazy;
		}
	}
	t[i].lazy=0;

	if(s>r || e<l)
		return;

	if(s>=l && e<=r)
	{
		t[i].red=(e-s+1)-t[i].red;
		if(s!=e)
		{
			t[i*2].lazy+=1;
			t[i*2+1].lazy+=1;
		}
	
		return;
	}

	int mid=(e+s)/2;
	invert(t,l,r,s,mid,i*2);
	invert(t,l,r,mid+1,e,i*2+1);

	t[i].red=t[i*2].red+t[i*2+1].red;
	return ;
}

int query(node *t, int l,int r,int s,int e,int i=1)
{
	
	if(t[i].lazy %2==1)
	{
		t[i].red=(e-s+1)-t[i].red;
		if(s!=e)
		{
			t[i*2].lazy+=t[i].lazy;
			t[i*2+1].lazy+=t[i].lazy;
		}
	}
	t[i].lazy=0;

	if(s>r || e<l)
	return 0;
	
	
	if(s>=l && e<=r)
	return t[i].red;


	int mid=(e+s)/2;
	return query(t,l,r,s,mid,i*2)+query(t,l,r,mid+1,e,i*2+1);
	
}

int main()
{
	int nx,ny,nz,t,q,x1,y1,z1,x2,y2,z2,i,j,c,count=1;
	lli ansx,ansy,ansp,ans,dx,dy,dz;
	scanf("%d",&t);

	while(t--){

	scanf("%d %d %d %d",&nx,&ny,&nz,&q);
	tx=(node*)calloc(4*nx,sizeof(node));
	ty=(node*)calloc(4*ny,sizeof(node));
	tz=(node*)calloc(4*nz,sizeof(node));

	while(q--){
		
		
		scanf("%d",&c);
		if(c==0){
			scanf("%d %d",&i,&j);
			invert(tx,i,j,0,nx-1);
		}
		else if(c==1){
			scanf("%d %d",&i,&j);
			invert(ty,i,j,0,ny-1);
		}
		else if(c==2){
			scanf("%d %d",&i,&j);
			invert(tz,i,j,0,nz-1);
		}
		else{
			scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
			ans=0;
			dx=query(tx,x1,x2,0,nx-1); //individual contribution of x axis
			dy=query(ty,y1,y2,0,ny-1); //individual contribution of y axis
			dz=query(tz,z1,z2,0,nz-1); //individual contribution of z axis
			ansx=dx*(y2-y1+1);
			ansy=dy*(x2-x1+1);	//distributions is uniform throughout the axis if we consider only one axix
			ansp=ansx+ansy-2*(dx*dy);// answer for a plane formed of x1,x2,ya,y2
			ans=ansp*(z2-z1+1-dz) +((lli)(x2-x1+1)*(y2-y1+1)-ansp)*dz;//Extending to z axix
			printf("%lld\n",ans);
		}	
					
		}
		free(tx);
		free(ty);
		free(tz);
		}	
}
