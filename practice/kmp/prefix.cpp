#include<bits/stdc++.h>

int main()
{
	char *s=(char*)calloc(10000,sizeof(char));
	scanf("%s",s);
	
	int *prefix=(int*)calloc(strlen(s)+1,sizeof(int));

	for(int i=1;i<strlen(s);i++)
	{
		int j=prefix[i-1];
		while(j>0 && s[j] !=s[i])
		j=prefix[j-1];
		if(s[i]==s[j])
		++j;
		prefix[i]=j;
		printf("%d ",prefix[i]);
	}

	printf("\nPrefix function calculated\n");

}
