---
title: Leetcode 20. Valid Parentheses
date: 2018-09-14 14:09:31
updated: 2018-09-14 14:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a string containing just the characters  `'('`,  `')'`,  `'{'`,  `'}'`,  `'['`  and  `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

**Example 1:**
> **Input:** "()"
> **Output:** true

**Example 2:**
> **Input:** "()[]{}"
> **Output:** true

**Example 3:**
> **Input:** "(]"
> **Output:** false

**Example 4:**
> **Input:** "([)]"
> **Output:** false

**Example 5:**
> **Input:** "{[]}"
> **Output:** true

**Difficulty**:Easy

**Category**:Stack, String

<!--more-->

----

# Analyze

验证输入的字符串是否为括号字符串，包括大括号，中括号和小括号。在这里使用一个栈来实现, 如果扫描到的是左边的括号`(,{,[`, 那么就把其压入到栈中，之后如果扫描到的不是左边的符号的话，那么就把堆栈最上面的数据出栈，然后如果出栈的数据是对应的右括号的话，那么就`pop` 出栈这个数据，如果不是对应的有括号，那么就返回`false`.

----

# Solution

```cpp
class Solution {
 public:
  bool isValid(string s) {
    std::stack<char> parentheses;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        parentheses.push(s[i]);
      else {
        if (parentheses.empty()) return false;
        if (s[i] == ')' && parentheses.top() != '(') return false;
        if (s[i] == '}' && parentheses.top() != '{') return false;
        if (s[i] == ']' && parentheses.top() != '[') return false;
        parentheses.pop();
      }
    }
    return parentheses.empty();
  }
};
```

换一种方式,判断是否满足全部也可以,但是这样时间复杂度是`O(n)`

```cpp
class Solution {
 public:
  bool isValid(string s) {
    stack<char> s_;
    for (int i = 0; i < s.length(); ++i) {
      if (s_.empty()) {
        s_.push(s[i]);
        continue;
      }
      if (s_.top() == '(' && s[i] == ')')
        s_.pop();
      else if (s_.top() == '[' && s[i] == ']')
        s_.pop();
      else if (s_.top() == '{' && s[i] == '}')
        s_.pop();
      else
        s_.push(s[i]);
    }

    if (s_.empty()) return true;
    return false;
  }
};
```

------

# Similar Questions

* [Different Ways to Add Parentheses](./Leetcode-241-Different-Ways-to-Add-Parentheses.md)
* [Longest Valid Parentheses](./Leetcode-32-Longest-Valid-Parentheses.md)
* [Generate Parentheses](./Leetcode-22-Generate-Parentheses.md)

-------

# updated

* 01/28/2019 Add the second Solution