#include<stdio.h>
long my_pow1(long x,int n)
{
	if(n==0) return 1;

	return x*my_pow1(x,n-1);
}

int main()
{
	long  x;
	int  n;
	scanf("%ld%d",&x,&n);

	printf("%ld\n",my_pow1(x,n));
	return 0;
} 
