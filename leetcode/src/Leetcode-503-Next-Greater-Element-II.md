---
title: Leetcode 503. Next Greater Element II
date: 2019-02-02 00:24:55
updated: 2019-02-02 00:24:55
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

**Example 1:**  

> **Input:** [1,2,1]
> **Output:** [2,-1,2]
> **Explanation:** The first 1's next greater number is 2;
> The number 2 can't find next greater number;
> The second 1's next greater number needs to search circularly, which is also 2.

**Note:**  The length of given array won't exceed 10000.

**Difficulty**:Medium

**Category**:Stack

<!-- more -->

# Analyze

这里的输入数组是一个循环数组, 我们首先想到的是循环遍历数组, 每一个元素向后找到第一个比它大的元素, 找到第一个之后就停止.

# Solution

```cpp
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n + i; ++j) {
        if (nums[j % n] > nums[i]) {
          ans[i] = nums[j % n];
          break;
        }
      }
    }
    return ans;
  }
};
```