---
title: Leetcode 44. Wildcard-Matching
date: 2018-06-18 11:50:32
updated: 2018-06-18 11:50:32
categories: Leetcode
tags: Leetcode
notshow: true
---

Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for  `'?'`  and  `'*'`.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the  **entire**  input string (not partial).

**Note:**

- `s` could be empty and contains only lowercase letters  `a-z`.
- `p`  could be empty and contains only lowercase letters  `a-z`, and characters like  `?` or `*`.

<!--more-->

**Example 1:**

> **Input:**
> s = "aa"
> p = "a"
> **Output:** false
> **Explanation:** "a" does not match the entire string "aa".

**Example 2:**

> **Input:**
> s = "aa"
> p = "*"
> **Output:** true
> **Explanation:** '*' matches any sequence.

**Example 3:**

>**Input:**
s = "cb"
p = "?a"
**Output:** false
**Explanation:** '?' matches 'c', but the second letter is 'a', which does not match 'b'.

**Example 4:**

>**Input:**
s = "adceb"
p = "*a*b"
**Output:** true
**Explanation:** The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

**Example 5:**

>**Input:**
s = "acdcb"
p = "a*c?b"
**Output:** false

**Difficulty**:Hard

**Category**:

<!--more-->

*****

# Analyze

使用贪婪算法 Greedy 求解，由于有特殊字符*和？，其中？能代替任何字符，*能代替任何字符串，那么我们需要定义几个额外的指针，其中 scur 和 pcur 分别指向当前遍历到的字符，再定义 pstar 指向p中最后一个*的位置，sstar指向此时对应的 s 的位置，具体算法如下：

- 定义scur, pcur, sstar, pstar

- 如果*scur存在

- 如果 `*scur == *pcur`或者 pcur 为 '?'，则 scur 和 pcur 都自增1

- 如果`*pcur == '*'`，则 pstar 指向 pcur 位置， pcur 自增1，且 sstar 指向scur

- 如果pstar存在，则pcur指向pstar的下一个位置，scur指向sstar自增1后的位置

- 如果pcur为'*'，则pcur自增1

- 若*pcur存在，返回False，若不存在，返回True

# Solution

```cpp
class Solution {
 public:
  bool isMatch(char *s, char *p) {
    char *scur = s, *pcur = p, *sstar = NULL, *pstar = NULL;
    while (*scur) {
      if (*scur == *pcur || *pcur == '?') {
        ++scur;
        ++pcur;
      } else if (*pcur == '*') {
        pstar = pcur++;
        sstar = scur;
      } else if (pstar) {
        pcur = pstar + 1;
        scur = ++sstar;
      } else
        return false;
    }
    while (*pcur == '*') ++pcur;
    return !*pcur;
  }
};
```