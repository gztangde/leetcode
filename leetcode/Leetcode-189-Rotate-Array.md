---
title: Leetcode 189. Rotate Array
date: 2018-10-28 02:09:31
updated: 2018-10-28 02:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array, rotate the array to the right by  _k_  steps, where _k_ is non-negative.

**Example 1:**

**Input:** `[1,2,3,4,5,6,7]` and _k_ = 3
**Output:** `[5,6,7,1,2,3,4]`
**Explanation:**
rotate 1 steps to the right: `[7,1,2,3,4,5,6]`
rotate 2 steps to the right: `[6,7,1,2,3,4,5]` rotate 3 steps to the right: `[5,6,7,1,2,3,4]`

**Example 2:**

**Input:** `[-1,-100,3,99]` and _k_ = 2
**Output:** [3,99,-1,-100]
**Explanation:**
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

**Note:**

- Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
- Could you do it in-place with O(1) extra space?

<!-- more -->

-----------

# Solutions
<!-- TODO:Try some other ways to solute this question. -->

```cpp
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    vector<int> temp = nums;
    for (int i = 0; i < nums.size(); ++i) {
      nums[(i + k) % nums.size()] = temp[i];
    }
  }
};
```