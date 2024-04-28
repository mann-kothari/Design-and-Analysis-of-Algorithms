#include <stdio.h>

#define n 4
#define MAX 10000

int dist[n + 1][n + 1] = {
    {0, 0, 0, 0, 0},
    {0, 0, 10, 15, 20},
    {0, 10, 0, 25, 25},
    {0, 15, 25, 0, 30},
    {0, 20, 25, 30, 0},
};

int memo[n + 1][1 << (n + 1)];

int min(int a, int b) { return a < b ? a : b; }

int fun(int i, int mask)
{
	int j;
    if (mask == ((1 << i) | 3))
        return dist[1][i];

    if (memo[i][mask] != 0)
        return memo[i][mask];

    int res = MAX;

    for (j = 1; j <= n; j++)
        if ((mask & (1 << j)) && j != i && j != 1)
            res = min(res, fun(j, mask & (~(1 << i))) + dist[j][i]);
    return memo[i][mask] = res;
}

int main()
{
    int ans = MAX;
    int i;
    for (i = 1; i <= n; i++)
        ans = min(ans, fun(i, (1 << (n + 1)) - 1) + dist[i][1]);

    printf("The cost of most efficient tour = %d", ans);

    return 0;
}
