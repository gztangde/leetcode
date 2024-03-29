---
title: Leetcode 791. Custom Sort String(Not Do)
date: 2018-10-22 19:09:31
updated: 2018-10-22 19:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

`S`  and  `T`  are strings composed of lowercase letters. In  `S`, no letter occurs more than once.

`S`  was sorted in some custom order previously. We want to permute the characters of  `T`  so that they match the order that  `S`  was sorted. More specifically, if  `x`  occurs before  `y`  in  `S`, then  `x`  should occur before  `y`  in the returned string.

Return any permutation of  `T`  (as a string) that satisfies this property.

**Example :**
**Input:** 
S = "cba"
T = "abcd"
**Output:** "cbad"
**Explanation:** 
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.

**Note:**

- `S`  has length at most  `26`, and no character is repeated in  `S`.
- `T`  has length at most  `200`.
- `S`  and  `T`  consist of lowercase letters only.

<!--more-->

# Solution

```cpp
class Solution {
 public:
  string customSortString(string S, string T) {
    string ans;
    vector<int> rec(26, 0);
    for (char& c : T) rec[c - 'a']++;
    for (int i = 0; i < S.length(); ++i)
      while (rec[S[i] - 'a']--) ans += S[i];

    for (int i = 0; i < rec.size(); ++i) {
      while (rec[i] > 0) {
        ans += i + 'a';
        rec[i]--;
      }
    }
    return ans;
  }
};
```