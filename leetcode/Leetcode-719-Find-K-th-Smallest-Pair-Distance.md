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

# Question

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

# Analyze

![](/images/in-post/2019-01-21-Leetcode-719-Find-K-th-Smallest-Pair-Distance/2019-01-21-23-08-54.png)

![](/images/in-post/2019-01-21-Leetcode-719-Find-K-th-Smallest-Pair-Distance/2019-01-21-23-09-02.png)

# Solution

```cpp
// Runtime: 504ms
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


