---
title: Leetcode 710. Random Pick with Blacklist
date: 2019-02-01 00:30:59
updated: 2019-02-01 00:30:59
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a blacklist `B`  containing unique integers from  `[0, N)`, write a function to return a uniform random integer from  `[0, N)`  which is  **NOT** in  `B`.

Optimize it such that it minimizes the call to system’s  `Math.random()`.

**Note:**

1.  `1 <= N <= 1000000000`
2.  `0 <= B.length < min(100000, N)`
3.  `[0, N)` does NOT include N. See  [interval notation](https://en.wikipedia.org/wiki/Interval_(mathematics)).

**Example 1:**

**Input:** ["Solution","pick","pick","pick"] [[1,[]],[],[],[]]
**Output:** [null,0,0,0]

**Example 2:**

**Input:** ["Solution","pick","pick","pick"] [[2,[]],[],[],[]]
**Output:** [null,1,1,1]

**Example 3:**

**Input:** ["Solution","pick","pick","pick"] [[3,[1]],[],[],[]]
**Output:** [null,0,0,2]

**Example 4:**

**Input:** ["Solution","pick","pick","pick"] [[4,[2]],[],[],[]]
**Output:** [null,1,3,1]

**Explanation of Input Syntax:**

The input is two lists: the subroutines called and their arguments. `Solution`'s constructor has two arguments, `N`  and the blacklist  `B`.  `pick`  has no arguments. Arguments are always wrapped with a list, even if there aren't any.

**Difficulty**:Hard

**Category**:Sort

<!-- more -->

# Solution

```cpp
class Solution {
 public:
  Solution(int N, vector<int> blacklist) {
    n = N;
    blackset = unordered_set<int>(blacklist.begin(), blacklist.end());
    whitelist = vector<int>();
    if (blacklist.size() > N / 2)
      for (int i = 0; i < N; i++)
        if (!blackset.count(i)) whitelist.push_back(i);
  }

  int pick() {
    if (!whitelist.empty())
      return whitelist[rand() % whitelist.size()];
    else
      while (true) {
        int r = rand() % n;
        if (!blackset.count(r)) return r;
      }
  }
private:
  int n;
  vector<int> whitelist;
  unordered_set<int> blackset;
};
```