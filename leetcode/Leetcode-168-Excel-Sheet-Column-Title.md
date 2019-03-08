---
title: Leetcode 168. Excel Sheet Column Title
date: 2019-01-22 17:11:48
updated: 2019-01-22 17:11:48
categories: 
- [Leetcode]
- [Leetcode, ]
tags: Leetcode
notshow: true
top:
---

# Question

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

```
For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
```

**Example 1:**

> **Input:** 1
> **Output:** "A"

**Example 2:**

> **Input:** 28
> **Output:** "AB"

**Example 3:**

> **Input:** 701
> **Output:** "ZY"

**Difficulty**:Easy

**Category**:

<!-- more -->

------------

# Analyze

# Solution

```cpp
class Solution {
 public:
  string convertToTitle(int n) {
    string ans = "";
    while (n > 0) {
      n -= 1;
      char temp = 'A' + n % 26;
      n = n / 26;
      ans = temp + ans;
    }
    return ans;
  }
};
```


