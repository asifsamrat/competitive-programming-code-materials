#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld PI = acosl(-1.0L);

struct Point {
    ld x, y;
};

// Distance between two points
ld dist(Point a, Point b) {
    return hypotl(a.x - b.x, a.y - b.y);
}

// Area of triangle formed by three points
ld triangleArea(Point a, Point b, Point c) {
    return fabsl(
        a.x * (b.y - c.y) +
        b.x * (c.y - a.y) +
        c.x * (a.y - b.y)
    ) / 2.0L;
}

// Radius of the circumcircle
ld circumradius(Point a, Point b, Point c) {
    ld A = dist(b, c);
    ld B = dist(a, c);
    ld C = dist(a, b);

    ld area = triangleArea(a, b, c);

    return (A * B * C) / (4.0L * area);
}

// Circumference of the circumcircle
ld circumference(Point a, Point b, Point c) {
    return 2.0L * PI * circumradius(a, b, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Point a, b, c;

    while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y) {
        cout << fixed << setprecision(2) << circumference(a, b, c) << '\n';
    }

    return 0;
}
