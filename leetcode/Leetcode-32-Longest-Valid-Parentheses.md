---
title: Leetcode 32. Longest Valid Parentheses
date: 2018-11-21 06:09:31
updated: 2018-11-21 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a string containing just the characters  `'('`  and  `')'`, find the length of the longest valid (well-formed) parentheses substring.

**Example 1:**

> **Input:** "(()"
> **Output:** 2
> **Explanation:** The longest valid parentheses substring is `"()"`

**Example 2:**

> **Input:** "`)()())`"
> **Output:** 4
> **Explanation:** The longest valid parentheses substring is `"()()"`

**Difficulty**:Hard

**Category**:Dynamic Programming, String

<!-- more -->

------------

# Analyze

# Solution

```cpp
class Solution {
 public:
  int longestValidParentheses(string s) {
    int res = 0, left = 0;
    stack<int> m;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        m.push(i);
      else {
        if (m.empty())
          left = i + 1;
        else {
          m.pop();
          if (m.empty())
            res = max(res, i + 1 - left);
          else
            res = max(res, i - m.top());
        }
      }
    }
    return res;
  }
};
```