/*
    Suffix Array
    Complexity: O(n * log(n) * log(n))
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

typedef struct suffix Suffix;

struct suffix {
    int index;
    int rank[2];
};

bool cmp(Suffix a, Suffix b) {
    return (a.rank[0] == b.rank[0]) ? (a.rank[1] == b.rank[1] ? (a.index > b.index) : (a.rank[1] < b.rank[1])) : (a.rank[0] < b.rank[0]);  
}

int *buildSuffixArray(char *txt, int n) {
    Suffix suffixes[MAXN];
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = (i + 1 < n) ? (txt[i+1] - 'a') : -1;
    }

    sort(suffixes, suffixes+n, cmp);

    int ind[MAXN];

    for (int k = 4; k < 2*n; k *= 2) {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1]) {
                suffixes[i].rank[0] = rank;
            } else {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[0].index] = 0;
        }
        for (int i = 0; i < n; i++) {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n) ? suffixes[ind[nextindex]].rank[0] : -1;
        }
        sort(suffixes, suffixes+n, cmp);
    }

    int *suffixArray = new int[n];
    for (int i = 0; i < n; i++) {
        suffixArray[i] = suffixes[i].index;
    }
    return suffixArray;
}

void printArr(char *txt, int arr[], int n) { 
    for (int i = 0; i < n; i++) {
		char c;
		for (int j = 0; (c = txt[arr[i] + j]) != '\0'; j++)
        	cout << c;
		cout << "\n";
	}
} 

int main() {
    char txt[MAXN];
    cin >> txt; 
    int n = strlen(txt); 
    int *suffixArr = buildSuffixArray(txt, n); 
    printArr(txt, suffixArr, n); 
    return 0;
}
