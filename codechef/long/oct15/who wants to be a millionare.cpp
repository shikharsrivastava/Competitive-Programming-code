#include<cstdio>
#include<cstdlib>

int main()
{
int t,n,max_ans,answer;
int* marks;
char* chef,*ans;
scanf("%d",&t);
while(t--)
{
max_ans=answer=0;
scanf("%d",&n);
chef=(char*)calloc(n+1,sizeof(char));
ans=(char*)calloc(n+1,sizeof(char));
marks=(int*)calloc(n+2,sizeof(int));
scanf("%s",ans);
scanf("%s",chef);

for(int i=0;i<n;i++)
{
if(ans[i]==chef[i])
max_ans++;
}
for(int i=0;i<n+1;i++)
scanf("%d",&marks[i]);

if(max_ans==n)
printf("%d\n",marks[n]);
else
{
for(int i=0;i<=max_ans;i++)
{
if(marks[i]>answer)
answer=marks[i];
}
printf("%d\n",answer);
}
free(chef);
free(ans);
free(marks);
}
return 0;
}
