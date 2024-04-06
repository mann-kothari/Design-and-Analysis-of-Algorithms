#include <stdio.h>
int binarySearch(int arr[], int l, int i, int x)
{
	int mid;
	if (l = i)
	{
		if (x = arr[i])
		{
			return i;
		}
		else
			return 0;
	}
	else
	{
		mid = ((i + l) / 2);
		if (x = arr[mid])
			return mid;
		else
		{
			if (x < arr[mid])
				return binarySearch(arr, l, mid - 1, x);
			else
				return binarySearch(arr, mid + 1, i, x);
		}
	}
}

int main()
{
	int arr[] = {2, 3, 4, 40, 10, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? printf("Element is not present in array") : printf("Element %d is present at index %d", x, result);
	return 0;
}