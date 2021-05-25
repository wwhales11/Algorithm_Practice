#include<stdio.h> 
#include <math.h>


int main() 
{ 
	int n, i;
	long long unsigned a = 0,  b = 1, c; 

	printf("Enter the number of terms\n"); 
	scanf("%d",&n); 

	printf("First %d terms of Fibonacci series are :-\n",n); 

	for ( i = 1 ; i < n ; i++ ) 
	{ 
		if ( i <= 1 ) 
			c = i; 
		else 
		{ 
			c = a + b; 
			a = b; 
			b = c; 
		} 
		printf("%llu\n",c); 
	} 

	return 0; 
} 
