---
title: Leetcode 763. Partition Labels
date: 2019-02-06 00:15:35
updated: 2019-02-06 00:15:35
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

A string  `S`  of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

**Example 1:**  

**Input:** S = "ababcbacadefegdehijhklij"
**Output:** [9,7,8]
**Explanation:**
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

**Note:**  

1.  `S`  will have length in range  `[1, 500]`.
2.  `S`  will consist of lowercase letters (`'a'`  to  `'z'`) only.

**Difficulty**:Medium

**Category**:Two-Points, Greedy

<!-- more -->

------------

# Analyze

分析参考博客: [花花酱 LeetCode 763. Partition Labels](https://zxi.mytechroad.com/blog/string/leetcode-763-partition-labels/)

![](/images/2019-02-06-00-16-24.png)

# Solution

## Solution 1: Brute Force

Time complexity: O(n^2), Space complexity: O(1)

```cpp
class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<int> ans;
    size_t start = 0, end = 0;
    for (size_t i = 0; i < S.length(); ++i) {
      // Find the las element for the first element.
      end = max(end, S.find_last_of(S[i]));
      if (end == i) {
        ans.emplace_back(end - start + 1);
        start = end + 1;
      }
    }
    return ans;
  }
};
```

## Solution 2: Greedy

Time complexity: O(n), Space complexity: O(26/128)

```cpp
class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<int> last_index(128, 0);
    for (int i = 0; i < S.length(); ++i) last_index[S[i]] = i;
    vector<int> ans;
    int start = 0, end = 0;
    for (int i = 0; i < S.length(); ++i) {
      // Find the las element for the first element.
      end = max(end, last_index[S[i]]);
      if (end == i) {
        ans.emplace_back(end - start + 1);
        start = end + 1;
      }
    }
    return ans;
  }
};
```