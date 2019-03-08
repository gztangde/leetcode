---
title: Leetcode 75. Sort Colors
date: 2018-12-16 09:09:31
updated: 2018-12-16 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array with  _n_  objects colored red, white or blue, sort them  **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

**Note:** You are not suppose to use the library's sort function for this problem.

**Example:**

> **Input:** [2,0,2,1,1,0]
> **Output:** [0,0,1,1,2,2]

**Follow up:**

- A rather straight forward solution is a two-pass algorithm using counting sort.  
  First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

- Could you come up with a one-pass algorithm using only constant space?

**Difficulty**:Medium

**Category**:Array, Two-Points, Sort

<!-- more -->

------------

# Analyze

# Solution

# Solution 1

```cpp
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int count[3] = {0};
    for (auto i : nums) count[i]++;
    for (int i = 0, index = 0; i < 3; ++i) {
      for (int j = 0; j < count[i]; ++j) nums[index++] = i;
    }
  }
};
```

# Solution 2: 颜色问题, 分成三个部分排序

```cpp
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int left = -1, mid = 0, right = nums.size();
    while (mid < right) {
      if (nums[mid] == 0) {
        swap(nums[++left], nums[mid++]);
      } else if (nums[mid] == 2) {
        swap(nums[--right], nums[mid]);
      } else
        ++mid;
    }
  }
};
```