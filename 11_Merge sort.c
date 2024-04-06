#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int a[MAX_SIZE], b[MAX_SIZE];
void Merge(int low, int mid, int high)
{
    int h = low, i = low, j = mid + 1;
    int k;
    while ((h <= mid) && (j <= high))
    {
        if (a[h] <= a[j])
        {
            b[i] = a[h];
            h += 1;
        }
        else
        {
            b[i] = b[j];
            j += 1;
        }
        i += 1;
    }
    if (h > mid)
    {
        for (k = j; k <= high; k++)
        {
            b[i] = a[k];
            i += 1;
        }
    }
    else
    {
        for (k = h; k <= mid; k++)
        {
            b[i] = a[k];
            i += 1;
        }
    }
    for (k = low; k <= high; k++)
    {
        a[k] = b[k];
    }
}

void MergeSort(int low, int high)
{
    int mid = 0;
    if (low < high)
    {
        mid = ((low + high) / 2);
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        Merge(low, mid, high);
    }
}

int main()
{
    int n,i;
    printf("Enter array size\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elemnts");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    MergeSort(0, n - 1);
    printf("The sorted array is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
