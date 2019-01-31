---
title: Leetcode 215. Kth Largest Element in an Array
date: 2019-01-31 16:33:40
updated: 2019-01-31 16:33:40
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Find the  **k**th largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

**Example 1:**

> **Input:** `[3,2,1,5,6,4]` and k = 2
> **Output:** 5

**Example 2:**

> **Input:** `[3,2,3,1,2,4,5,5,6]` and k = 4
> **Output:** 4

**Note:**  
You may assume k is always valid, 1 ≤ k ≤ array's length.

**Difficulty**:Medium

**Category**:

<!-- more -->

------------

# Analyze

这道题目是要求找到 k-th Largest Element in An Array, 可以考虑使用堆排序.

------------

# Solution

## Solution 1: Sort

时间复杂度 $O(n log n)$, 空间复杂度 $O(1)$

```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};
```

## Solution 2: Heap Sort

排序 ：时间复杂度 O(nlog n)，空间复杂度 O(N)

```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> p;
    for (int& i : nums) p.push(i);
    while (--k) p.pop();
    return p.top();
  }
};
```