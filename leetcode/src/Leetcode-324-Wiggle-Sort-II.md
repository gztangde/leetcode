---
title: Leetcode 324. Wiggle Sort II
date: 2019-01-31 18:09:38
updated: 2019-01-31 18:09:38
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given an unsorted array  `nums`, reorder it such that  `nums[0] < nums[1] > nums[2] < nums[3]...`.

**Example 1:**

> **Input:** `nums = [1, 5, 1, 1, 6, 4]`
> **Output:** One possible answer is `[1, 4, 1, 5, 1, 6]`.

**Example 2:**

> **Input:** `nums = [1, 3, 2, 2, 3, 1]`
> **Output:** One possible answer is `[2, 3, 1, 3, 1, 2]`.

**Note:**  
You may assume all input has valid answer.

**Follow Up:**  
Can you do it in O(n) time and/or in-place with O(1) extra space?

**Difficulty**:Medium

**Category**:Sort

<!-- more -->

<!-- TODO: Write this post -->

https://leetcode.com/problems/wiggle-sort-ii/

# Solution

```cpp
class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    int n = nums.size();
    int left = (n + 1) / 2, right = n;
    for (int i = 0; i < n; ++i) {
      nums[i] = i & 1 ? temp[--right] : temp[--left];
    }
  }
};
```