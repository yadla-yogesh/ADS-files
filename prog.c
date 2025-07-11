#include<stdio.h>

int main()
{
	int a;
	printf("enter a number\n");
	scanf("%d",&a);
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
