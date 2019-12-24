/*
    Union-find
    Complexity: O(log (n)) per operation
*/
#include <bits/stdc++.h>
using namespace std;

#define V 110

typedef struct {
    int rank;
    int parent;
} Subset;

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int a = find(subsets, x);
    int b = find(subsets, y);
    if (subsets[a].rank < subsets[b].rank) {
        subsets[a].parent = b;
    } else if (subsets[a].rank > subsets[b].rank) {
        subsets[b].parent = a;
    } else {
        subsets[b].parent = a;
        subsets[a].rank++;
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<int> adjs[V];
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adjs[a].push_back(b);
    }
    Subset subsets[V];
    for (int i = 0; i < v; i++) {
        subsets[i].rank = 0;
        subsets[i].parent = i;
    }
    bool cyclic = false;
    for (int i = 0; i < v && !cyclic; i++) {
        for (int j = 0; j < adjs[i].size() && !cyclic; j++) {
            int curSub = find(subsets, i);
            int adjSub = find(subsets, adjs[i][j]);
            if (curSub == adjSub) {
                cout << "achei " << i << " " << adjs[i][j] << endl;
                cyclic = true;
            } else {
                Union(subsets, curSub, adjSub);
            }
        }
    }
    if (cyclic) cout << "Graph has cycle\n";
    else cout << "Graph has no cycle\n";
    return 0;
}
