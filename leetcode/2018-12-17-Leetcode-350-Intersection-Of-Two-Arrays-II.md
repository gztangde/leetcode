---
title: Leetcode 350. Intersection of Two Arrays II
date: 2018-12-17 09:09:31
updated: 2018-12-17 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given two arrays, write a function to compute their intersection.

**Example 1:**

> **Input:** nums1 = [1,2,2,1], nums2 = [2,2]
> **Output:** [2,2]

**Example 2:**

> **Input:** nums1 = [4,9,5], nums2 = [9,4,9,8,4]
> **Output:** [4,9]

**Note:**

- Each element in the result should appear as many times as it shows in both arrays.
- The result can be in any order.

**Follow up:**

- What if the given array is already sorted? How would you optimize your algorithm?
- What if  _nums1_'s size is small compared to  _nums2_'s size? Which algorithm is better?
- What if elements of  _nums2_  are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

**Difficulty**:Easy

**Category**:Hash-Table, Two-Points, Binary-Search, Sort

# Solution

## Solution 1: HashTable

Time Complexity: O(n)
Space Complexity: O(n)

```cpp
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int> cnts;
    for (int& num : nums1) ++cnts[num];
    for (int& num : nums2) {
      if (cnts[num]) {
        ans.emplace_back(num);
        --cnts[num];
      }
    }
    return ans;
  }
};
```

## Solution 2: Sorting

Time Complexity: O(n log n)
Space Complexity: O(n)

```cpp
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    int i = 0, j = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] == nums2[j]) {
        res.push_back(nums1[i]);
        ++i;
        ++j;
      } else if (nums1[i] > nums2[j]) {
        ++j;
      } else {
        ++i;
      }
    }
    return res;
  }
};
```