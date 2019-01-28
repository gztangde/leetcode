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

------------

# Analyze

------------

# Solution

```cpp
// Runtime: 4ms
class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans;
    lcp(S, 0, ans);
    return ans;
  }

  void lcp(string& s, int p, vector<string>& ans) {
    if (p == s.length()) {
      ans.emplace_back(s);
      return;
    }
    lcp(s, p + 1, ans);
    if (!isalpha(s[p])) return;
    isupper(s[p]) ? s[p] = std::tolower(s[p]) : s[p] = std::toupper(s[p]);
    lcp(s, p + 1, ans);
  }
};
```