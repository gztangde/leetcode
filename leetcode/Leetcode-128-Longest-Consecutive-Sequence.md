---
title: Leetcode 128. Longest Consecutive Sequence
date: 2018-11-07 06:09:31
updated: 2018-11-07 06:09:31
categories:
- [Leetcode]
- [Leetcode, Hash-Table]
tags: Leetcode
notshow: true
top:
---

# Question

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(_n_) complexity.

**Example:**

> **Input:** [100, 4, 200, 1, 3, 2]
> **Output:** 4
> **Explanation:** The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore its length is 4.

<!-- more -->

------------

# Analyze

本题目要求的是O(n)的时间复杂度，因为序列中的元素是无序的，而且要求了O(n)的时间复杂度，所以这道题尝试使用哈希表去完成。

使用哈希表`unordered_map<int, bool> used`记录每个元素是否已经使用，对每一个元素，使用该元素作为中心，向左右扩张到不能扩张位置，并将这些位置设置为`True`，然后记录下能够扩张的长度。

**时间复杂度:** O(n)

# Solution

## Solution 1: Unodered_map, expand to two side

```cpp
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    int longest = 0;
    unordered_map<int, bool> used;
    for (int i : nums) used[i] = false;
    for (auto n : nums) {
      if (used[n]) continue;
      used[n] = true;
      int prev = n - 1, next = n + 1;
      while (used.find(prev) != used.end()) used[prev--] = true;
      while (used.find(next) != used.end()) used[next++] = true; 
      longest = max(longest, next - prev - 1);
    }
    return longest;
  }
};
```

## Solution 1: unordered_set, expand to two side

对上面的解法,也可以使用`unordered_set`去解答,这种方案来自于Leetcode[讨论区](https://leetcode.com/problems/longest-consecutive-sequence/discuss/41060/A-simple-C%2B%2Bsolution-using-unordered_set.And-simple-consideration-about-this-problem)

```cpp
class Solution {
 public:
  int longestConsecutive(vector<int> &num) {
    unordered_set<int> record(num.begin(), num.end());
    int res = 0;
    for (int n : num) {
      if (record.find(n) == record.end()) continue;
      record.erase(n);
      int prev = n - 1, next = n + 1;
      while (record.find(prev) != record.end()) record.erase(prev--);
      while (record.find(next) != record.end()) record.erase(next++);
      res = max(res, next - prev - 1);
    }
    return res;
  }
};
```
