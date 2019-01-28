---
title: Leetcode 645. Set Mismatch
date: 2019-01-26 16:35:41
updated: 2019-01-26 16:35:41
categories: 
- [Leetcode]
- [Leetcode, Hash-Table]
- [Leetcode, Math]
tags: Leetcode
notshow: true
top:
---

# Question

The set  `S`  originally contains numbers from 1 to  `n`. But unfortunately, due to the data error, one of the numbers in the set got duplicated to  **another**  number in the set, which results in repetition of one number and loss of another number.

Given an array  `nums`  representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

**Example 1:**  

> **Input:** nums = [1,2,2,4]
> **Output:** [2,3]

**Note:**  

1. The given array size will in the range [2, 10000].
2. The given array's numbers won't have any order.

**Difficulty**:Easy
**Category**:Hash-Table, Math

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i)
      while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) swap(nums[i], nums[nums[i] - 1]);

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] != i + 1) return {nums[i], i + 1};

    return {0};
  }
};
```

<!-- 
------------

# Leetcode Question Summary


------------ -->
