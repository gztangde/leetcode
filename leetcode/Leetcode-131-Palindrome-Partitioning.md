---
title: Leetcode 131. Palindrome Partitioning
date: 2018-12-19 09:09:31
updated: 2018-12-19 09:09:31
categories: 
- [Leetcode]
- [Leetcode, 3_Backtracking]
tags: Leetcode
notshow: true
top:
---

# Question

Given a string  _s_, partition  _s_  such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of  _s_.

![](/images/in-post/2018-12-19-Leetcode-131-Palindrome-Partitioning/2018-12-19-16-11-07.png)

**Difficulty**:Medium

**Category**:Backtracking

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<string> out;
    vector<vector<string>> res;

    partitionDFS(s, 0, out, res);
    return res;
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
