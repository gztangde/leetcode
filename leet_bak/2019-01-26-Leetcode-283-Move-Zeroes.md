---
title: Leetcode 283. Move Zeroes
date: 2019-01-26 16:16:29
updated: 2019-01-26 16:16:29
categories: 
- [Leetcode]
- [Leetcode, Array]
- [Leetcode, Two-Points]
tags: Leetcode
notshow: true
top:
---

# Question

Given an array  `nums`, write a function to move all  `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Example:**

**Input:** `[0,1,0,3,12]`
**Output:** `[1,3,12,0,0]`

**Note**:

1. You must do this  **in-place**  without making a copy of the array.
2. Minimize the total number of operations.

**Difficulty**:Medium
**Category**:Array, Two Points

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    for (int i = 0, j = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) swap(nums[i], nums[j++]);
    }
  }
};
```

<!-- 
------------

# Leetcode Question Summary


------------ -->
