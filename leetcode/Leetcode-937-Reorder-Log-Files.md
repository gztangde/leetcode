---
title: Leetcode 937. Reorder Log Files
date: 2019-02-04 12:53:39
updated: 2019-02-04 12:53:39
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

You have an array of  `logs`. Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric  _identifier_. Then, either:

- Each word after the identifier will consist only of lowercase letters, or;
- Each word after the identifier will consist only of digits.

We will call these two varieties of logs  _letter-logs_  and  _digit-logs_. It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log. The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties. The digit-logs should be put in their original order.

Return the final order of the logs.

**Example 1:**

**Input:** ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
**Output:** ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]

**Note:**

1. `0 <= logs.length <= 100`
2. `3 <= logs[i].length <= 100`
3. `logs[i]`  is guaranteed to have an identifier, and a word after the identifier.

**Difficulty**:Easy

**Category**:

<!-- more -->

------------

# Analyze

Log的格式是第一个单词是Log的索引，后面的都是Log的内容。有两种Log，一种内容是纯数字的，一种内容是纯英文字符的。现在要求，把所有的英文Log放到数字Log前面。而且如果是纯英文的字符Log，需要按照内容对Log进行排序，当内容相同的时候按照索引排序；如果是数字Log，保持原来的顺序。

# Solution

```cpp
bool myCompare(string a, string b) {
  int i = a.find(' ');
  int j = b.find(' ');
  if (!isdigit(a[i + 1]) && !isdigit(b[j + 1]))
    return a.substr(i + 1) < b.substr(j + 1);
  else {
    if (!isdigit(a[i + 1])) return true;
    return false;
  }
}
class Solution {
 public:
  vector<string> reorderLogFiles(vector<string>& logs) {
    stable_sort(logs.begin(), logs.end(), myCompare);
    return logs;
  }
};
```