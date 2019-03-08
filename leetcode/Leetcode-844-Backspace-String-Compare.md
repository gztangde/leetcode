---
title: Leetcode 844. Backspace String Compare
date: 2019-02-06 00:37:00
updated: 2019-02-06 00:37:00
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given two strings `S` and  `T`, return if they are equal when both are typed into empty text editors.  `#`  means a backspace character.

**Example 1:**

**Input:** S = "ab#c", T = "ad#c"
**Output:** true **Explanation**: Both S and T become "ac".

**Example 2:**

**Input:** S = "ab##", T = "c#d#"
**Output:** true **Explanation**: Both S and T become "".

**Example 3:**

**Input:** S = "a##c", T = "#a#c"
**Output:** true **Explanation**: Both S and T become "c".

**Example 4:**

**Input:** S = "a#c", T = "b"
**Output:** false **Explanation**: S becomes "c" while T becomes "b".

**Note**:

1.  `1 <= S.length <= 200`
2.  `1 <= T.length <= 200`
3.  `S` and  `T`  only contain lowercase letters and  `'#'`  characters.

**Follow up:**

-   Can you solve it in  `O(N)`  time and  `O(1)`  space?

**Difficulty**:Easy

**Category**:

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    stack<char> l, r;
    for (char& c : S) {
      if (c >= 'a' && c <= 'z')
        r.push(c);
      else {
        if (!r.empty()) r.pop();
      }
    }
    for (char& c : T) {
      if (c >= 'a' && c <= 'z')
        l.push(c);
      else {
        if (!l.empty()) l.pop();
      }
    }
    if (l.size() != l.size())
      return false;
    else {
      while (!l.empty() && l.top() == r.top()) {
        l.pop();
        r.pop();
      }
      if (!l.empty() || !r.empty()) return false;
    }
    return true;
  }
};
```