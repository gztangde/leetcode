---
title: Leetcode 771. Jewels and Stones
date: 2019-01-25 16:32:05
updated: 2019-01-25 16:32:05
categories: 
- [Leetcode]
- [Leetcode, Hash-Table]
tags: Leetcode
notshow: true
top:
---

# Question

You're given strings  `J`  representing the types of stones that are jewels, and  `S`representing the stones you have. Each character in  `S`  is a type of stone you have. You want to know how many of the stones you have are also jewels.

The letters in  `J`  are guaranteed distinct, and all characters in  `J`  and  `S`  are letters. Letters are case sensitive, so  `"a"`  is considered a different type of stone from  `"A"`.

**Example 1:**

**Input:** J = "aA", S = "aAAbbbb"
**Output:** 3

**Example 2:**

**Input:** J = "z", S = "ZZ"
**Output:** 0

**Note:**

- `S`  and  `J`  will consist of letters and have length at most 50.
- The characters in  `J`  are distinct.

**Difficulty**:Easy

**Category**:Hash-Table

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    int ans = 0;
    unordered_map<char, int> rec;
    for (char c : J) rec.insert({c, 1});
    for (char c : S) {
      if (rec[c] == 1) ans++;
    }
    return ans;
  }
};
```


