#include <stdio.h>
int linear_search(int a[], int n, int x)
{
    int i, flag = 0, index;
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            flag = 1;
            index = i;
        }
    }
    if (flag == 1)
        printf("%d is present in the array at index %d\n", x, index);
    else
        printf("%d is not present in the array \n", x);
    return 0;
}

void main()
{
    int arr[10], i, n = 10, x;
    printf("Enter the array values\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value to be searched\n");
    scanf("%d", &x);
    linear_search(arr, n, x);
}