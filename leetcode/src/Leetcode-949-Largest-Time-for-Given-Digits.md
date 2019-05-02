---
title: Leetcode 949. Largest Time for Given Digits
date: 2019-01-08 09:09:31
updated: 2019-01-08 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59. Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5. If no valid time can be made, return an empty string.

**Example 1:**

> **Input:** [1,2,3,4]
> **Output:** "23:41"

**Example 2:**

> **Input:** [5,5,5,5]
> **Output:** ""

**Note:**

1. `A.length == 4`
2. `0 <= A[i] <= 9`
  
**Difficulty**:Easy

**Category**:Math

<!-- more -->

# Solution

```cpp
class Solution {
 public:
  string largestTimeFromDigits(vector<int>& A) {
    vector<int> temp(10, 0);
    for (int i : A) temp[i]++;
    for (int h = 23; h >= 0; --h) {
      for (int m = 59; m >= 0; --m) {
        vector<int> rec = temp;
        int h1 = h / 10, h2 = h % 10;
        int m1 = m / 10, m2 = m % 10;
        if (rec[h1] > 0) rec[h1]--;
        if (rec[h2] > 0) rec[h2]--;
        if (rec[m1] > 0) rec[m1]--;
        if (rec[m2] > 0) rec[m2]--;
        if (rec == vector<int>(10, 0)) return to_string(h1) + to_string(h2) + ":" + to_string(m1) + to_string(m2);
      }
    }
    return "";
  }
};
```

