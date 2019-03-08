---
title: Leetcode 374. Guess Number Higher or Lower
date: 2018-12-17 09:09:31
updated: 2018-12-17 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

We are playing the Guess Game. The game is as follows:

I pick a number from  **1**  to  **_n_**. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API  `guess(int num)`  which returns 3 possible results (`-1`,  `1`, or  `0`):

> -1 : My number is lower
> 1 : My number is higher
> 0 : Congrats! You got it!

**Example :**

> **Input:** n = 10, pick = 6
> **Output:** 6

**Difficulty**:Easy

**Category**:Binary-Search

<!-- more -->

# Analyze

# Solution

```cpp
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
 public:
  int guessNumber(int n) {
    long int left = 1, right = n;
    while (left <= right) {
      long int mid = (left + right) / 2;
      int res = guess(mid);
      if (!res)
        return mid;
      else if (res == 1)
        left = mid + 1;
      else
        right = mid;
    }
    return left;
  }
};
```