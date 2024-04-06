#include <stdio.h>
int factorial(int n)
{
	int result = 1, i;
	for (i = n; i > 0; i--) {
		result *= i;
	}
	return result;
}
int main()
{
	int num = 5;
	printf("Factorial of %d is %d", num, factorial(num));
	return 0;
}
