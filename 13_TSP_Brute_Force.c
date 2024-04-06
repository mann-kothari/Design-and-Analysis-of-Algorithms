#include <stdio.h>
#include <limits.h>
#define V 4

int next_permutation(int arr[], int size)
{
    int i = size - 1;
    while (i > 0 && arr[i - 1] >= arr[i])
    {
        i--;
    }
    if (i <= 0)
    {
        return 0;
    }
    int j = size - 1;
    while (arr[j] <= arr[i - 1])
    {
        j--;
    }
    int temp = arr[i - 1];
    arr[i - 1] = arr[j];
    arr[j] = temp;
    j = size - 1;
    while (i < j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    return 1;
}

int travllingSalesmanProblem(int graph[][V], int s)
{
    int vertex[V - 1];
    for (int i = 0, k = 0; i < V; i++)
    {
        if (i != s)
        {
            vertex[k] = i;
            k++;
        }
    }
    int min_path = INT_MAX;
    do
    {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < V - 1; i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        if (current_pathweight < min_path)
        {
            min_path = current_pathweight;
        }
    } while (next_permutation(vertex, V - 1));
    return min_path;
}

int main()
{
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int s = 0;
    printf("The optimal cost is: %d\n", travllingSalesmanProblem(graph, s));
    return 0;
}