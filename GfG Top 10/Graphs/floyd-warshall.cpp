/*
    Floyd Warshall Algorithm
    Complexity: O(vertices^3)
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 110
#define INF 1000000000

int graph[MAXN][MAXN];
int dists[MAXN][MAXN];

void floyd(int vertices) {
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            dists[i][j] = graph[i][j];
        }
    }

    for (int k = 1; k <= vertices; k++) {
        for (int s = 1; s <= vertices; s++) {
            for (int e = 1; e <= vertices; e++) {
                if (dists[s][k] + dists[k][e] < dists[s][e]) {
                    dists[s][e] = dists[s][k] + dists[k][e];
                }
            }
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }

        }
    }
    for (int i = 0; i < edges; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = w;
    }
    floyd(vertices);
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            cout << i << " to " << j << ": " << dists[i][j] << endl;
        }
    }
    return 0;
}
