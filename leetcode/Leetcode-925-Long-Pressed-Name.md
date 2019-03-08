---
title: Leetcode 169. Majority Element
date: 2019-01-10 09:00:33
updated: 2019-01-10 09:00:33
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Your friend is typing his  `name` into a keyboard. Sometimes, when typing a character  `c`, the key might get  _long pressed_, and the character will be typed 1 or more times.

You examine the  `typed` characters of the keyboard. Return  `True`  if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

**Example 1:**

> **Input:** name = "alex", typed = "aaleex"
> **Output:** true
> **Explanation:** 'a' and 'e' in 'alex' were long pressed.

**Example 2:**

> **Input:** name = "saeed", typed = "ssaaedd"
> **Output:** false
> **Explanation:** 'e' must have been pressed twice, but it wasn't in the typed output.

**Example 3:**

> **Input:** name = "leelee", typed = "lleeelee"
> **Output:** true

**Example 4:**

> **Input:** name = "laiden", typed = "laiden"
> **Output:** true
> **Explanation:** It's not necessary to long press any character.

**Note:**

1.  `name.length <= 1000`
2.  `typed.length <= 1000`
3.  The characters of  `name`  and  `typed`  are lowercase letters.

**Difficulty**:Easy

**Category**:Two-Points, String

<!-- more -->

# Analyze

这道题目使用两个指针分别定位`name`和`typed`，当左边和右边不相等的时候，判断是否和上一位相等，如果和`name`的上一位相等，那么指针`l`就向右移动一位。

# Solution

```cpp
// Solution: Two Points
// Runtimes: 4ms
class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    int l = 0, r = 0;
    char prev;
    while (l < name.length()) {
      if (typed[r] == name[l]) {
        prev = typed[r];
        r++;
        l++;
      } else if (typed[r] == prev) {
        r++;
      } else
        return false;
    }
    return true;
  }
};
```