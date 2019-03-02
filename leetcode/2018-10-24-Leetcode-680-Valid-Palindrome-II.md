---
title: C++ 变量的初始化问题
date: 2018-09-11 02:09:31
updated: 2018-09-11 02:09:31
categories: C++
tags: C++
top:
---

# Question

Given a non-empty string  `s`, you may delete  **at most**  one character. Judge whether you can make it a palindrome.

**Example 1:**  

**Input:** "aba"
**Output:** True

**Example 2:**  

**Input:** "abca"
**Output:** True
**Explanation:** You could delete the character 'c'.

**Note:**  

1. The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

<!--more-->

-------

# Solution

```cpp
class Solution {
 public:
  bool validPalindrome(string s) {
    int n = s.length();
    int left = 0, right = n - 1;
    while (left < right) {
      if (s[left++] != s[right--]) return isPalindromic(s, left, right + 1) || isPalindromic(s, left - 1, right);
    }
    return true;
  }

 private:
  bool isPalindromic(string s, int left, int right) {
    while (left < right) {
      if (s[left++] != s[right--]) return false;
    }
    return true;
  }
};
```