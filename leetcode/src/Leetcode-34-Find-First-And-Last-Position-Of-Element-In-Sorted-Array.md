---
title: Leetcode 34. Find First and Last Position of Element in Sorted Array
date: 2018-12-17 09:09:31
updated: 2018-12-17 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array of integers  `nums`  sorted in ascending order, find the starting and ending position of a given  `target`  value.

Your algorithm's runtime complexity must be in the order of  _O_(log  _n_).

If the target is not found in the array, return  `[-1, -1]`.

**Example 1:**

> **Input:** nums = [`5,7,7,8,8,10]`, target = 8
> **Output:** [3,4]

**Example 2:**

> **Input:** nums = [`5,7,7,8,8,10]`, target = 6
> **Output:** [-1,-1]

**Difficulty**:Medium

**Category**:Array, Binary-Search

<!-- more -->

# Solution

## Solution 1: Binary Search

在第一个　Binary Search 里面，　寻找　lower bound 的时候，有两种情况：
* 如果目标数字比数组中所有数值都要大，那么　Left 指针会一直移动到超出数组索引
* 如果目标数字比数组中所有数字都要小的话，　那么，right指针会一直移动到０的位置

所以在这个位置的去数值要比较特殊：如果使用的是：`int left = 0, right = nums.size();`, 那么在使用`left` or `right`进行索引的时候，　一定要判断是否超出索引。

```cpp
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid;
    }
    if (nums[right] != target) return res;
    res[0] = right;

    // Do the second Binary Search
    right = nums.size();
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] <= target)
        left = mid + 1;
      else
        right = mid;
    }
    res[1] = left - 1;
    return res;
  }
};
```

# Solution 2: DFS

```cpp
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    int index_x = search(nums, target);
    if (index_x == -1) return res;
    int index_left = index_x, index_right = index_x;
    while (index_left && nums[index_left - 1] == target) index_left--;
    while (index_right < nums.size() - 1 && nums[index_right + 1] == target) index_right++;
    res[0] = index_left;
    res[1] = index_right;
    return res;
  }

  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left != right) {
      const int mid = left + (right - left) / 2;
      if (nums[mid] == target) return mid;
      if (nums[left] < nums[mid]) {
        if (nums[left] <= target && nums[mid] > target) {
          right = mid;
        } else {
          left = mid + 1;
        }
      } else if (nums[left] == nums[mid]) {
        left++;
      } else {
        if (nums[mid] < target && nums[right - 1] >= target) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
    }
    return -1;
  }
};
```

