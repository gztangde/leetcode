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

# Solution

把非零数前移，要求不能改变非零数的相对应的位置关系，而且不能拷贝额外的数组，那么只能用替换法in-place来做，需要用两个指针，一个不停的向后扫，找到非零位置，然后和前面那个指针交换位置即可，参见下面的代码：

Time complexity: O(n)
Space complexity: O(1)

```cpp
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int left = 0, right = 0;
    for (; right < nums.size(); ++right) {
      // If nums[i] != 0, then we can swap with the first zero....
      // nums[j] is zero....
      if (nums[right] != 0) swap(nums[right], nums[left++]);
    }
  }
};
```