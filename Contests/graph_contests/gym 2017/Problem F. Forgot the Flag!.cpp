//
// Created by ahmed on 05/07/2023.
//
#pragma GCC optimization("Ofast")
// #pragma GCC target("popcnt")

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <iterator> // for iterators
#include <queue>
#include <cmath>
#include <complex>
#include <iomanip>

const double PI = acos(-1.0);

using namespace std;
typedef long long ll;
typedef vector<vector<int>> matrix;
typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a, b)                ((b)-(a))
#define same(p1, p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a, b)                 ( (conj(a)*(b)).real() )    // a*b cos(T), if zero -> prep
#define cp(a, b)                 ( (conj(a)*(b)).imag() )    // a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p, ang)          ((p)*exp(point(0,ang)))
#define rotateA(p, ang, about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v, m)  (conj((v)/(m))*(m))
#define EPS 1e-8
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);


point reflect(point p, point p0, point p1) {
    point z = p - p0, w = p1 - p0;
    return conj(z / w) * w + p0; // Reflect point p1 around p0p1
}

double fixAngle(double A) {
    return A > 1 ? 1 : (A < -1 ? -1 : A);
}

// return min angle: aOb / bOa
// dp(v1, v2) = |v1|*|v2|*cos(theta)
double angleO(point a, point O, point b) {
    point v1(a - O), v2(b - O);
    return acos(fixAngle(dp(v1, v2) / length(v1) / length(v2)));
}

point ternery(point left, point right, point p1, point p2) {
    for (int i = 0; i < 100; ++i) {
        point g = (1 - (1 / 3.0)) * left + (1 / 3.0) * right;
        point h = (1 - (2 / 3.0)) * left + (2 / 3.0) * right;

        if (length(g - p1) + length(g - p2) < length(h - p1) + length(h - p2)) {
            right = h;
        } else {
            left = g;
        }
    }
    return right;
}

int main() {
    freopen("flags.in", "r", stdin);
    FIO;
//    double d = length(point(4, 3));
//    cout << d << endl;
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n = 0, Q = 0;
        cin >> n;
        vector<point> points;
        long double x = 0, y = 0;
        cin >> x >> y;
        point point_0(x, y);
        points.push_back(point_0);
        for (int j = 1; j < n; j++) {
            long double x = 0, y = 0;
            cin >> x >> y;
            points.push_back(point(x, y));
        }
        points.push_back(point_0);
        cin >> Q;
        cout << "Case " << i + 1 << ":\n";
        for (int j = 0; j < Q; j++) {
            long double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            long double minLen = 1e18;
            point finalP;
            for (int k = 0; k < n; k++) {
                point start = points[k];
                point end = points[k + 1];
                point res = ternery(start, end, point(x1, y1), point(x2, y2));
                long double len = length(res - point(x1, y1)) + length(res - point(x2, y2));
                if (len < minLen) {
                    finalP = res;
                    minLen = len;
                }
            }
            std::cout << std::setprecision(7) << std::fixed;
            cout << minLen << " " << finalP.X << " " << finalP.Y << "\n";
        }
    }
    return 0;
}
