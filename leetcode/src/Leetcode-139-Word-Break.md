---
title: Leetcode 139. Word Break
date: 2018-12-25 09:09:31
updated: 2018-12-25 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a  **non-empty**  string  _s_  and a dictionary  _wordDict_  containing a list of  **non-empty**  words, determine if  _s_  can be segmented into a space-separated sequence of one or more dictionary words.

**Note:**

- The same word in the dictionary may be reused multiple times in the segmentation.
- You may assume the dictionary does not contain duplicate words.

**Example 1:**

> **Input:** s = "leetcode", wordDict = ["leet", "code"]
> **Output:** true
> **Explanation:** Return true because `"leetcode"` can be segmented as `"leet code"`.

**Example 2:**

> **Input:** s = "applepenapple", wordDict = ["apple", "pen"]
> **Output:** true
> **Explanation:** Return true because `"`applepenapple`"` can be segmented as `"`apple pen apple`"`. Note that you are allowed to reuse a dictionary word.

**Example 3:**

> **Input:** s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
> **Output:** false

**Difficulty**:Medium

**Category**:Dynamic-Programming

<!-- more -->

# Solution

# Solution１:Error--Time Limit Exceeded---DFS

```cpp
// 时间复杂度：　O(２＾ｎ)
// 空间复杂度：　Ｏ(n)
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    return dfs(s, dict, 0, 0);
  }

  bool dfs(const string& s, unordered_set<string>& dict, size_t start, size_t cur) {
    // 1) Output node
    if (cur == s.size()) {
      if (dict.find(s.substr(start, cur - start + 1)) != dict.end())
        return true;
      else
        return false;
    }
    if (dict.find(s.substr(start, cur - start + 1)) != dict.end())
      if (dfs(s, dict, cur + 1, cur + 1)) return true;

    if (dfs(s, dict, start, cur + 1)) return true;
    return false;
  }
};
```

## Solution 2: 动态规划: DP

```cpp
// Runtime: 4ms
// f[i] is mean the word can divide at the i index position.
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> w_(wordDict.begin(), wordDict.end());
    int len = s.size();
    vector<bool> f(len + 1, false);
    f[0] = true;
    for (int i = 1; i <= len; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (f[j] && w_.find(s.substr(j, i - j)) != w_.end()) {
          f[i] = true;
          break;
        }
      }
    }
    return f[len];
  }
};
```