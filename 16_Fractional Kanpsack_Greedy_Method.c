#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int weight;
    int value;
    float ratio;
} Item;

void swap(Item *a, Item *b)
{
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItemsByRatio(Item items[], int n)
{
	int i,j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

float fractionalKnapsack(int capacity, Item items[], int n)
{
    float totalValue = 0.0;
    int currentWeight = 0;

    sortItemsByRatio(items, n);
	int i;
    for (i = 0; i < n; i++)
    {
        if (currentWeight + items[i].weight <= capacity)
        {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].ratio * remainingWeight;
            break;
        }
    }

    return totalValue;
}

int main()
{
    int capacity = 50;
    Item items[] = {
        {10, 60, 0.0},
        {20, 100, 0.0},
        {30, 120, 0.0}};
    int n = sizeof(items) / sizeof(items[0]);
    int i;
    for (i = 0; i < n; i++)
    {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    float totalValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in Knapsack = %.2f\n", totalValue);

    return 0;
}
