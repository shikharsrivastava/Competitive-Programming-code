#include<stdio.h>
#include<stdlib.h>

struct ARR
{
int x;
int y;
};

int main()
{
int t,n,x,y,i,maxx,maxxpos,minxpos,minx,maxy,maxypos,minypos,miny,urposx,lrposx,ulposx,llposx,urposy,lrposy,ulposy,llposy;
struct ARR *a;
scanf("%d",&t);
while(t--)
{
maxx=-1000000000;maxy=-1000000000;minx=1000000000;miny=1000000000;
scanf("%d",&n);
a=(struct ARR*)calloc(n+1,sizeof(struct ARR));
for(i=1;i<=n;i++)
{
scanf("%d %d",&a[i].x,&a[i].y);
if(a[i].x>maxx)
{
maxx=a[i].x;
maxxpos=i;
urposx=i;
lrposx=i;
}
else if(a[i].x==maxx)
{
if(a[i].y>=maxy)
urposx=i;
else if(a[i].y<=miny)
lrposx=i;
}
if(a[i].x<minx)
{
minx=a[i].x;
minxpos=i;
ulposx=llposx=i;
}
else if(a[i].x==minx)
{
if(a[i].y>=maxy)
ulposx=i;
else if(a[i].y<=miny)
llposx=i;
}

if(a[i].y>maxy)
{
maxy=a[i].y;
maxypos=i;
urposy=ulposy=i;
}
else if(a[i].y==maxy)
{
if(a[i].x>=maxx)
urposy=i;
else if(a[i].x<=minx)
ulposy=i;
}

if(a[i].y<miny)
{
miny=a[i].y;
minypos=i;
lrposy=llposy=i;
}
else if(a[i].y==miny)
{
if(a[i].x>=maxx)
lrposy=i;
else if(a[i].x<=minx)
llposy=i;
}

}//for end
//printf("urposx = %d ,urposy =%d ,lrposx =%d ,lrposy=%d ulposx=%d ,ulposy=%d ,llposx=%d ,llposy=%d\n",urposx,urposy,lrposx,lrposy,ulposx,ulposy,llposx,llposy);
if(minx==maxx)
{
printf("1\n");
printf("%d SE\n",maxypos);
continue;
}
else if(miny==maxy)
{
printf("1\n");
printf("%d NE\n",minxpos);
continue;
}
else if(lrposx==lrposy)
{
printf("1\n");
printf("%d NW\n",lrposx);
continue;
} 
else if(urposx==urposy)
{
printf("1\n");
printf("%d SW\n",urposx);
continue;
} 
else if(llposx==llposy)
{
printf("1\n");
printf("%d NE\n",llposx);
continue;
} 
else if(ulposx==ulposy)
{
printf("1\n");
printf("%d SE\n",ulposx);
continue;
} 
else
{
printf("2\n");
if(a[maxypos].x >a[minypos].x)
{
printf("%d SW\n",maxypos);
printf("%d NE\n",minypos);
}
else
{
printf("%d SE\n",maxypos);
printf("%d NW\n",minypos);
}
}

free(a);
}// while end

}
