---
title: Leetcode 996. Number of Squareful Arrays
date: 2019-02-18 16:48:06
updated: 2019-02-18 16:48:06
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given an array  `A`  of non-negative integers, the array is  _squareful_  if for every pair of adjacent elements, their sum is a perfect square.

Return the number of permutations of A that are squareful. Two permutations  `A1`  and  `A2`  differ if and only if there is some index  `i`  such that  `A1[i] != A2[i]`.

**Example 1:**

**Input:** [1,17,8]
**Output:** 2
**Explanation:** 
[1,8,17] and [17,8,1] are the valid permutations.

**Example 2:**

**Input:** [2,2,2]
**Output:** 1

**Note:**

1. `1 <= A.length <= 12`
2. `0 <= A[i] <= 1e9`

**Difficulty**:Hard

**Category**:

<!-- more -->

------------

# Analyze

------------

# Solution 1: DFS

Time complexity: O(n!)
Space complexity: O(n)

```cpp
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Number of Squareful Arrays.
// Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Number of Squareful Arrays.
class Solution {
 public:
  int numSquarefulPerms(vector<int>& A) {
    std::sort(begin(A), end(A));
    vector<int> out;
    vector<int> used(A.size(), 0);
    int ans = 0;
    permuteUniqueDFS(A, used, out, ans);
    return ans;
  }

 private:
  void permuteUniqueDFS(vector<int>& nums, vector<int>& used, vector<int>& out, int& ans) {
    if (out.size() == nums.size()) {
      ++ans;
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (used[i]) continue;
      // Same number can be only used once at each depth.
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
      if (!out.empty() && !squareful(out.back(), nums[i])) continue;
      used[i] = 1;
      out.emplace_back(nums[i]);
      permuteUniqueDFS(nums, used, out, ans);
      out.pop_back();
      used[i] = 0;
    }
  }

  bool squareful(int x, int y) {
    int s = sqrt(x + y);
    return s * s == x + y;
  }
};
```