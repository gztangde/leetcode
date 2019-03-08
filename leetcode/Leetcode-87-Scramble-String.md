---
title: Leetcode 87. Scramble String
date: 2018-12-22 09:09:31
updated: 2018-12-22 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a string  _s1_, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of  _s1_  =  `"great"`:
![](/images/in-post/2018-12-22-Leetcode-87-Scramble-String/2018-12-22-23-12-04.png)

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node  `"gr"`  and swap its two children, it produces a scrambled string  `"rgeat"`.
![](/images/in-post/2018-12-22-Leetcode-87-Scramble-String/2018-12-22-23-12-35.png)

We say that  `"rgeat"`  is a scrambled string of  `"great"`.

Similarly, if we continue to swap the children of nodes  `"eat"`  and  `"at"`, it produces a scrambled string  `"rgtae"`.
![](/images/in-post/2018-12-22-Leetcode-87-Scramble-String/2018-12-22-23-12-55.png)

We say that  `"rgtae"`  is a scrambled string of  `"great"`.

Given two strings  _s1_  and  _s2_  of the same length, determine if  _s2_  is a scrambled string of  _s1_.

**Example 1:**

> **Input:** s1 = "great", s2 = "rgeat"
> **Output:** true

**Example 2:**

> **Input:** s1 = "abcde", s2 = "caebd"
> **Output:** false

**Difficulty**:Hard

**Category**:String, Dynamic-Programming

<!-- more -->

# Analyze

# Solution

## Solution 1

递归的方案。

```cpp
class Solution {
 public:
  bool isScramble(string s1, string s2) {
    // 1. Exclude option
    if (s1.length() != s2.length()) return false;
    if (s1 == s2) return true;

    // 2. Exclude the sort(s1)!=sort(s2)
    string str1 = s1, str2 = s2;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if (str1 != str2) return false;

    // 3. Recursion
    for (unsigned int i = 1; i < s1.length(); ++i) {
      string s11 = s1.substr(0, i), s12 = s1.substr(i);
      string s21 = s2.substr(0, i), s22 = s2.substr(i);
      if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
      s21 = s2.substr(s1.length() - i);
      s22 = s2.substr(0, s1.length() - i);
      if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
    }
    return false;
  }
};
```

<!-- TODO:使用动态方案的方式来完成 -->