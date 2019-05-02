---
title: Leetcode 720. Longest Word in Dictionary
date: 2019-01-25 23:27:35
updated: 2019-01-25 23:27:35
categories: 
- [Leetcode]
- [Leetcode, Hash-Table]
- [Leetcode, Trie]
tags: Leetcode
notshow: true
top:
---

# Question

Given a list of strings  `words`  representing an English Dictionary, find the longest word in  `words`  that can be built one character at a time by other words in  `words`. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.

**Example 1:**  

> **Input:** 
> words = ["w","wo","wor","worl", "world"]
> **Output:** "world"
> **Explanation:** 
> The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

**Example 2:**  

> **Input:** 
> words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
> **Output:** "apple"
> **Explanation:** 
> Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

**Note:**

- All the strings in the input will only contain lowercase letters.
- The length of  `words`  will be in the range  `[1, 1000]`.
- The length of  `words[i]`  will be in the range  `[1, 30]`.

**Difficulty**:Easy

**Category**:Hash-Table, Trie

<!-- more -->

# Solution

```cpp
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans;
    string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    letterCombinationsDFS(digits, dict, 0, "", ans);
    return ans;
  }

 private:
  void letterCombinationsDFS(const string& digits, string dict[], int index, string out, vector<string>& ans) {
    if (index == digits.size()) {
      ans.emplace_back(out);
      return;
    }
    string str = dict[digits[index] - '0'];
    for (int i = 0; i < str.length(); ++i) {
      letterCombinationsDFS(digits, dict, index + 1, out + str[i], ans);
    }
  }
};
```


