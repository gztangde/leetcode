---
title: Leetcode 451. Sort Characters By Frequency
date: 2019-01-31 20:20:24
updated: 2019-01-31 20:20:24
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a string, sort it in decreasing order based on the frequency of characters.

**Example 1:**

> **Input:**
> "tree"
> **Output:**
> "eert"
> **Explanation:**
> 'e' appears twice while 'r' and 't' both appear once.
> So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

**Example 2:**

> **Input:**
> "cccaaa"
> **Output:**
> "cccaaa"
> **Explanation:**
> Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
> Note that "cacaca" is incorrect, as the same characters must be together.

**Example 3:**

> **Input:**
> "Aabb"
> **Output:**
> "bbAa"
> **Explanation:**
> "bbaA" is also a valid answer, but "Aabb" is incorrect.
> Note that 'A' and 'a' are treated as two different characters.

**Difficulty**:Medium

**Category**: Hash-Table, Heap

<!-- more -->

------------

# Analyze

# Solution

## Solution 1: Bubble Sort

```cpp
// Bubble Sort
// Runtime: 12ms > 87.28%
class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> m_;
    for (char c : s) ++m_[c];
    priority_queue<pair<int, int>> q;
    for (auto& val : m_) q.emplace(val.second, val.first);
    string ans;
    int len = s.length() - 1;
    while (q.size()) {
      for (int i = q.top().first; i > 0; --i) {
        ans += q.top().second;
      }
      q.pop();
    }
    return ans;
  }
};
```