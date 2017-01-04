#include<bits/stdc++.h>
using namespace std;
#define MARK(num,i) ( (i ? (num = num | ( 1<<(i-1) ) ) : 0 ) )
#define GET(num,i) ((num >> (i-1)) & 1)
#define GD(num,i) ( i ? (num | (1<<(i-1)) ) : num)

/*
	using the property of MOD
	that we can determine the number of single digit factors of x if we know x % M , M = LCM(1,2,3,4...9)
	single digit factors of x and x % M are all same
*/

typedef long long int lli;
int kvalue[512][2520];
int modval[10][2520];
/* calculates the length of number*/
int DIGIT(lli num)
{
	if(num == 0)
	return 1;
	int ret = 0;
	while(num >0)
	ret++ , num/=10;
	return ret;
}
/* stores the digits of number in vector*/
void getdigits(vector<int> & v,lli num)
{
	while(num>0)
	v.push_back(num%10) , num/= 10;
	reverse(v.begin(),v.end());
}
/* get max k value i.e max number of distinct digits that are both present in num and divides num
   gives k value for bitmask , remainder pair
*/
int getK(int st,int v)
{
	int ret  = 0;
	for(int i=1;i<=9;i++)
		if(GET(st,i) && v%i == 0)
			ret++;
			return ret;
}


void precompute()
{
	int bmod = 10 % 2520;
	for(int i=1;i<=511;i++)
		for(int rem = 0;rem<2520;rem++)
			kvalue[i][rem] = getK(i,rem); 
	for(int dig=0;dig<=9;dig++)
		for(int rem=0;rem<2520;rem++)
			modval[dig][rem] = (rem*bmod + dig)%2520;
		
}
/* DP tables , storing bitmask , remainder pairs*/
lli gmod[512][2520] , dgmod[512][2520]; // for num1
lli gmod2[512][2520] , dgmod2[512][2520]; // for num2

/*
	if num1 is d1 digits long and num2 is d2 digits long
	then getk returns number of d1 digits k special numbers strictly less than num1 in ans1
	and		  number of d2 digits k special numbers less than or equal to num2 in ans2


	i.e ans1 = number of k special numbers in ranage [10^(d1-1) , num1)
	    ans2 = number of k special numbers in range [10^(d2-1) , num2]
*/

void getk(lli num1,lli num2,int k,lli &ans1 , lli &ans2)
{
	int l1 = DIGIT(num1),l2 = DIGIT(num2);
	vector<int> d1,d2;
	getdigits(d1,num1) , getdigits(d2,num2);

	int currdigit1 = d1[0] , currdigit2 = d2[0];
	int currset1 = 0 , currset2 = 0;

	MARK(currset1,currdigit1); MARK(currset2,currdigit2);
	/*initialising the tables*/
	for(int i=1;i<=511;i++)
			for(int j=0;j<2520;j++)
				gmod[i][j] = dgmod[i][j] = gmod2[i][j] = dgmod2[i][j] = 0;

	/*setting tables for single digit numbers*/
	for(int i=1;i<=9;i++)
			if(i < currdigit1)
				gmod[(1<<(i-1))][i] = 1;
	for(int i=1;i<=9;i++)
			if(i < currdigit2)
				gmod2[(1<<(i-1))][i] = 1;


	int bmod = 10 % 2520;
	int eqmod1 = currdigit1 % 2520 , eqmod2 = currdigit2 % 2520;
	ans1 = 0 , ans2 = 0;

	bool done[3] = {false,false,false};
	
	if(l1 == 1)
	{
		for(int i=1;i<=511;i++)
			for(int j=0;j<2520;j++)
				if(kvalue[i][j] >= k)
					ans1 += gmod[i][j];
		done[1] = true;
	}

	if(l2 == 1)
	{
		for(int i=1;i<=511;i++)
			for(int j=0;j<2520;j++)
				if(kvalue[i][j] >= k)
					ans2 += gmod2[i][j];
		if(kvalue[currset2][eqmod2] >=k)
		ans2 +=1;
		done[2] = true;
	}

	
	int to,nmod;

	/* Going till length l1 and updating both tables*/

	for(int len = 2;len<=l1;len++)
	{
		currdigit1 = d1[len-1];
		currdigit2 = d2[len-1];
		for(int digit = 0 ;digit <=9 ;digit++)
		{
			for(int from = 1;from<=511;from++)
			{	
				for(int md = 0;md <2520;md++)
				{
					to = GD(from,digit);
					nmod = modval[digit][md];
					dgmod[to][nmod] += gmod[from][md];
					dgmod2[to][nmod] += gmod2[from][md];
				}
			}
			if(digit < currdigit1)
			{
				to = GD(currset1,digit);
				nmod = modval[digit][eqmod1];
				dgmod[to][nmod] += 1;
			}
			if(digit < currdigit2)
			{
				to = GD(currset2,digit);
				nmod = modval[digit][eqmod2];
				dgmod2[to][nmod] += 1;
			}

		}
		eqmod1 = modval[currdigit1][eqmod1];
		eqmod2 = modval[currdigit2][eqmod2];
		MARK(currset1,currdigit1);
		MARK(currset2,currdigit2);
		/* swapping tables*/
		for(int i=1;i<=511;i++)
			for(int j=0;j<2520;j++)
				gmod[i][j] = dgmod[i][j] , gmod2[i][j] = dgmod2[i][j] , dgmod[i][j] = dgmod2[i][j] = 0;
	}
	
	/*After length l1 updating only the second table as ans for l1 is done*/
	for(int len=l1+1;len<=l2;len++)
	{
		currdigit2 = d2[len-1];
		for(int digit = 0 ;digit <=9 ;digit++)
		{
			for(int from = 1;from<=511;from++)
			{	
				for(int md = 0;md <2520;md++)
				{
					to = GD(from,digit);
					nmod = modval[digit][md];
					dgmod2[to][nmod] += gmod2[from][md];
				}
			}

			if(digit < currdigit2)
			{
				to = GD(currset2,digit);
				nmod = modval[digit][eqmod2];
				dgmod2[to][nmod] += 1;
			}

		}
		eqmod2 = modval[currdigit2][eqmod2];
		MARK(currset2,currdigit2);

		for(int i=1;i<=511;i++)
			for(int j=0;j<2520;j++)
				gmod2[i][j] = dgmod2[i][j] ,dgmod2[i][j] = 0;
	}
	/*calculating answers*/
	
	if(!done[1]){
	for(int i=1;i<=511;i++)
		for(int j=0;j<2520;j++)
			if(kvalue[i][j] >= k)
				ans1 += gmod[i][j];
		
	}
	if(!done[2]){
	for(int i=1;i<=511;i++)
		for(int j=0;j<2520;j++)
			if(kvalue[i][j] >= k)
				ans2 += gmod2[i][j];
		/*checking for equality i.e if num2 is k special*/
		if(kvalue[currset2][eqmod2] >= k)
		ans2 += 1;
	}
	
}


int main()
{
	precompute();
	/* This table stores the total number of k special numbers in all numbers of d digits
	kval[d][k] = number of k special numbers of length d	
	*/
	lli kvals[19][10] = {{0,0,0,0,0,0,0,0,0,0},
			     {9,9,0,0,0,0,0,0,0,0},
			     {90,59,5,0,0,0,0,0,0,0},
			     {900,640,175,30,0,0,0,0,0,0},
			     {9000,6870,2644,574,67,0,0,0,0,0},
			     {90000,72374,33007,9677,1720,84,0,0,0,0},
			     {900000,752554,382306,134643,32607,3996,248,0,0,0},
			     {9000000,7753077,4250033,1694752,502769,93047,9483,105,0,0},
			     {90000000,79358834,46049697,20056375,6862390,1625805,227889,9110,0,0},
			     {900000000,808508575,490293790,228073131,86597306,24235196,4281784,321067,7199,0},
			     {9000000000,8208509756,5155278261,2522883639,1036887307,326403213,69536703,7173152,250369,11460},
			     {90000000000,83117472265,53706649381,27355149271,11962872224,4112583984,1011387905,130455136,6382062,166804},
			     {900000000000,839890645550,555579296788,292205351803,134321195048,49438916260,13591165295,2076153559,129800495,2689336},
			     {9000000000000,8473074138944,5715875036866,3085748993530,1477607039573,574098062067,172396879969,30076886515,2259032102,52286220},
			   {90000000000000,85366135457703,58550216325558,32295494846849,15998955336888,6493690863967,2094088568001,406603457499,35252704401,971926914},
	   {900000000000000,859136469673701,597651602682369,335605119320260,171076354956930,71967730696235,24602665205238,5215945715172,507649365727,16290631536},
{9000000000000000,8638781294063548,6083010868463192,3467511308935990,1811021016016792,784830565223073,281575319282572,64235916723687,6874243802202,249350284884},
			     {90000000000000000,86800266698796437,61766720523146026,35658800607172773,19015196180807000,8448518906721307,3155903819441803,765865374838382,88698503913949,3552616040075},
			     {900000000000000000,871604238619217379,625928558568697983,365283751683629689,198310454938660467,89989965119503750,34777503541312697,8895451302215582,1101093003474519,47835158330548}
			     };

	lli num1,num2,ans1,ans2;
	int k,t,d1,d2,f;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%lld %lld%d",&num1,&num2,&k);
	d1 = DIGIT(num1);
	d2 = DIGIT(num2);
	if(d1 == d2)
	{
		getk(num1,num2,k,ans1,ans2);
		printf("%lld\n",ans2-ans1);
	}
	else
	{
		getk(num1,num2,k,ans1,ans2);
		ans1 = kvals[d1][k] - ans1;
		lli total = 0;
		/*for numbers of length [d1+1,d2-1] , using precalculated tables*/
		for(int d=d1+1;d<d2;d++)
		total += kvals[d][k];

		printf("%lld\n",ans1+ans2+total);	
	}
	}
}
