---
title: Leetcode 5. Longest Palindromic Substring
date: 2018-06-10 02:44:02
updated: 2018-06-10 02:44:02
categories: Leetcode
tags: Leetcode
---

# Question

Given a string  **s**, find the longest palindromic substring in  **s**. You may assume that the maximum length of  **s**  is 1000.

**Example 1:**
> **Input:** "babad"  
> **Output:** "bab"  
> **Note:** "aba" is also a valid answer.

**Example 2:**
> **Input:** "cbbd"  
> **Output:** "bb"

**Difficulty**:Medium

**Category**:String

<!--more-->
*****

# Analyze

这道题让我们求的是最长回文串，那么什么是回文串呢？
> “回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。  

那么这道题，我们要求解最长的回文串的话，可以使用对称验证的方式进行判断，对称验证有两种情况，回文串长度为奇数或者为偶数。如果回文串长度为奇数，那么是以一个字符作为中心的，如果回文串的长度为偶数，那么是以两个相同的字符来作为中心的。分为这两种情况分别进行遍历查找。

*****

# Solution

> C++实现  

```cpp
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s == "") return s;
    int start = 0, left = 0, right = 0, len = 0;

    for (int i = 0; i < s.size() - 1; ++i) {
      if (s[i] == s[i + 1]) {
        left = i;
        right = i + 1;
        searchPalindromicSubstring(s, left, right, start, len);
      }
      left = right = i;
      searchPalindromicSubstring(s, left, right, start, len);
    }

    if (len == 0) len = s.size();
    return s.substr(start, len);
  }

  void searchPalindromicSubstring(string s, int left, int right, int &start, int &len) {
    int diff = 1;

    while ((left - diff) >= 0 && (right + diff) < s.size()) {
      if (s[left - diff] != s[right + diff]) break;
      ++diff;
    }

    int wide = right - left + 2 * diff - 1;
    if (len < wide) {
      len = wide;
      start = left - diff + 1;
    }
  }
};
```

## Solution 2: Greedy

贪婪算法，对每一个位置分别向两边扩展，计算能够扩展得到的最长回文字符。

```cpp
#include <iostream>
#include <string>

string longestPalindrome(string s) {
  int best_len = 0;
  int start = 0;
  for (int i = 0; i < s.length(); ++i) {
    // e.g. aba, abba
    int l1 = getLen(s, i, i);
    int l2 = getLen(s, i, i + 1);
    int l = max(l1, l2);
    if (l > best_len) {
      best_len = l;
      start = i - (l - 1) / 2; // Get the start index, i is the medium index, And l is the len
    }
  }
  return s.substr(start, best_len); // Get the substr in [start, best_len]
}

// Get the palindrome len from the medium to both sides.
int getLen(const string& s, int l, int r) {
  if (s[l] != s[r]) return 1;
  while (l >= 0 && r <= s.length() - 1 && s[l] == s[r]) {
    --l;
    ++r;
  };
  return r - l - 1;
}
```