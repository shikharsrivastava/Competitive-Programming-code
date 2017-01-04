//12:11 - 12:23
// 30 min gone

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int f;
	int num;
};

bool so(const node &a, const node &b)
{
	if(a.f == b.f)
	return a.num < b.num;
	return a.f < b.f;
}

int main()
{
	int t;
	node *can;
	scanf("%d",&t);
	while(t--)	
	{
		can = (node*)calloc((10),sizeof(node));
		for(int i=0;i<10;i++)
		{
			can[i].num = i;
			scanf("%d",&can[i].f);
		}
		sort(can,can+10,so);
		
		if(can[0].num == 0 && can[1].f > can[0].f)
		{
			printf("1");
			for(int i=1;i<=can[0].f+1;i++)
			printf("0");
			printf("\n");
		}
		else if(can[0].num == 0 && can[1].f == can[0].f)
		{
			for(int i=1;i<=can[1].f+1;i++)
			printf("%d",can[1].num);
			printf("\n");
		}
		else
		{
			for(int i=1;i<=can[0].f+1;i++)
			printf("%d",can[0].num);
			printf("\n");
		}
		free(can);
	}
}
