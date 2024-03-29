---
title: Leetcode 914. X of a Kind in a Deck of Cards
date: 2019-01-10 02:14:15
updated: 2019-01-10 02:14:15
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

In a deck of cards, each card has an integer written on it.

Return  `true`  if and only if you can choose `X >= 2`  such that it is possible to split the entire deck into 1 or more groups of cards, where:

-   Each group has exactly  `X`  cards.
-   All the cards in each group have the same integer.

**Example 1:**

> **Input:** [1,2,3,4,4,3,2,1]
> **Output:** true
> **Explanation**: Possible partition [1,1],[2,2],[3,3],[4,4]

**Example 2:**

> **Input:** [1,1,1,2,2,2,3,3]
> **Output:** false **Explanation**: No possible partition.

**Example 3:**

> **Input:** [1]
> **Output:** false **Explanation**: No possible partition.

**Example 4:**

> **Input:** [1,1]
> **Output:** true **Explanation**: Possible partition [1,1]

**Example 5:**

> **Input:** [1,1,2,2,2,2]
> **Output:** true **Explanation**: Possible partition [1,1],[2,2],[2,2]

  
**Note:**

1.  `1 <= deck.length <= 10000`
2.  `0 <= deck[i] < 10000`

**Difficulty**:Easy

**Category**:Array, Math

<!-- more -->

# Analyze

# Solution

```cpp
// Runtimes: 20ms
class Solution {
 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> rec;
    for (int i : deck) rec[i]++;
    for (int i = 2; i <= deck.size(); ++i) {
      if (deck.size() % i) continue;
      bool ok = true;
      for (auto& card : rec) {
        if (card.second % i) {
          ok = false;
          break;
        }
      }
      if (ok) return true;
    }
    return false;
  }
};
```