---
title: Leetcode 169. Majority Element
date: 2019-01-08 09:09:31
updated: 2019-01-08 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an unsorted array of integers, find the length of longest increasing subsequence.

**Example:**

> **Input:** `[10,9,2,5,3,7,101,18]` **Output:** 4 
> **Explanation:** The longest increasing subsequence is `[2,3,7,101]`, therefore the length is `4`. 

**Note:**

- There may be more than one LIS combination, it is only necessary for you to return the length.
- Your algorithm should run in O(_n2_) complexity.

**Follow up:**  Could you improve it to O(_n_  log  _n_) time complexity?

**Difficulty**:Medium

**Category**:Dynamic-Programming, Binary-Search

<!-- more -->

------------

# Analyze

------------

# Solution

## Solution 1: DP

解题思路来源于博客：[花花酱 LeetCode 300. Longest Increasing Subsequence](http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-300-longest-increasing-subsequence/)

具有的特性：

![](/images/in-post/2019-01-08-Leetcode-300-Longest-Increasing-Subsequence/2019-01-08-17-44-01.png)

解决方案的流程示意图：

![](/images/in-post/2019-01-08-Leetcode-300-Longest-Increasing-Subsequence/2019-01-08-17-44-19.png)

```cpp
// Runtimes: 32ms
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> f(n, 1);
    // f[i] 表示前面的元素可以组合得到的最长的元素之和
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[i] > nums[j]) f[i] = max(f[i], f[j] + 1);
    return *std::max_element(f.begin(), f.end());
  }
};
```

## Solution 2: 递归方案

解题思路：
![](/images/in-post/2019-01-08-Leetcode-300-Longest-Increasing-Subsequence/2019-01-08-17-59-46.png)

```cpp
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    const int n = nums.size();
    f_ = vector<int>(n, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, LIS(nums, i));
    }
    return ans;
  }

 private:
  vector<int> f_;
  int LIS(const vector<int>& nums, int r) {
    if (r == 0) return 1;
    if (f_[r] > 0) return f_[r];
    int ans = 1;

    for (int i = 0; i < r; ++i) {
      if (nums[r] > nums[i]) {
        ans = max(ans, LIS(nums, i) + 1);
      }
    }
    f_[r] = ans;
    return f_[r];
  }
};
```
