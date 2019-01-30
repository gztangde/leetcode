---
title: Leetcode 509. Fibonacci Number
date: 2019-01-30 01:05:44
updated: 2019-01-30 01:05:44
categories: 
- [Leetcode]
tags: Leetcode
notshow: true
top:
---

# Question

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from  `0`  and  `1`. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.

Given  `N`, calculate  `F(N)`.

**Example 1:**

> **Input:** 2
> **Output:** 1
> **Explanation:** F(2) = F(1) + F(0) = 1 + 0 = 1.

**Example 2:**

> **Input:** 3
> **Output:** 2
> **Explanation:** F(3) = F(2) + F(1) = 1 + 1 = 2.

**Example 3:**

> **Input:** 4
> **Output:** 3
> **Explanation:** F(4) = F(3) + F(2) = 2 + 1 = 3.

**Note:**

0 ≤  `N`  ≤ 30.

**Difficulty**:Medium

**Category**: Recursion, DP

<!-- more -->

------------

# Analyze

------------

# Solution

# SOlution 1: 递归方案:

```cpp
//时间复杂度: O(2^n)
class Solution {
 public:
  int fib(int N) { 
    return N < 2 ? N : fib(N - 1) + fib(N - 2); 
  }
};
```

## Solution 2:

```cpp
class Solution {
 public:
  int fib(int N) {
    vector<int> m_(N + 1, 0);
    if (N < 2) return N;
    m_[0] = 0, m_[1] = 1;
    for (int i = 2; i <= N; ++i) {
      m_[i] = m_[i - 1] + m_[i - 2];
    }
    return m_[N];
  }
};
```

## Solution 3: DP

```cpp
class Solution {
 public:
  int fib(int N) {
    if (N < 2) return N;
    int m1 = 0, m2 = 1, m3 = 0;
    for (int i = 2; i <= N; ++i) {
      m3 = m1 + m2;
      m1 = m2;
      m2 = m3;
    }
    return m3;
  }
};
```