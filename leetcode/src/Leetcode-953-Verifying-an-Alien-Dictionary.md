---
title: Leetcode 953. Verifying an Alien Dictionary
date: 2019-01-08 09:09:31
updated: 2019-01-08 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different  `order`. The `order`  of the alphabet is some permutation of lowercase letters.

Given a sequence of  `words` written in the alien language, and the  `order`  of the alphabet, return  `true`  if and only if the given  `words` are sorted lexicographicaly in this alien language.

**Example 1:**

> **Input:** words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
> **Output:** true
> **Explanation:** As 'h' comes before 'l' in this language, then the sequence is sorted.

**Example 2:**

> **Input:** words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
> **Output:** false
> **Explanation:** As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

**Example 3:**

> **Input:** words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
> **Output:** false **Explanation:** The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character ([More info](https://en.wikipedia.org/wiki/Lexicographical_order)).

**Note:**

1. `1 <= words.length <= 100`
2. `1 <= words[i].length <= 20`
3. `order.length == 26`
4. All characters in  `words[i]`  and  `order`  are english lowercase letters.

**Difficulty**:Easy

**Category**:Hash-Table

# Solution

Time complexity: O(n)
Space complexity: O(n)

```cpp
class Solution {
 public:
  bool isAlienSorted(vector<string>& words, string order) {
    vector<char> m(26);
    // Build the map table
    for (int i = 0; i < 26; ++i) m[order[i] - 'a'] = 'a' + i;

    // Transfer the Alien dictinoary to the normal dictionary
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words[i].length(); ++j) {
        words[i][j] = m[words[i][j] - 'a'];
      }
      if (i > 0 && words[i] < words[i - 1]) return false;
    }
    return true;
  }
};
```
