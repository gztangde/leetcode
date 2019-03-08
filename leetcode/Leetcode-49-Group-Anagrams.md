---
title: Leetcode 49. Group Anagrams
date: 2019-02-04 15:40:00
updated: 2019-02-04 15:40:00
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given an array of strings, group anagrams together.

**Example:**

**Input:** `["eat", "tea", "tan", "ate", "nat", "bat"]`,
**Output:**
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

**Note:**

- All inputs will be in lowercase.
- The order of your output does not matter.

**Difficulty**:Easy

**Category**:Hash-Table, String

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> rec;
    for (string& s : strs) {
      string temp = s;
      sort(temp.begin(), temp.end());
      rec[temp].push_back(s);
    }

    vector<vector<string>> ans;
    for (auto& m : rec) ans.emplace_back(m.second);
    return ans;
  }
};
```