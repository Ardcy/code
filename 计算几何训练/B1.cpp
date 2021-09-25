#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
typedef double db;
const db eps = 1e-10;  
const db pi = acos(-1.0);  
const ll inf = 0x3f3f3f3f3f3f3f3f;  
const ll maxn = 1e3 + 10;

inline int dcmp(db x) {
    if(fabs(x) < eps) return 0;
    return x > 0? 1: -1;
}

class Point {
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    bool operator<(const Point &a) const {
        return (!dcmp(x - a.x))? dcmp(y - a.y) < 0: x < a.x;
    }
    bool operator==(const Point &a) const {
        return dcmp(x - a.x) == 0 && dcmp(y - a.y) == 0;
    }
    db dis2(const Point a) {
        return pow(x - a.x, 2) + pow(y - a.y, 2);
    }
    db dis(const Point a) {
        return sqrt(dis2(a));
    }

    db dis2() {
        return x * x + y * y;
    }
    db dis() {
        return sqrt(dis2());
    }
    Point operator+(const Point a) {
        return Point(x + a.x, y + a.y);
    }
    Point operator-(const Point a) {
        return Point(x - a.x, y - a.y);
    }
    Point operator*(double p) {
        return Point(x * p, y * p);
    }
    Point operator/(double p) {
        return Point(x / p, y / p);
    }
    db dot(const Point a) {
        return x * a.x + y * a.y;
    }
    db cross(const Point a) {
        return x * a.y - y * a.x;
    }
};
typedef Point Vector;

class Line {
public:
    Point s, e;
    Line() {}
    Line(Point s, Point e) : s(s), e(e) {}
    void input() {
        scanf("%lf%lf%lf%lf", &s.x, &s.y, &e.x, &e.y);
    }
    int toLeftTest(Point p) {
        if((e - s).cross(p - s) > 0) return 1;
        else if((e - s).cross(p - s) < 0) return -1;
        return 0;
    }
};
Line line[maxn];
Point point[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            line[i].input();
            point[i * 2] = line[i].s;
            point[i * 2 + 1] = line[i].e;
        }
        if(n < 3) {
            printf("Yes!\n");
            continue;
        }
        int fg = 0;
        for(int i = 0; i < 2 * n; ++i) {
            for(int j = i + 1; j < 2 * n; ++j) {
                if(point[i] == point[j]) continue;
                Line l = Line(point[i], point[j]);
                int flag = 1;
                for(int k = 0; k < n; ++k) {
                    if(l.toLeftTest(line[k].s) + l.toLeftTest(line[k].e) && l.toLeftTest(line[k].s) == l.toLeftTest(line[k].e)) {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1) {
                    printf("Yes!\n");
                    fg = 1;
                    break;
                }
            }
            if(fg == 1) {break;}
        }
        if(!fg) {
            printf("No!\n");
        }
    }
    return 0;
}