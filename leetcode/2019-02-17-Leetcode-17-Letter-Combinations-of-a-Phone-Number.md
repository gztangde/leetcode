---
title: Leetcode 17. Letter Combinations of a Phone Number
date: 2019-02-17 22:55:01
updated: 2019-02-17 22:55:01
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

**Difficulty**:Medium

**Category**:

<!-- more -->

------------

# Analyze

------------

# Solution

## Solution 1: DFS

```cpp
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans;
    string cur;
    string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    letterCombinationsDFS(digits, dict, 0, cur, ans);
    return ans;
  }
  void letterCombinationsDFS(const string& digits, string dict[], int index, string& out, vector<string>& ans) {
    if (index == digits.length()) {
      ans.emplace_back(out);
      return;
    }
    for (char c : dict[digits[index] - '0']) {
      out.push_back(c);
      letterCombinationsDFS(digits, dict, index + 1, out, ans);
      out.pop_back();
    }
  }
};
```

## Solution 2: BSF

这一种解法来自于: [花花酱 LeetCode 17. Letter Combinations of a Phone Number](http://zxi.mytechroad.com/blog/searching/leetcode-17-letter-combinations-of-a-phone-number/)

在这一种解法里面, 使用到了一种API. ans.swap(temp) , 可以用来交换两个 `vector`.

```cpp
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans = {""};
    string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for (char& digit : digits) {
      vector<string> temp;
      for (string s : ans) {
        for (char& c : dict[digit - '0']) {
          temp.emplace_back(s + c);
        }
      }
      ans.swap(temp);
    }
    return ans;
  }
};
```