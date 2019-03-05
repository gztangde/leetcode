---
title: Leetcode 278. First Bad Version
date: 2018-12-17 09:09:31
updated: 2018-12-17 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Leetcode 278. First Bad Version

题目大意：给你一个API查询版本是否坏了，让你找出第一个坏掉的版本。

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have  `n`  versions  `[1, 2, ..., n]`  and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API  `bool isBadVersion(version)`  which will return whether  `version`  is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

**Example:**

> Given n = 5, and version = 4 is the first bad version.
> call isBadVersion(3) -> false
> call isBadVersion(5) -> true
> call isBadVersion(4) -> true
> Then 4 is the first bad version.

**Difficulty**:Easy

**Category**:Binary-Search

<!-- more -->

# Solution

## Solution 1: Brute Force

Time Complexity: O(n) TLE
Space Complexity: O(1)

```cpp
// Runtime: 1864 ms, faster than 9.83% of C++ online submissions for First Bad Version.
// Memory Usage: 8.2 MB, less than 41.34% of C++ online submissions for First Bad Version.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    for (int i = n; i > 0; --i) {
      if (isBadVersion(i)) continue;
      return i + 1 > n ? n : i + 1;
    }v
    return 1;
  }
};
```

## Solution 2: Binary Search

Time Complexity: O(log n)
Space Complexity: O(1)

```cpp
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left < right) {
      int mid = left + (right - left) / 2;
      isBadVersion(mid) ? right = mid : left = mid + 1;
    }
    return left;
  }
};
```