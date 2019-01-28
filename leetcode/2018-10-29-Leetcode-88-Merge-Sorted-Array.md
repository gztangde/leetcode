---
title: Leetcode 88. Merge Sorted Array
date: 2018-10-29 06:09:31
updated: 2018-10-29 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

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

------------

# Solution

## Solution1

```cpp
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0) return;
    vector<int> temp = nums1;
    std::cout << "Size:" << nums1.size() << std::endl;
    int index = 0;
    int p = 0, q = 0;
    for (int i = 0; i < m + n; ++i) {
      if (q < n && temp[p] >= nums2[q] || p == m) {
        nums1[i] = nums2[q];
        q++;
      } else {
        nums1[i] = temp[p];
        p++;
      }
    }
  }
};
```

## Solution2

```cpp
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p_a = m - 1, p_b = n - 1, p_merge = m + n - 1;
    while (p_a >= 0 && p_b >= 0) {
      nums1[p_merge--] = nums1[p_a] >= nums2[p_b] ? nums1[p_a--] : nums2[p_b--];
    }

    while (p_b >= 0) {
      nums1[p_merge--] = nums2[p_b--];
    }
  }
};
```