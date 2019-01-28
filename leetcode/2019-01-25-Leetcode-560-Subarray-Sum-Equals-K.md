---
title: Leetcode 560. Subarray Sum Equals K
date: 2019-01-25 18:28:07
updated: 2019-01-25 18:28:07
categories: 
- [Leetcode]
- [Leetcode, Array]
- [Leetcode, Hash-Table]
tags: Leetcode
notshow: true
top:
---

# Question

Given an array of integers and an integer  **k**, you need to find the total number of continuous subarrays whose sum equals to  **k**.

**Example 1:**  

```
**Input:**nums = [1,1,1], k = 2
**Output:** 2
```

**Note:**  

1. The length of the array is in range [1, 20,000].
2. The range of numbers in the array is [-1000, 1000] and the range of the integer  **k**  is [-1e7, 1e7].

**Difficulty**:Medium
**Category**:Array, Hash-Table

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int ans = 0;
    const int len = nums.size();
    vector<int> sum(len + 1, 0);
    // s[i] is the sum from 0 to i - 1;
    for (int i = 1; i <= len; ++i) sum[i] = sum[i - 1] + nums[i - 1];
    for (int i = 0; i < len; ++i) {
      for (int j = i; j < len; ++j) {
        if (sum[j + 1] - sum[i] == k) ++ans;
      }
    }
    return ans;
  }
};
```


