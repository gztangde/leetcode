---
title: Leetcode 884. Uncommon Words from Two Sentences
date: 2019-01-10 10:05:49
updated: 2019-01-10 10:05:49
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

We are given two sentences  `A`  and  `B`. (A  _sentence_ is a string of space separated words. Each  _word_  consists only of lowercase letters.)

A word is  _uncommon_ if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words.

You may return the list in any order.

**Example 1:**

> **Input:** A = "this apple is sweet", B = "this apple is sour"
> **Output:** ["sweet","sour"]

**Example 2:**

> **Input:** A = "apple apple", B = "banana"
> **Output:** ["banana"]

**Note:**

1.  `0 <= A.length <= 200`
2.  `0 <= B.length <= 200`
3.  `A`  and  `B`  both contain only spaces and lowercase letters.

**Difficulty**:Medium

**Category**:Hash-Table

<!-- more -->

------------

# Analyze

这道题目要求求解在两个`string`的句子里面，只出现过一次的单词，將两个`string`里面的单词全部放在`unordered_map`中统计各个单词的数量，然后输出只出现了一次的单词即可。

------------

# Solution

```cpp
// Runtime: 4ms
class Solution {
 public:
  vector<string> uncommonFromSentences(string A, string B) {
    vector<string> ans;
    unordered_map<string, int> rec;
    for (int i = 0; i < A.length(); ++i) {
      string temp;
      while (islower(A[i])) temp += A[i++];
      rec[temp]++;
      // rec.count(temp) ? rec[temp]++ : rec[temp] = 1;
    }

    for (int i = 0; i < B.length(); ++i) {
      string temp;
      while (islower(B[i])) temp += B[i++];
      rec[temp]++;
    }

    for (auto& a : rec)
      if (a.second == 1) ans.emplace_back(a.first);

    return ans;
  }
};
```
