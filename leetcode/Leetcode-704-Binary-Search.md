---
title: Leetcode 704. Binary Search
date: 2019-03-09 11:32:12
updated: 2019-03-09 11:32:12
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Leetcode 704. Binary Search

Given a  **sorted**  (in ascending order) integer array  `nums`  of  `n`  elements and a  `target`value, write a function to search  `target`  in  `nums`. If  `target`  exists, then return its index, otherwise return  `-1`.

  
**Example 1:**

**Input:** `nums` = [-1,0,3,5,9,12], `target` = 9
**Output:** 4
**Explanation:** 9 exists in `nums` and its index is 4

**Example 2:**

**Input:** `nums` = [-1,0,3,5,9,12], `target` = 2
**Output:** -1
**Explanation:** 2 does not exist in `nums` so return -1

**Note:**

1.  You may assume that all elements in  `nums`  are unique.
2.  `n`  will be in the range  `[1, 10000]`.
3.  The value of each element in  `nums`  will be in the range  `[-9999, 9999]`.

**Difficulty**:Medium

**Category**:

# Solution

Time complexity: O(log n)
Space complexity: O(1)

```cpp
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) return mid;
      else if (nums[mid] < target) left = mid + 1;
      else right = mid;
    }
    return -1;
  }
};
```