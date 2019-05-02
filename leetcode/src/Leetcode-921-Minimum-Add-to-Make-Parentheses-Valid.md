---
title: Leetcode 921. Minimum Add to Make Parentheses Valid
date: 2019-02-01 19:10:33
updated: 2019-02-01 19:10:33
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a string `S`  of  `'('`  and  `')'`  parentheses, we add the minimum number of parentheses (  `'('`  or  `')'`, and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

-   It is the empty string, or
-   It can be written as  `AB` (`A`  concatenated with  `B`), where  `A`  and  `B`  are valid strings, or
-   It can be written as  `(A)`, where  `A`  is a valid string.

Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

**Example 1:**

**Input:** "())"
**Output:** 1

**Example 2:**

**Input:** "((("
**Output:** 3

**Example 3:**

**Input:** "()"
**Output:** 0

**Example 4:**

**Input:** "()))(("
**Output:** 4

**Note:**

1. `S.length <= 1000`
2. `S`  only consists of  `'('`  and  `')'`  characters.

**Difficulty**:Medium

**Category**:

<!-- more -->

# Solution

```cpp
class Solution {
 public:
  int minAddToMakeValid(string s) {
    int ans = 0;
    stack<char> sta;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        sta.push(s[i]);
      else {
        if (sta.empty()) {
          ans++;
          continue;
        } else if (s[i] == ')' && sta.top() != '(')
          ans++;
        sta.pop();
      }
    }
    ans += sta.size();
    return ans;
  }
};
```

# Related Problems

* [Valid Parentheses](../Leetcode-20-Valid-Parentheses/)