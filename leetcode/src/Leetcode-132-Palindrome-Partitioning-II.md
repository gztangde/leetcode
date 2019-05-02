---
title: Leetcode 132. Palindrome Partitioning II 
date: 2018-12-19 09:09:31
updated: 2018-12-19 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a string  _s_, partition  _s_  such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of  _s_.

**Example:**
> **Input:** "aab"
> **Output:** 1
> **Explanation:** The palindrome partitioning ["aa","b"] could be produced using 1 cut.

**Difficulty**:Hard

**Category**:Dynamic-Programming

<!-- more -->

# Solution

## Solution 1: Memory Limit Exceeded 

```cpp
class Solution {
 public:
  int minCut(string s) {
    vector<string> out;
    vector<vector<string>> res;
    int res_min = INT_MAX;

    partitionDFS(s, 0, out, res);
    for (auto t : res) {
      int len_cut = t.size() - 1;
      res_min = min(res_min, len_cut);
    }
    return res_min;
  }
  void partitionDFS(string s, int start, vector<string>& out, vector<vector<string>>& res) {
    if (start == s.size()) {
      res.emplace_back(out);
      return;
    }
    for (int i = start; i < s.size(); ++i) {
      if (isPalindrome(s, start, i)) {
        out.emplace_back(s.substr(start, i - start + 1));
        partitionDFS(s, i + 1, out, res);
        out.pop_back();
      }
    }
  }

  bool isPalindrome(string s, int left, int right) {
    while (left < right) {
      if (s[left++] != s[right--]) return false;
    }
    return true;
  }
};
```

果然不能简单的照搬另外一道题目来轻微修改就能够得到结果的。

## Solution2
<!-- TODO: I need to understand this question more deeply. -->
```cpp
class Solution {
 public:
  int minCut(string s) {
    //
    const int n = s.size();
    int f[n + 1];
    bool p[n][n];
    fill_n(&p[0][0], n * n, false);
    for (int i = 0; i <= n; ++i) {
      f[i] = n - 1 - i;  // eg. n-1, n-2, n-3, ... 0, -1
    }

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
          p[i][j] = true;
          f[i] = min(f[i], f[j + 1] + 1);
        }
      }
    }
    return f[0];
  }
};
```

------------
