#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXH 100010

using namespace std;

struct Point {
    int x, y;
};

bool operator<(Point &a, Point &b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
};

Point pivot;

int n, q, p;
int i;
int maxa, maxb;
int a, b;
double ans;
int N;

int isCCW(Point a, Point b, Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

int sqrDist(Point a, Point b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool POLAR_ORDER(Point a, Point b)  {
    int order = isCCW(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}

vector<Point> grahamScan(Point *points, int N)    {
    vector <Point> hull;
    
    if (N < 3)
        return hull;
    
    int leastY = 0;
    for (int i = 1; i < N; i++)
        if (points[i] < points[leastY])
            leastY = i;
    
    swap(points[0], points[leastY]);
    
    pivot = points[0];
    sort(points + 1, points + N, POLAR_ORDER);
    
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);
    
    for (int i = 3; i < N; i++) {
        Point peek = hull.back();
        hull.pop_back();
        while (isCCW(hull.back(), peek, points[i]) != -1)   {
            peek = hull.back();
            hull.pop_back();
        }
        hull.push_back(peek);
        hull.push_back(points[i]);
    }
    return hull;
}

void find(Point p, Point q) {
    
}

int main()  {
    Point points[MAXH];

    scanf("%d %d %d", &n, &p, &q);
    for (i = 0;i < n;i ++) {
        scanf("%d %d", &a, &b);
        points[i] = {a, b};
        if(a > maxa) maxa = a;
        if(b > maxb) maxb = b;
    }
    points[n] = {maxa, 0};
    points[n + 1] = {0, maxb};
    if (q == 0) {
        printf("%.20f\n", p * 1.0 / maxa);
    } else if (p == 0) {
        printf("%.20f\n", q * 1.0 / maxb);
    } else {
        N = n + 2;
        vector<Point> hull = grahamScan(points, N);
        Point origin = {0, 0};
        Point term = {p, q};
        for(int i = 0;i < hull.size();i ++) {
            tmp = find(hull[i], hull[i + 1]);
        }
    }
    return 0;
}

