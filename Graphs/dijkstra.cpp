/*
    Dijkstra’s shortest path algorithm
    Complexity: O(edges * log(vertices))
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

vector<pair<int, int>> adj[MAXN];
int dists[MAXN];

void dijkstra(int root) {
    set<pair<int, int>> toCheck;
    toCheck.insert(make_pair(0, root));
    while (!toCheck.empty()) {
        int curNode = (*toCheck.begin()).second;
        int curDist = (*toCheck.begin()).first;
        toCheck.erase(*toCheck.begin());
        if (dists[curNode] != -1) continue;
        dists[curNode] = curDist;
        for (auto it = adj[curNode].begin(); it != adj[curNode].end(); it++) {
            int adjNode = (*it).first;
            if (dists[adjNode] != -1) continue;
            int adjWeight = (*it).second;
            toCheck.insert(make_pair(curDist + adjWeight, adjNode));
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    for (int i = 0; i < edges; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
    }
    memset(dists, -1, sizeof dists);
    dijkstra(1);
    for (int i = 1; i <= vertices; i++) {
        cout << "1 to " << i << ": "<< (dists[i]) << endl;
    }
    return 0;
}
