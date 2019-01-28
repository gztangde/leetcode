---
title: Leetcode 303. Range Sum Query - Immutable
date: 2019-01-07 09:09:31
updated: 2019-01-07 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an integer array  _nums_, find the sum of the elements between indices  _i_  and  _j_  (_i_  ≤  _j_), inclusive.

**Example:**  

> Given nums = [-2, 0, 3, -5, 2, -1]
> sumRange(0, 2) -> 1
> sumRange(2, 5) -> -1
> sumRange(0, 5) -> -3

**Note:**  

1. You may assume that the array does not change.
2. There are many calls to  _sumRange_  function.

**Difficulty**:Easy

**Category**:Dynamic-Programming

<!-- more -->

------------

# Analyze

------------

# Solution

## Solution 1: 直接使用求解的方式

```cpp
class NumArray {
 public:
  NumArray(vector<int> nums) { nums_ = std::move(nums); }

  int sumRange(int i, int j) {
    int sum = 0;
    for (int m = i; m <= j; m++) {
      sum += nums_[m];
    }
    return sum;
  }

 private:
  vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```

运行时间： 108ms
这个的时间复杂度是非常高的了： O(m*n) 
空间复杂度：O(n)

优化，进行预处理

## Solution 2: DP

![](/images/in-post/2019-01-07-Leetcode-303-Range-Sum-Query-Immutable/2019-01-07-17-39-42.png)

```cpp
class NumArray {
 public:
  NumArray(vector<int> nums) : sums_(nums) {
    if (nums.empty()) return;
    for (int i = 1; i < nums.size(); ++i) {
      sums_[i] += sums_[i - 1];
    }
  }

  int sumRange(int i, int j) {
    if (i == 0) return sums_[j];
    return sums_[j] - sums_[i - 1];
  }

 private:
  vector<int> sums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```

Times: O(n) + m*O(1) = O(n+m)
Spaces: O(n)
Runtime: 28ms
