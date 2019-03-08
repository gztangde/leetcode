---
title: Leetcode 164. Maximum Gap
date: 2019-01-31 23:45:54
updated: 2019-01-31 23:45:54
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

**Example 1:**

**Input:** [3,6,9,1]
**Output:** 3
**Explanation:** The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.

**Example 2:**

**Input:** [10]
**Output:** 0
**Explanation:** The array contains less than 2 elements, therefore return 0.

**Note:**

- You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
- Try to solve it in linear time/space.

**Difficulty**:Hard

**Category**:Sort

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int num : nums) pq.push(num);
    int ans = 0;
    int pre = pq.top();
    pq.pop();
    for (int i = 1; i < nums.size(); ++i) {
      int cur = pq.top();
      pq.pop();
      ans = max(cur - pre, ans);
      pre = cur;
    }
    return ans;
  }
};
```