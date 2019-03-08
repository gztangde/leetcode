---
title: Leetcode 88. Merge Sorted Array
date: 2018-10-29 06:09:31
updated: 2018-10-29 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Leetcode 88. Merge Sorted Array

Given two sorted integer arrays  _nums1_  and  _nums2_, merge  _nums2_  into  _nums1_  as one sorted array.

**Note:**

- The number of elements initialized in  _nums1_  and  _nums2_  are  _m_  and  _n_  respectively.
- You may assume that  _nums1_  has enough space (size that is greater or equal to  _m_  +  _n_) to hold additional elements from  _nums2_.

**Example:**

> **Input:**
> nums1 = [1,2,3,0,0,0], m = 3
> nums2 = [2,5,6],       n = 3
> **Output:** [1,2,2,3,5,6]

**Difficulty**:Easy

**Category**:Array, Two Pointers

<!-- more -->

# Solution

## Solution1: Two Points

混合插入有序数组，由于两个数组都是有序的，所有只要按顺序比较大小即可。

Time complexity: O(m + n)
Space complexity: O(m + n)

```cpp
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0) return;
    vector<int> temp = nums1;

    int p = 0, q = 0;
    for (int i = 0; i < m + n; ++i) nums1[i] = q < n && temp[p] >= nums2[q] || p == m ? nums2[q++] : temp[p++];
  }
};
```

## Solution2: Two Points

Fill nums1 from back to front
Time complexity: O(m + n)
Space complexity: O(1) in-place

```cpp
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p = m - 1, q = n - 1, tail = m + n - 1;
    while (q >= 0) nums1[tail--] = (p >= 0 && nums1[p] >= nums2[q]) ? nums1[p--] : nums2[q--];
  }
};
```