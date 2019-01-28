---
title: Leetcode 917. Reverse Only Letters
date: 2019-01-10 01:12:19
updated: 2019-01-10 01:12:19
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a string  `S`, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

**Example 1:**

> **Input:** "ab-cd"
> **Output:** "dc-ba"

**Example 2:**

> **Input:** "a-bC-dEf-ghIj"
> **Output:** "j-Ih-gfE-dCba"

**Example 3:**

> **Input:** "Test1ng-Leet=code-Q!"
> **Output:** "Qedo1ct-eeLg=ntse-T!"

**Note:**

1. `S.length <= 100`
2. `33 <= S[i].ASCIIcode <= 122`
3. `S`  doesn't contain  `\`  or  `"`

**Difficulty**:Easy

**Category**:String

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
// Solution: Two Points
// Runtimes: 4ms
class Solution {
 public:
  string reverseOnlyLetters(string S) {
    if (S.length() == 0) return "";
    int left = 0, right = S.length() - 1;

    while (left < right) {
      while (!isalpha(S[left])) ++left;
      while (!isalpha(S[right])) --right;
      if (left >= right) break;
      swap(S[left++], S[right--]);
    }
    return S;
  }
};
```