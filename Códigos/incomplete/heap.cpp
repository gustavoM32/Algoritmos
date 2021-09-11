#include <iostream>
#include <queue>
#include <set>
#include <climits>

using namespace std;

struct Node {
    int value;
    Node *left, *right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class MinHeap {
    Node *root;

    public:
    MinHeap() : root(nullptr) {}

    Node *merge(Node *a, Node *b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        if (a->value > b->value) swap(a, b);
        if (rand() % 2) swap(a->left, a->right);
        a->right = merge(b, a->right);
        return a;
    }

    void push(int val) {
        root = merge(root, new Node(val));
    }

    int top() {
        if (root == nullptr) return INT_MAX;
        return root->value;
    }

    void pop() {
        Node *old = root;
        root = merge(root->left, root->right);
        delete old;
    }
};

int main() {
    //MinHeap a;
    //priority_queue<int> a;
    multiset<int> a;
    vector<int> v;

    const int N = 1000000;
    for (int i = 0; i < N; i++) v.push_back(rand() % 10000);

    for (int i = 0; i < N; i++) {
        //a.push(v[i]);
        a.insert(v[i]);
    }
    for (int i = 0; i < N; i++) {
        //a.pop();
        a.erase(a.begin());
    }
}
