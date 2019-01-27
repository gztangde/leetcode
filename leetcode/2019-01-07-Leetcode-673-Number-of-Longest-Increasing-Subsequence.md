---
title: Leetcode 673. Number of Longest Increasing Subsequence
date: 2019-01-07 19:09:31
updated: 2019-01-07 19:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an unsorted array of integers, find the number of longest increasing subsequence.

**Example 1:**  

> **Input:** [1,3,5,4,7]
> **Output:** 2
> **Explanation:** The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].

**Example 2:**  

> **Input:** [2,2,2,2,2]
> **Output:** 5
> **Explanation:** The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

**Note:**  Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.

**Difficulty**:Medium
**Category**:Dynamic-Programming

<!-- more -->

------------

# Analyze

------------

# Solution

## Solution 1:　递归

参考博客：[花花酱 LeetCode 673. Number of Longest Increasing ](http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-673-number-of-longest-increasing-subsequence/)

![](/images/in-post/2019-01-07-Leetcode-673-Number-of-Longest-Increasing-Subsequence/2019-01-08-19-03-20.png)

```cpp
// Runtime: 80ms
class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    const int n = nums.size();
    f_ = vector<int>(n, 0);
    c_ = vector<int>(n, 0);
    // max_len must be difined in local, it will changed in the count function
    int max_len = 0;
    for (int i = 0; i < n; ++i) max_len = max(max_len, LIS(nums, i));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (LIS(nums, i) == max_len) {
        ans += count(nums, i);
      }
    }

    return ans;
  }

 private:
  vector<int> c_;
  vector<int> f_;
  int count(const vector<int>& nums, int n) {
    if (n == 0) return 1;
    if (c_[n] > 0) return c_[n];
    int max_len = LIS(nums, n);
    int total_count = 0;
    for (int i = 0; i < n; ++i) {
      // 比最后一个元素大，并且长度正好大于１
      if (nums[n] > nums[i] && LIS(nums, i) == max_len - 1) {
        total_count += count(nums, i);
      }
    }
　　 //如果数量为０，那就是在之前找不到一个子集，所以就只能使用这一个数字作为１，就是单个元素的情况
    if (total_count == 0) {
      total_count = 1;
    }

    c_[n] = total_count;
    return c_[n];
  }

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

## Solution 2: 动态规划

<!-- TODO: Understand the code 
        if (nums[i] > nums[j]) {
          if (f[j] + 1 > f[i]) {
            f[i] = f[j] + 1;
            c[i] = c[j];
          } else if (f[j] + 1 == f[i]) {
            c[i] += c[j];
          }
 -->
```cpp
// Solution2: Dynamic-Programming
// Runtime: 32ms
class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> f(n, 1);
    vector<int> c(n, 1);
    // f[i] 表示前面的元素可以组合得到的最长的元素之和
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j)
      　// 最后一个元素大于前面的元素的话，如果子问题的长度＋1比现在的长度大的话，那就表示找到了一个新的解
        if (nums[i] > nums[j]) {
          if (f[j] + 1 > f[i]) {
            f[i] = f[j] + 1;
            //新的解，但是数量却没有变化的
            c[i] = c[j];
          } else if (f[j] + 1 == f[i]) {
            //之前的最长子序列加一的长度和现在的长度相等，那么就表示可以把之前的子序列的长度归入到这里面进行统计
            c[i] += c[j];
          }
        }

    int max_len = *std::max_element(f.begin(), f.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (f[i] == max_len) ans += c[i];
    }
    return ans;
  }
};
```