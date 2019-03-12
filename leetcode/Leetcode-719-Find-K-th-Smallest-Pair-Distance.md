---
title: Leetcode 719. Find K th Smallest Pair Distance
date: 2019-01-21 21:49:31
updated: 2019-01-21 21:49:31
categories: 
- [Leetcode]
- [Leetcode, Array]
- [Leetcode, Binary-Search]
- [Leetcode, Heap]
tags: Leetcode
notshow: true
top:
---

# Leetcode 719. Find K th Smallest Pair Distance

题目：给你一个数组，返回所有数对中，绝对值差第k小的值。

Given an integer array, return the k-th smallest  **distance**  among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

**Example 1:**  

> **Input:**
> nums = [1,3,1]
> k = 1
> **Output: 0** 
> **Explanation:**
> Here are all the pairs:
> (1,3) -> 2
> (1,1) -> 0
> (3,1) -> 2
> Then the 1st smallest distance pair is (1,1), and its distance is 0.

**Note:**  

1. `2 <= len(nums) <= 10000`.
2. `0 <= nums[i] < 1000000`.
3. `1 <= k <= len(nums) * (len(nums) - 1) / 2`.

**Difficulty**:Hard

**Category**:Array, Binary-Search, Heap

<!-- more -->

# Solution

![](/images/in-post/2019-01-21-Leetcode-719-Find-K-th-Smallest-Pair-Distance/2019-01-21-23-08-54.png)

![](/images/in-post/2019-01-21-Leetcode-719-Find-K-th-Smallest-Pair-Distance/2019-01-21-23-09-02.png)

## Solution 1: Binary Search

Time Complexity: O(n log n), Space complexity: O(1)

```cpp
class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    int left = 0, right = nums.back() - nums.front();
    while (left < right) {
      int mid = left + (right - left) / 2;
      count(nums, mid) >= k ? right = mid: left = mid + 1;
    }
    return left;
  }

 private:
  // Count how many distance less that target
  int count(vector<int>& nums, int& target) {
    int n = nums.size();
    int j = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      while (j < n && nums[j] - nums[i] <= target) ++j;
      cnt += j - i - 1;
    }
    return cnt;
  }
};
```

## Solution 2: Bucket Sort

使用暴力搜索的方式，是会超出时间的，我们采用桶排序的思路来求解这个问题，使用每个距离作为桶的标号，这样我们可以很容易得到每一个距离有多少个元素对。

1. 排序数组(也可以不排序)
2. 循环扫描所有的元素，將求得的所有距离全部放入对应的桶计数中
3. 依次从小到达计算第 `k-th` smallest distance.

Time complexity: O(n^2), Space complexity: O(max_d)

```cpp
class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    const int max_d = nums.back();
    vector<int> rec(max_d + 1, 0);
    const int n = nums.size();
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        ++rec[nums[j] - nums[i]];

    for (int i = 0; i < max_d + 1; ++i) {
      k -= rec[i];
      if (k <= 0) return i;
    }
    return 0;
  }
};
```