---
title: Leetcode 632. Smallest Range
date: 2019-02-05 10:50:50
updated: 2019-02-05 10:50:50
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

You have  `k`  lists of sorted integers in ascending order. Find the  **smallest**  range that includes at least one number from each of the  `k`  lists.

We define the range [a,b] is smaller than range [c,d] if  `b-a < d-c`  or  `a < c`  if  `b-a == d-c`.

**Example 1:**  

**Input:**[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
**Output:** [20,24]
**Explanation:** 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

**Note:**  

1. The given list may contain duplicates, so ascending order means >= here.
2. 1 <=  `k`  <= 3500
3. -105  <=  `value of elements`  <= 105.
4. **For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.**

**Difficulty**:Hard

**Category**:Hash-Table, Two-Points, String

<!-- more -->

------------

# Analyze

输入是一些数组, 都是排好序的, 我们需要找到一个最小的数据范围, 使得这个范围至少能够包括每个数组中的一个数字. 我们可以考虑按照以下方式进行处理:

* 將这些数组合并成为一个大的数组并且保留其序号, 使用`vector<pair<int, int>>`, 然后排序.
* 这样等同于, 我们找到一个最小的窗口, 然后这个窗口里面要同时包含所有数组中的至少一个数字.

------------

# Solution

```cpp
class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<int> ans;
    vector<pair<int, int>> v;
    unordered_map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
      for (int& num : nums[i]) v.push_back({num, i});

    sort(v.begin(), v.end());
    int left = 0, len = v.size(), cnt = 0, diff = INT_MAX;
    for (int right = 0; right < len; ++right) {
      if (m[v[right].second] == 0) cnt++;
      ++m[v[right].second];

      while (cnt == n && left <= right) {
        if (diff > v[right].first - v[left].first) {
          diff = v[right].first - v[left].first;
          ans = {v[left].first, v[right].first};
        }
        if (--m[v[left].second] == 0) --cnt;
        ++left;
      }
    }
    return ans;
  }
};
```