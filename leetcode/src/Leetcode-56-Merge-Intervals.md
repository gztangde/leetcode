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

# Leetcode 56. Merge Intervals

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

# Analyze

一开始,我使用两重循环的方式来解决这个问题,但是很耗时间,需要考虑使用其他的方式(solution 1).

根据博客:[花花酱 LeetCode 56. Merge Intervals](https://zxi.mytechroad.com/blog/geometry/leetcode-56-merge-intervals/)

![](/images/2019-01-29-00-12-33.png)

进行优化,先按照`start`数值的大小进行排序.

# Solution

## Solution 1: 暴力枚举的方式

Time complexity: O(n^2)
Space complexity: O(n)

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

我们首先给`区间集排序`，由于我们要排序的是个结构体，所以我们要定义自己的`comparator`，才能用sort来排序，我们以 start 的值从小到大来排序，排完序我们就可以开始合并了，首先把第一个区间存入结果中，然后从第二个开始遍历区间集，`如果结果中最后一个区间和遍历的当前区间无重叠`，直接将当前区间存入结果中，如果有重叠，将结果中最后一个区间的 end值更新为结果中最后一个区间的end和当前end值之中的较大值，然后继续遍历区间集，以此类推可以得到最终结果

Time complexity: O(n log n)
Space complexity: O(n)

```cpp
class Solution {
 public:
  vector<Interval> merge(vector<Interval>& vals) {
    if (vals.empty()) return {};
    sort(vals.begin(), vals.end(), [](Interval& a, Interval& b) { return a.start < b.start; });
    vector<Interval> ans{vals[0]};

    for (int i = 1; i < vals.size(); ++i) {
      // If the next one don't overlap with the prev one
      if (ans.back().end < vals[i].start)
        ans.emplace_back(vals[i]);
      else
        ans.back().end = max(ans.back().end, vals[i].end);
    }
    return ans;
  }
};
```