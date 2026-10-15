
#include <iostream>
using namespace std;

int main() {
    int n;
    int graph[10][10];
    int key[10], parent[10];
    bool mst[10] = {false};
    int totalCost = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    for (int i = 0; i < n; i++) {
        key[i] = 9999;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;
        int minKey = 9999;

        for (int v = 0; v < n; v++) {
            if (!mst[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        if (u == -1) {
            cout << "Graph is disconnected.\n";
            return 0;
        }

        mst[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 &&
                !mst[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nEdge\tWeight\n";

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - "
             << i << "\t" << key[i] << "\n";
        totalCost += key[i];
    }

    cout << "Total minimum cost = "
         << totalCost << endl;

    return 0;
}
