/*
	Graham Scan
	Complexity: O(n * log(n))
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 1010

typedef struct {
	ll x;
	ll y;
} Point;

Point p0;

Point nextToTop(stack<Point> &ps) {
	Point top = ps.top();
	ps.pop();
	Point res = ps.top();
	ps.push(top);
	return res;
}

int orientation(Point a, Point b, Point c) {
	ll area = a.x * b.y - a.x * c.y + c.x * a.y
			 - b.x * a.y + b.x * c.y - c.x * b.y;
	if (area > 0) return 1;
	if (area < 0) return -1;
	return 0;
}

ll distSq(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void swap(Point &a, Point &b) {
	Point aux = a;
	a = b;
	b = aux;
}

int comparePoints(const void *a1, const void *b1) {
	Point *a = (Point *) a1;
	Point *b = (Point *) b1;
	int orient = orientation(p0, *a, *b);
	if (orient == 0) return (distSq(p0, *a) <= distSq(p0, *b)) ? -1 : 1;
	return (orient == 1) ? -1 : 1;
}

int convexHull(Point points[], int n, Point hull[]) {
	int lowerLeft = 0;
	for (int i = 1; i < n; i++) {
		if (points[i].y < points[lowerLeft].y || (points[i].y == points[lowerLeft].y && points[i].x < points[lowerLeft].x)) {
			lowerLeft = i;
		}
	}
	swap(points[lowerLeft], points[0]);

	p0 = points[0];
	qsort(&points[1], n-1, sizeof(Point), comparePoints);

	int m = 1;
	for (int i = 1; i < n; i++) {
		while (i < n - 1 && orientation(p0, points[i], points[i+1]) == 0) i++;
		points[m++] = points[i];
	}

	if (m < 3) return -1;

	stack<Point> ps;
	ps.push(points[0]);
	ps.push(points[1]);
	ps.push(points[2]);

	for (int i = 3; i < m; i++) {
		while (orientation(nextToTop(ps), ps.top(), points[i]) != 1) {
			ps.pop();
		}
		ps.push(points[i]);
	}

	int hullSize = ps.size();
	while (!ps.empty()) {
		hull[ps.size() - 1] = ps.top();
		ps.pop();
	}
	return hullSize;
}

int main() {
	int n;
	Point points[MAXN];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
	}
	Point hull[MAXN];
	int m = convexHull(points, n, hull);
	if (m == -1) cout << -1 << endl;
	else {
		for (int i = 0; i < m; i++) {
			printf("(%lld, %lld) ", hull[i].x, hull[i].y);
		}
		printf("\n");
	}
	return 0;
}
