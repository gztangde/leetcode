---
title: Leetcode 161. One Edit Distance
date: 2019-03-09 20:57:09
updated: 2019-03-09 20:57:09
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Question

Given two strings S and T, determine if they are both one edit distance apart.

**Difficulty**:Medium

**Category**:

# Analyze

判断两个字符串的编辑距离(删除或替代)是否为1，分三种情况考虑：

1. 两个字符串的长度之差大于1，那么直接返回False
2. 两个字符串的长度之差等于1，那么长的那个字符串去掉一个字符，剩下的应该和短的字符串相同(删除的方式)
3. 两个字符串的长度之差等于0，那么两个字符串对应位置的字符只能有一处不同，也不能完全相同(替换的方式得到相同字符串)。

# Solution

```cpp
class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    if (s.size() < t.size()) swap(s, t);
    int m = s.size(), n = t.size(), diff = m - n;
    if (diff >= 2) return false;
    else if (diff == 1) {
      for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
          // There are one char we don't need
          return s.substr(i + 1) == t.substr(i);
        }
      }
      return true;
    } else {
      int cnt = 0;
      for (int i = 0; i < m; ++i) {
        if (s[i] != t[i]) ++cnt;
      }
      return cnt == 1;
    }
  }
};
```

我们实际上可以让代码写的更加简洁，只需要对比两个字符串对应位置上的字符，如果遇到不同的时候，这时我们看两个字符串的长度关系，如果相等，那么我们比较当前位置后的字串是否相同，如果s的长度大，那么我们比较s的下一个位置开始的子串，和t的当前位置开始的子串是否相同，反之如果t的长度大，那么我们比较t的下一个位置开始的子串，和s的当前位置开始的子串是否相同。如果循环结束，都没有找到不同的字符，那么此时我们看两个字符串的长度是否相差1，参见代码如下：

```cpp
class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    for (int i = 0; i < min(s.size(), t.size()); ++i) {
      if (s[i] != t[i]) {
        if (s.size() == t.size())
          return s.substr(i + 1) == t.substr(i + 1);
        else if (s.size() < t.size())
          return s.substr(i) == t.substr(i + 1);
        else
          return s.substr(i + 1) == t.substr(i);
      }
    }
    return abs((int)s.size() - (int)t.size()) == 1;
  }
};
```

## Follow up

如果你只能够使用 remove 的编辑方式的话，那么能不能够在最多只修改两边一个字符的情况下得到相同的字符串呢。

```cpp
class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    if (s.size() < t.size()) swap(s, t);
    int m = s.size(), n = t.size(), diff = m - n;
    if (diff >= 2) return false;
    else if (diff == 1) {
      for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
          // There are one char we don't need
          return s.substr(i + 1) == t.substr(i);
        }
      }
      return true;
    } else {
      int cnt = 0;
      for (int i = 0; i < m; ++i) {
        if (s[i] != t[i]) {
          // Remove the same index
          if (s.substr(i+1) == t.substr(i+1)) return true;
        }
      }
      return cnt == 1;
    }
  }
};
```