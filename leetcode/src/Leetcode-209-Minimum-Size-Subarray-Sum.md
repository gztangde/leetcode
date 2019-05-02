---
title: Leetcode 209. Minimum Size Subarray Sum
date: 2019-02-05 20:57:11
updated: 2019-02-05 20:57:11
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Leetcode 209. Minimum Size Subarray Sum

Given an array of  **n**  positive integers and a positive integer  **s**, find the minimal length of a  **contiguous**  subarray of which the sum ≥  **s**. If there isn't one, return 0 instead.

**Example:**

**Input:** `s = 7, nums = [2,3,1,2,4,3]`
**Output:** 2
**Explanation:** the subarray `[4,3]` has the minimal length under the problem constraint.

**Follow up:**

If you have figured out the  _O_(_n_) solution, try coding another solution of which the time complexity is  _O_(_n_  log  _n_).

**Difficulty**:Medium

**Category**:

<!-- more -->

# Solution

Time complexity: O(n), Space complexity: O(1)

```cpp
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size(), left = 0, right = 0, ans = INT_MAX;
    int sum = 0;
    for (right = 0; right < n; ++right) {
      sum += nums[right];
      while (sum >= s) {
        ans = min(ans, right - left + 1);
        sum -= nums[left++];
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
```

# Relative problem

* [Leetcode 76. Minimum Window Substring](./Leetcode-76-Minimum-Window-Substring/)
* [Leetcode 209. Minimum Size Subarray Sum](./Leetcode-209-Minimum-Size-Subarray-Sum/)
