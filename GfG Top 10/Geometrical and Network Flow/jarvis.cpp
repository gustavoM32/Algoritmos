/*
    Jarvis’s Algorithm
    Complexity: O(m * n)
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 1010

typedef struct {
    ll x;
    ll y;
} Point;

bool onSegment(Point a, Point b, Point c) {
    return (min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x));
}

int orientation(Point a, Point b, Point c) {
    ll area = a.x * b.y - a.x * c.y + c.x * a.y
             - b.x * a.y + b.x * c.y - c.x * b.y;
    if (area > 0) return 1;
    if (area < 0) return -1;
    return 0;
}

int convexHull(Point points[], int n, int hull[]) {
    int cur, m;
    m = 0;
    cur = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[cur].x) cur = i;
    }
    do {
        hull[m++] = cur;
        cur = (cur + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[hull[m-1]], points[cur], points[i]) == 1) cur = i;
        }
    } while (cur != hull[0]);
    return m;
}

int main() {
    Point points[MAXN];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    int m;
    int hull[MAXN];
    m = convexHull(points, n, hull);
    for (int i = 0; i < m; i++) {
        printf("(%lld, %lld) ", points[hull[i]].x, points[hull[i]].y);
    }
    cout << "\n";
    return 0;
}
