#include <stdio.h>
#include <limits.h>

#define N 4 // Number of workers and jobs

int minCost = INT_MAX;
int minAssignment[N];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void findMinCost(int costMatrix[N][N], int cost, int assigned[], int index)
{
    if (index == N)
    {
        if (cost < minCost)
        {
            minCost = cost;
            for (int i = 0; i < N; i++)
            {
                minAssignment[i] = assigned[i];
            }
        }
        return;
    }

    for (int i = index; i < N; i++)
    {
        swap(&assigned[index], &assigned[i]);
        findMinCost(costMatrix, cost + costMatrix[index][assigned[index]], assigned, index + 1);
        swap(&assigned[index], &assigned[i]);
    }
}

int main()
{
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}};
    int assigned[N];
    for (int i = 0; i < N; i++)
    {
        assigned[i] = i;
    }

    findMinCost(costMatrix, 0, assigned, 0);

    printf("Minimum cost: %d\n", minCost);
    printf("Assignment: ");
    for (int i = 0; i < N; i++)
    {
        printf("(%d, %d) ", i + 1, minAssignment[i] + 1);
    }
    printf("\n");

    return 0;
}
