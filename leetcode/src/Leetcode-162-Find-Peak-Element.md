---
title: Leetcode 162. Find Peak Element
date: 2019-03-11 13:23:31
updated: 2019-03-11 13:23:31
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Question

A peak element is an element that is greater than its neighbors.

Given an input array  `nums`, where  `nums[i] ≠ nums[i+1]`, find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that  `nums[-1] = nums[n] = -∞`.

**Example 1:**

**Input:** **nums** = `[1,2,3,1]`
**Output:** 2
**Explanation:** 3 is a peak element and your function should return the index number 2.

**Example 2:**

**Input:** **nums** = `[`1,2,1,3,5,6,4]
**Output:** 1 or 5 
**Explanation:** Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.

**Note:**

Your solution should be in logarithmic complexity.

**Difficulty**:Medium

**Category**:

# Solution

## Solution 1: Line Scan

所谓峰值就是比周围两个数字都大的数字，那么只需要跟周围两个数字比较就可以了。既然要跟左右的数字比较，就得考虑越界的问题，题目中给了nums[-1] = nums[n] = -∞，那么我们其实可以把这两个整型最小值直接加入到数组中，然后从第二个数字遍历到倒数第二个数字，这样就不会存在越界的可能了。由于题目中说了峰值一定存在，那么有一个很重要的corner case. 对于数组中只有一个数字的情况在开头直接判断一下即可.

Time complexity: O(n), Space complexity: O(1)

```cpp
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    nums.insert(nums.begin(), INT_MIN);
    nums.push_back(INT_MIN);
    for (int i = 1; i < (int)nums.size() - 1; ++i) {
      if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i - 1;
    }
    return -1;
  }
};
```

```cpp
class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[i-1]) return i - 1;
    }
    return n - 1;
  }
};
```

## Solution 2: Binary Search

题目要求是 O(log n) 的时间复杂度，考虑使用类似于二分查找法来缩短时间。由于只是需要找到任意一个峰值，那么我们在确定二分查找折半后中间那个元素后，和紧跟的那个元素比较下大小，如果大于，则说明峰值在前面，如果小于则在后面。这样就可以找到一个峰值了。

```cpp
class Solution {
public:
  int findPeakElement(vector<int>& A) {
    // Binary Search
    int left = 0, right = A.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (A[mid] < A[mid + 1]) left = mid + 1; // For the left part
      else right = mid;
    }
    return left;
  }
};
```