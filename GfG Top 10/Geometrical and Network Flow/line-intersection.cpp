/*
    Line intersection
    Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef struct {
    ll x;
    ll y;
} Point;

typedef struct {
    Point a;
    Point b;
} Segment;

bool onSegment(Segment s, Point p) {
    return (min(s.a.x, s.b.x) <= p.x && p.x <= max(s.a.x, s.b.x));
}

int orientation(Point a, Point b, Point c) {
    ll area = a.x * b.y - a.x * c.y + c.x * a.y
             - b.x * a.y + b.x * c.y - c.x * b.y;
    if (area > 0) return 1;
    if (area < 0) return -1;
    return 0;
}

bool intersection(Segment p, Segment q) {
    int o1 = orientation(p.a, p.b, q.a);
    int o2 = orientation(p.a, p.b, q.b);
    int o3 = orientation(q.a, q.b, p.a);
    int o4 = orientation(q.a, q.b, p.b);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(p, q.a)) return true;
    if (o2 == 0 && onSegment(p, q.b)) return true;
    if (o3 == 0 && onSegment(q, p.a)) return true;
    if (o4 == 0 && onSegment(q, p.b)) return true;
    return false;
}

int main() {
    Segment p, q;
    cin >> p.a.x >> p.a.y >> p.b.x >> p.b.y;
    cin >> q.a.x >> q.a.y >> q.b.x >> q.b.y;
    cout << intersection(p, q) << endl;
    return 0;
}
