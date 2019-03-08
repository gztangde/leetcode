---
title: Leetcode 76. Minimum Window Substring
date: 2019-02-05 15:58:46
updated: 2019-02-05 15:58:46
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

**Example:**

**Input: S** = "ADOBECODEBANC", **T** = "ABC"
**Output:** "BANC"

**Note:**

- If there is no such window in S that covers all characters in T, return the empty string  `""`.
- If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

**Difficulty**:Medium

**Category**:Hard

<!-- more -->

------------

# Analyze

# Solution

```cpp
class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> r(128, 0);
    string ans;
    for (char& c : t) ++r[c];
    int left = 0, cnt = 0, n = t.length(), diff = INT_MAX;
    for (int right = 0; right < s.size(); ++right) {
      if (--r[s[right]] >= 0) cnt++;
      while (cnt == n) {
        if (diff > right - left + 1) {
          diff = right - left + 1;
          ans = s.substr(left, diff);
        }
        if (++r[s[left]] > 0) --cnt;
        ++left;
      }
    }
    return ans;
  }
};
```

# Relative Questions

* [Leetcode 632. Smallest Range](./Leetcode-632-Smallest-Range/)