---
title: Leetcode 349. Intersection of Two Arrays
date: 2018-12-16 09:09:31
updated: 2018-12-16 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question


Given two strings  _s_  and  _t_ , write a function to determine if  _t_  is an anagram of  _s_.

**Example 1:**

> **Input:** _s_ = "anagram", _t_ = "nagaram"
> **Output:** true

**Example 2:**

> **Input:** _s_ = "rat", _t_ = "car"
> **Output:** false

**Note:**  
You may assume the string contains only lowercase alphabets.

**Follow up:**  
What if the inputs contain unicode characters? How would you adapt your solution to such case?

**Difficulty**:Easy
**Category**:Sort, Hash-Table

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    int count[26] = {0};
    for (char c : s) count[c - 'a']++;
    for (char c : t) count[c - 'a']--;
    for (int i = 0; i < 26; ++i) {
      if (count[i] != 0) return false;
    }
    return true;
  }
};
```