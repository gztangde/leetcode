---
title: K Nearest Points
date: 2019-03-08 23:38:22
updated: 2019-03-08 23:38:22
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# K Nearest Points (K closest points to origin)


```cpp
// K-Nearest Points
// 时间复杂度：O(NlogK)
// 空间复杂度： O(K)
struct Point {
  double x;
  double y;
  Point(double _x, double _y) : x(_x), y(_y) {}
};

double squaredDistance(Point a, Point b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }
typedef bool (*cmp)(Point, Point);
Point global_origin = Point(0, 0);
bool compare(Point a, Point b) { return squaredDistance(a, global_origin) < squaredDistance(b, global_origin); }

vector<Point> kNearestPoint(vector<Point> points, Point origin, int k) {
  global_origin = origin;
  priority_queue<Point, vector<Point>, cmp> pq(compare);
  for (int i = 0; i < points.size(); i++) {
    pq.push(points[i]);
    if (i >= k) pq.pop();
  }
  vector<Point> res;
  for (int i = 0; i < k; i++) {
    res.push_back(pq.top());
    pq.pop();
  }
  return res;
}
```