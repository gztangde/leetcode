---
title: Leetcode 318. Maximum Product of Word Lengths
date: 2019-02-09 17:04:18
updated: 2019-02-09 17:04:18
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a string array  `words`, find the maximum value of  `length(word[i]) * length(word[j])`  where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

**Example 1:**

**Input:** `["abcw","baz","foo","bar","xtfn","abcdef"]`
**Output:** `16 
**Explanation:**` The two words can be `"abcw", "xtfn"`.

**Example 2:**

**Input:** `["a","ab","abc","d","cd","bcd","abcd"]`
**Output:** `4 
**Explanation:**` The two words can be `"ab", "cd"`.

**Example 3:**

**Input:** `["a","aa","aaa","aaaa"]`
**Output:** `0 
**Explanation:**` No such pair of words.

**Difficulty**:Medium

**Category**:Bit-Manipulation

<!-- more -->

------------

# Analyze

题目描述：字符串数组的字符串只含有小写字符。求解字符串数组中两个字符串长度的最大乘积，要求这两个字符串不能含有相同字符。

本题主要问题是判断两个字符串是否含相同字符，由于字符串只含有小写字符，总共 26 位，因此可以用一个 32 位的整数来存储每个字符是否出现过。

------------

# Solution

```cpp
class Solution {
 public:
  int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
      for (char& c : words[i]) {
        v[i] |= (1 << (c - 'a'));
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if ((v[i] & v[j]) == 0) {
          int a = words[i].length(), b = words[j].length();
          ans = max(ans, a * b);
        }
      }
    }
    return ans;
  }
};
```