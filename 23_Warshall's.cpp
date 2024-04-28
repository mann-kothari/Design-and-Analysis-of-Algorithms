#include <iostream>
using namespace std;

#define V 4 // Number of vertices in the graph

void printMatrix(int reach[][V]) {
	int i,j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }
}

void transitiveClosure(int graph[][V]) {
    int reach[V][V];
	int i,j,k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            reach[i][j] = graph[i][j];

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printMatrix(reach);
}

int main() {
    int graph[V][V] = { {0, 1, 0, 0},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0},
                        {1, 0, 1, 0} };

    transitiveClosure(graph);
    return 0;
}
