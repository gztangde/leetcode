---
title: Leetcode 739. Daily Temperatures
date: 2019-02-01 19:55:55
updated: 2019-02-01 19:55:55
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a list of daily temperatures  `T`, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put  `0`  instead.

For example, given the list of temperatures  `T = [73, 74, 75, 71, 69, 72, 76, 73]`, your output should be  `[1, 1, 4, 2, 1, 1, 0, 0]`.

**Note:**  The length of  `temperatures`  will be in the range  `[1, 30000]`. Each temperature will be an integer in the range  `[30, 100]`.

**Difficulty**:Medium

**Category**:Hash-Table, Stack

<!-- more -->

------------

# Analyze

# Solution

```cpp
// So slow
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& t) {
    int n = t.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (t[j] > t[i]) {
          t[i] = j - i;
          break;
        }
        if (j == n - 1) t[i] = 0;
      }
    }
    return t;
  }
};
```

## Solution 2

来源于讨论区: [Link](https://leetcode.com/problems/daily-temperatures/discuss/109869/JavaC%2B%2B-Clean-Code)

```cpp
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temps) {
    int n = temps.size();
    vector<int> waits(n, 0);
    vector<int> next(101, INT_MAX);  // next day with with certain temperature.
    for (int i = n - 1; i >= 0; i--) {
      int earliest = INT_MAX;
      for (int t = temps[i] + 1; t <= 100; t++) {
        // Find the next temp in the next list, get the smallest one;
        earliest = min(earliest, next[t]);
      }
      if (earliest != INT_MAX) waits[i] = earliest - i;
      next[temps[i]] = i;
    }
    return waits;
  }
};
```

## Solution 3

<!-- TODO: Understand this solution -->

还没有看懂的解法: [Link](https://leetcode.com/problems/daily-temperatures/discuss/121787/C%2B%2B-Clean-code-with-explanation%3A-O(n)-time-and-O(1)-space-(beats-99.13))

```cpp
vector<int> dailyTemperatures(vector<int>& temperatures) {
  vector<int> res(temperatures.size());
  for (int i = temperatures.size() - 1; i >= 0; --i) {
    int j = i + 1;
    while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
      if (res[j] > 0)
        j = res[j] + j;
      else
        j = temperatures.size();
    }
    // either j == size || temperatures[j] > temperatures[i]
    if (j < temperatures.size()) res[i] = j - i;
  }
  return res;
}
```
