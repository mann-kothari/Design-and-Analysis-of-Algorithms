#include <stdio.h>
#include <limits.>
#define INT_MAX 100
int sum(int freq[], int i, int j)
{
	int s = 0;
	int k;
	for (k = i; k <=j; k++)
	s += freq[k];
	return s;
}

int optCost(int freq[], int i, int j){
	if (j < i)
		return 0;
	if (j == i)
		return freq[i];

	int fsum = sum(freq, i, j);

	int min = INT_MAX;
	int r;
	for (r = i; r <= j; ++r)
	{
		int cost = optCost(freq, i, r-1) + 
					optCost(freq, r+1, j);
		if (cost < min)
			min = cost;
	}

	return min + fsum;
}

int optimalSearchTree(int keys[], int freq[], int n)
{
	return optCost(freq, 0, n-1);
}

int main()
{
	int keys[] = {10, 12, 20};
	int freq[] = {34, 8, 50};
	int n = sizeof(keys)/sizeof(keys[0]);
	printf("Cost of Optimal BST is %d ", 
			optimalSearchTree(keys, freq, n));
	return 0;
}

