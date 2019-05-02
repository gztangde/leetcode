---
title: Leetcode 784. Letter Case Permutation
date: 2019-01-10 20:32:27
updated: 2019-01-10 20:32:27
categories:
- [Leetcode]
- [Leetcode, 3_Backtracking]
- [Leetcode, 2_Bit-Manipulation]
tags: Leetcode
notshow: true
top:
---

# Question

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string. Return a list of all possible strings we could create.

**Examples:**
> **Input:** S = "a1b2"
> **Output:** ["a1b2", "a1B2", "A1b2", "A1B2"]
> **Input:** S = "3z4"
> **Output:** ["3z4", "3Z4"]
> **Input:** S = "12345"
> **Output:** ["12345"]

**Note:**
- `S`  will be a string with length between  `1`  and  `12`.
- `S`  will consist only of letters or digits.

**Difficulty**:Easy

**Category**:Backtracking, Bit-Manipulation

<!-- more -->

# Solution

##　Solution 1: DFS

```cpp
// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Letter Case Permutation.
// Memory Usage: 12.9 MB, less than 100.00% of C++ online submissions for Letter Case Permutation.
class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans;
    letterCasePermutationDFS(S, 0, ans);
    return ans;
  }
  void letterCasePermutationDFS(string& S, int index, vector<string>& ans) {
    if (index == S.length()) {
      ans.emplace_back(S);
      return;
    }
    letterCasePermutationDFS(S, index + 1, ans);
    if (!isalpha(S[index])) return;
    isupper(S[index]) ? S[index] = std::tolower(S[index]) : S[index] = std::toupper(S[index]);
    letterCasePermutationDFS(S, index + 1, ans);
  }
};
```

后面这一种解法对字母大小写转换的地方做了一些改变： 来源于博客：[花花酱 LeetCode 784. Letter Case Permutation](https://zxi.mytechroad.com/blog/searching/leetcode-784-letter-case-permutation/)

ASCII:
* Uppercase A-Z: 65 - 90
* Lowercase a-z: 97 - 122

`a` - `A` = 32, `a` ^ (1 << 5) = `A`;

```cpp
class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans;
    dfs(S, 0, ans);
    return ans;
  }

 private:
  void dfs(string& S, int s, vector<string>& ans) {
    if (s == S.length()) {
      ans.push_back(S);
      return;
    }
    dfs(S, s + 1, ans);
    if (!isalpha(S[s])) return;
    S[s] ^= (1 << 5);
    dfs(S, s + 1, ans);
    S[s] ^= (1 << 5);
  }
};
```