---
title: Leetcode 56. Merge Intervals
date: 2019-01-28 21:32:25
updated: 2019-01-28 21:32:25
categories: 
- [Leetcode]
tags: Leetcode
notshow: true
top:
---

# Question

Given a collection of intervals, merge all overlapping intervals.

**Example 1:**

> **Input:** [[1,3],[2,6],[8,10],[15,18]]
> **Output:** [[1,6],[8,10],[15,18]]
> **Explanation:** Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

**Example 2:**

> **Input:** [[1,4],[4,5]]
> **Output:** [[1,5]]
> **Explanation:** Intervals [1,4] and [4,5] are considered overlapping.

**Difficulty**:Medium

**Category**:Array, Sort

<!-- more -->

------------

# Analyze

一开始,我使用两重循环的方式来解决这个问题,但是很耗时间,需要考虑使用其他的方式(solution 1).

根据博客:[花花酱 LeetCode 56. Merge Intervals](https://zxi.mytechroad.com/blog/geometry/leetcode-56-merge-intervals/)

![](/images/2019-01-29-00-12-33.png)

进行优化,先按照`start`数值的大小进行排序.

------------

# Solution

## Solution 1: 暴力枚举的方式

```cpp
// Runtime: 44ms (> 8.37%)
class Solution {
 public:
  vector<Interval> merge(vector<Interval>& vals) {
    if (vals.empty()) return {};
    for (int j = 0; j < vals.size() - 1; ++j) {
      int len = vals.size();
      for (int i = j + 1; i < vals.size(); ++i) {
        Interval& p = vals[j];
        if (max(p.start, vals[i].start) <= min(p.end, vals[i].end)) {
          p.start = min(p.start, vals[i].start);
          p.end = max(p.end, vals[i].end);
          vals.erase(vals.begin() + i);
          i--;
        }
      }
      if (vals.size() < len) --j;
    }
    return vals;
  }
};
```

## Solution 2: 先排序, Lamda function

```cpp
class Solution {
 public:
  vector<Interval> merge(vector<Interval>& vals) {
    if (vals.empty()) return {};
    sort(vals.begin(), vals.end(), [](Interval& a, Interval& b) { return a.start < b.start; });
    vector<Interval> ans{vals[0]};

    for (int i = 1; i < vals.size(); ++i) {
      if (ans.back().end < vals[i].start)
        ans.emplace_back(vals[i]);
      else
        ans.back().end = max(ans.back().end, vals[i].end);
    }
    return ans;
  }
};
```

<!-- TODO: Read some book which talk about the lamda function. -->