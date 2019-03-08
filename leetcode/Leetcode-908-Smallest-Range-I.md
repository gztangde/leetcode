---
title: Leetcode 908. Smallest Range I
date: 2019-01-10 09:15:21
updated: 2019-01-10 09:15:21
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array  `A`  of integers, for each integer  `A[i]`  we may choose any  `x`  with  `-K <= x <= K`, and add  `x`to  `A[i]`.

After this process, we have some array  `B`.

Return the smallest possible difference between the maximum value of  `B` and the minimum value of  `B`.

**Example 1:**

> **Input:** A = [1], K = 0
> **Output:** 0
> **Explanation**: B = [1]

**Example 2:**

> **Input:** A = [0,10], K = 2
> **Output:** 6 **Explanation**: B = [2,8]

**Example 3:**

> **Input:** A = [1,3,6], K = 3
> **Output:** 0 **Explanation**: B = [3,3,3] or B = [4,4,4]

**Note:**

1.  `1 <= A.length <= 10000`
2.  `0 <= A[i] <= 10000`
3.  `0 <= K <= 10000`

**Difficulty**:Easy

**Category**:Math

<!-- more -->

------------

# Analyze

这道题目的输入是一个整数的集合以及一个目标数值`k`,要求对于`A[i]`的任何一个元素，我们都可以选择一个`-K <= x <= K`的整数，并將藏歌整数加入到这个集合里面去，找到每一项中加入的数值的最大值和最小值的最小差。(其实就是向中间值靠拢)

# Solution

```cpp
// Solution:
// Runtime: 20ms
class Solution {
 public:
  int smallestRangeI(vector<int>& A, int K) {
    int ma = *std::max_element(A.begin(), A.end());
    int mi = *std::min_element(A.begin(), A.end());

    return max(0, ma - mi - 2 * K);
  }
};
```

稍微修改一下：

```cpp
// Solution:
// Runtime: 20ms
class Solution {
 public:
  int smallestRangeI(vector<int>& A, int K) {
    int ma = 0, mi = INT_MAX;
    for (int& i : A) {
      ma = max(ma, i);
      mi = min(mi, i);
    }
    return max(0, ma - mi - 2 * K);
  }
};
```
