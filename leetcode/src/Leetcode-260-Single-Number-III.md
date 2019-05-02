---
title: Leetcode 260. Single Number III
date: 2019-02-07 23:20:49
updated: 2019-02-07 23:20:49
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given an array of numbers  `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

**Example:**

**Input:**  `[1,2,1,3,2,5]`
**Output:** `[3,5]`

**Note**:

1. The order of the result is not important. So in the above example,  `[5, 3]`  is also correct.
2. Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

**Difficulty**:Medium

**Category**:

<!-- more -->

# Analyze

两个不相等的元素一定有一位是不相同的, 所有当我们將所有元素都异或之后, 得到的是两个不存在重复的两个元素异或的结果:

根据 `d &= -d`可以得到最右边不为0的位, 这一位就是这两个不同的元素的其中一个不同的地方, 我们利用这一位, 將所有元素分成两类, 分别在进行异或一次, 就可以筛选出来不同的元素. 时间复杂度: O(n)

# Solution

```cpp
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int diff = 0;
    for (int& num : nums) diff ^= num;
    diff &= -diff;
    vector<int> ans(2, 0);
    for (int& num : nums) {
      if (num & diff)
        ans[0] ^= num;
      else
        ans[1] ^= num;
    }
    return ans;
  }
};
```