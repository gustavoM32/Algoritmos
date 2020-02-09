/*
    Tries
    Complexity: O()
*/
#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

typedef struct node Node;

struct node {
    Node *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

Node *getNode() {
    Node *node = new Node;
    for (int i = 0; i < ALPHABET_SIZE; i++) node->children[i] = NULL;
    node->isEndOfWord = false;
    return node;
}

void insert(Node *trie, string key) {
    Node *curNode = trie;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (curNode->children[index] == NULL) {
            curNode->children[index] = getNode();
        }
        curNode = curNode->children[index];
    }
    curNode->isEndOfWord = true;
}

bool search(Node *trie, string key) {
    Node *curNode = trie;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (curNode->children[index] == NULL) return false;
        curNode = curNode->children[index];
    }
    if (curNode->isEndOfWord) return true;
}

int main() {
    Node *root = getNode();
    int n;
    cin >> n;
    while (n--) {
        string key;
        cin >> key;
        insert(root, key);
    }
    int m;
    cin >> m;
    while (m--) {
        string key;
        cin >> key;
        cout << search(root, key) << "\n";
    }
    return 0;
}
