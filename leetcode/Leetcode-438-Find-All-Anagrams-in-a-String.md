---
title: Leetcode 438. Find All Anagrams in a String
date: 2019-01-25 17:55:10
updated: 2019-01-25 17:55:10
categories: 
- [Leetcode]
- [Leetcode, ]
tags: Leetcode
notshow: true
top:
---

# Question

Given a string  **s**  and a  **non-empty**  string  **p**, find all the start indices of  **p**'s anagrams in  **s**.

Strings consists of lowercase English letters only and the length of both strings  **s**  and  **p**  will not be larger than 20,100.

The order of output does not matter.

**Example 1:**

```
**Input:**
s: "cbaebabacd" p: "abc"

**Output:**
[0, 6]

**Explanation:**
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```

**Example 2:**

```
**Input:**
s: "abab" p: "ab"

**Output:**
[0, 1, 2]

**Explanation:**
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
```

**Difficulty**:Easy

**Category**:Hash-Table

<!-- more -->

------------

# Analyze

# Solution

```cpp
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> count(26, 0), rec(26, 0), ans;
    int len = p.length();
    for (char& c : p) ++count[c - 'a'];
    for (int i = 0; i < s.length(); ++i) {
      if (i >= len) --rec[s[i - len] - 'a'];
      ++rec[s[i] - 'a'];
      // Check the equal
      if (rec == count) ans.emplace_back(i - len + 1);
    }
    return ans;
  }
};
```


