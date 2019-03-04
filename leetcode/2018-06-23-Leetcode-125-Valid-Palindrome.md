---
title: Leetcode 125. Valid palindrome
date: 2018-06-23 15:09:31
updated: 2018-06-23 15:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

**Example 1:**
> Input: "A man, a plan, a canal: Panama"
> Output: true

**Example 2:**
> Input: "race a car"
> Output: false

**Difficulty**:Easy

**Category**:

<!--more-->
******

# Solution

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
      int left = 0, right = s.length();
      while (left <= right) {
        if (!isalpha(s[left]) && !isdigit(s[left])) ++left;
        else if (!isalpha(s[right]) && !isdigit(s[right])) --right;
        else if ((s[left] | (1 << 5)) != (s[right] | (1 << 5))) return false;
        else {
          ++left;
          --right;
        }
      }
      return true;
    }
};
```

使用两根指针遍历整个字符串即可, 假定有指针i, j, 其中i是从前往后遍历, j是从后往前遍历. 当i在j左边时继续循环, 每一次将i右移到数字/字母上, j左移到数字/字母上, 比较二者对应的字符串内的字符是否相同,不相同则原字符串不是回文串. 如果全部的比较都相同, 说明是回文串.

```cpp
class Solution {
 public:
  bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    // Move to the
    while (left < right) {
      while (left < s.length() && !isdigit(s[left]) && !isalpha(s[left])) ++left;
      while (right >= 0 && !isdigit(s[right]) && !isalpha(s[right])) --right;

      if (left == s.length()) return true;

      if (tolower(s[left++]) != tolower(s[right--])) return false;
    }
    return true;
  }
};
```