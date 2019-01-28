---
title: Leetcode 922. Sort Array By Parity II
date: 2018-12-17 09:09:31
updated: 2018-12-17 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array  `A` of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever  `A[i]`  is odd,  `i`  is odd; and whenever  `A[i]`  is even,  `i`  is even.

You may return any answer array that satisfies this condition.

**Example 1:**

**Input:** [4,2,5,7]
**Output:** [4,5,2,7]
**Explanation:** [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

**Note:**

1. `2 <= A.length <= 20000`
2. `A.length % 2 == 0`
3. `0 <= A[i] <= 1000`

**Difficulty**:Easy

**Category**:Array, Sort

<!-- more -->

------------

# Analyze

------------

# Solution

## Solution 2 (Error: Memory Limit Exceeded)

```cpp
class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    vector<int> odd_vec, even_vec, res_vec;
    for (auto i : A) {
      if (i & 1)
        odd_vec.emplace_back(i);
      else
        even_vec.emplace_back(i);
    }
    for (int i = 0; i < odd_vec.size();) {
      res_vec.emplace_back(even_vec[i]);
      res_vec.emplace_back(odd_vec[i]);
    }
    return res_vec;
  }
};
```

## Solution 2

```cpp
class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    int odd = 1, even = 0, len = A.size();
    while (odd < len && even < len) {
      while (A[odd] & 1) odd += 2;
      while (A[even] % 2 == 0) even += 2;
      if (odd < len && even < len) {
        swap(A[odd], A[even]);
        odd += 2;
        even += 2;
      }
    }
    return A;
  }
};
```