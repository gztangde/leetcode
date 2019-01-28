---
title: Leetcode 275. H-Index II
date: 2018-12-16 09:09:31
updated: 2018-12-16 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question


Given an array of citations  **sorted in ascending order** (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the [definition of h-index on Wikipedia](https://en.wikipedia.org/wiki/H-index): "A scientist has index _h_ if _h_ of his/her _N_ papers have **at least** _h_ citations each, and the other _N − h_ papers have **no more than** _h_ citations each."

![](/images/in-post/2018-12-16-Leetcode-275-H-Index-II/2018-12-17-00-51-50.png)

**Note:**

If there are several possible values for _h_, the maximum one is taken as the h-index.

**Follow up:**

- This is a follow up problem to [H-Index](https://leetcode.com/problems/h-index/description/), where  `citations`  is now guaranteed to be sorted in ascending order.
- Could you solve it in logarithmic time complexity?

**Difficulty**:Medium

**Category**:Array

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int len_c = citations.size(), left = 0, right = len_c - 1;
    while (left <= right) {
      int mid_c = (right + left) / 2;
      if (citations[mid_c] == len_c - mid_c)
        return len_c - mid_c;
      else if (citations[mid_c] > len_c - mid_c) {
        right = mid_c - 1;
      } else {
        left = mid_c + 1;
      }
    }
    return len_c - left;
  }
};

```

## Solution 2: Line Scan

```cpp
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    vector<int>& c = citations; 
    for (int i = 1; i <= c.size(); ++i) {
      if ( *(c.rbegin()+i-1) < i ) return i - 1;
    }
    return c.size();
  }
};
```


<!-- TODO:
Spend more time to resolve this questions.
 -->