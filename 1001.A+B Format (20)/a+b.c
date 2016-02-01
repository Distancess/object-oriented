#include<stdio.h>
int main()
{
	int a,b;
	int i,j,sum; 
	int s[30];
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		sum=a+b;
		if(sum==0) printf("%d\n",sum);
		else
		{
		    if(sum<0) 
		    {
			    sum=-sum;printf("-");
		    }
		    for(i=1;sum!=0;i++,sum=sum/10) s[i]=sum%10;
		    printf("%d",s[i-1]);
		    for(j=i-2;j>0;j--)
		    {
			    if(j%3==0) printf(",");
		        printf("%d",s[j]);
		    }
		    printf("\n");
	    }
	}
} 
