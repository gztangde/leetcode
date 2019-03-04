---
title: Leetcode 17. Letter Combinations of a Phone Number
date: 2019-02-17 22:55:01
updated: 2019-02-17 22:55:01
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Leetcode 17. Letter Combinations of a Phone Number

Given a string containing digits from  `2-9`  inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![](http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

**Example:**

**Input:** "23"
**Output:** ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

**Note:**

Although the above answer is in lexicographical order, your answer could be in any order you want.

**Difficulty**:Medium

**Category**:

<!-- more -->

# Solution

## Solution 1: DFS

```cpp
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans;
    string cur;
    string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    letterCombinationsDFS(digits, dict, 0, cur, ans);
    return ans;
  }
  void letterCombinationsDFS(const string& digits, string dict[], int index, string& out, vector<string>& ans) {
    if (index == digits.length()) {
      ans.emplace_back(out);
      return;
    }
    for (char c : dict[digits[index] - '0']) {
      out.push_back(c);
      letterCombinationsDFS(digits, dict, index + 1, out, ans);
      out.pop_back();
    }
  }
};
```

## Solution 2: BSF

这一种解法来自于: [花花酱 LeetCode 17. Letter Combinations of a Phone Number](http://zxi.mytechroad.com/blog/searching/leetcode-17-letter-combinations-of-a-phone-number/)

在这一种解法里面, 使用到了一种API. ans.swap(temp) , 可以用来交换两个 `vector`.

在这里需要的是將 ans 付一个初值， 这样才能够进入循环进行计算 `for (char& digit : digits)`

```cpp
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans = {""};
    string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for (char& digit : digits) {
      vector<string> temp;
      for (string s : ans) {
        for (char& c : dict[digit - '0']) {
          temp.emplace_back(s + c);
        }
      }
      ans.swap(temp);
    }
    return ans;
  }
};
```

# Update

03/01/2019 Review (BSF: 10 mins, DFS: 8mins)