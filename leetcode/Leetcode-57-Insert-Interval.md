---
title: Leetcode 57. Insert Interval
date: 2019-02-01 00:33:15
updated: 2019-02-01 00:33:15
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a set of  _non-overlapping_  intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

**Example 1:**

**Input:** intervals = [[1,3],[6,9]], newInterval = [2,5]
**Output:** [[1,5],[6,9]]

**Example 2:**

**Input:** intervals = `[[1,2],[3,5],[6,7],[8,10],[12,16]]`, newInterval = `[4,8]`
**Output:** [[1,2],[3,10],[12,16]]
**Explanation:** Because the new interval `[4,8]` overlaps with `[3,5],[6,7],[8,10]`.

**Difficulty**:Medium

**Category**:

<!-- more -->

------------

# Analyze

# Solution

```cpp
class Solution {
 public:
  vector<Interval> insert(vector<Interval>& vals, Interval newVal) {
    vector<Interval> ans;
    int index = 0;
    for (auto& v : vals) {
      if (v.end < newVal.start) {
        ans.emplace_back(v);
        index++;
      } else if (v.start > newVal.end) {
        ans.emplace_back(v);
      } else {
        newVal.start = min(newVal.start, v.start);
        newVal.end = max(newVal.end, v.end);
      }
    }
    ans.insert(ans.begin() + index, newVal);
    return ans;
  }
};
```