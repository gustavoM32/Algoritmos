/*
	k Dimensional Tree
	Complexity: O()
*/
#include <bits/stdc++.h>
using namespace std;

#define K 2
#define MAXN 10010

typedef struct node Node;

struct node {
	int point[K];
	Node *left, *right;
};

Node *newNode(int point[]) {
	Node *node = new Node;
	for (int i = 0; i < K; i++) node->point[i] = point[i];
	node->left = node->right = NULL;
	return node;
}

Node *insertRec(Node *root, int point[], int depth) {
	if (root == NULL)
		return newNode(point);

	int dm = depth % K;

	if (point[dm] < root->point[dm])
		root->left = insertRec(root->left, point, depth+1);
	else
		root->right = insertRec(root->right, point, depth+1);
	return root;
}

Node *insert(Node *root, int point[]) {
	return insertRec(root, point, 0);
}

bool arePointsEqual(int a[], int b[]) {
	for (int i = 0; i < K; i++)
		if (a[i] != b[i]) return false;
	return true;
}

bool searchRec(Node *root, int point[], int depth) {
	if (root == NULL)
		return false;
	if (arePointsEqual(root->point, point))
		return true;

	int dm = depth % K;

	if (point[dm] < root->point[dm])
		return searchRec(root->left, point, depth+1);
	else
		return searchRec(root->right, point, depth+1);
}

bool search(Node *root, int point[]) {
	return searchRec(root, point, 0);
}

int main() {
	Node *root = NULL; 
	int n;
	cin >> n;
	while (n--) {
		int point[K];
		for (int i = 0; i < K; i++) {
			cin >> point[i];
		}
		root = insert(root, point);
	}

	int m;
	cin >> m;
	while (m--) {
		int point[K];
		for (int i = 0; i < K; i++) {
			cin >> point[i];
		}
		(search(root, point)) ? cout << "Found\n": cout << "Not Found\n"; 
	}
	return 0;
}
