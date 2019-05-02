---
title: Leetcode 29. Divide Two Integers
date: 2019-01-22 21:45:39
updated: 2019-01-22 21:45:39
categories: 
- [Leetcode]
- [Leetcode, Math]
- [Leetcode, Binary-Search]
tags: Leetcode
notshow: true
top:
---

# Question

Given two integers  `dividend`  and  `divisor`, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing  `dividend`  by  `divisor`.

The integer division should truncate toward zero.

**Example 1:**

> **Input:** dividend = 10, divisor = 3
> **Output:** 3

**Example 2:**

> **Input:** dividend = 7, divisor = -3
> **Output:** -2

**Note:**

- Both dividend and divisor will be 32-bit signed integers.
- The divisor will never be 0.
- Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231, 231  − 1]. For the purpose of this problem, assume that your function returns 231  − 1 when the division result overflows.

**Difficulty**:Medium

**Category**:

<!-- more -->

# Solution

这道题目规定我们不能使用乘法，除法以及取余操作。我们可以考虑在这道题目使用 `Bit Operation`

以下分析来自于博文：[Divide Two Integers 两数相除](http://www.cnblogs.com/grandyang/p/4431949.html)
这道题让我们求两数相除，而且规定我们不能用乘法，除法和取余操作，那么我们还可以用另一神器位操作Bit Operation，思路是，如果被除数大于或等于除数，则进行如下循环，定义变量t等于除数，定义计数p，当t的两倍小于等于被除数时，进行如下循环，t扩大一倍，p扩大一倍，然后更新res和m。这道题的OJ给的一些test case非常的讨厌，因为输入的都是int型，比如被除数是-2147483648，在int范围内，当除数是-1时，结果就超出了int范围，需要返回INT_MAX，所以对于这种情况我们就在开始用if判定，将其和除数为0的情况放一起判定，返回INT_MAX。然后我们还要根据被除数和除数的正负来确定返回值的正负，这里我们采用长整型long来完成所有的计算，最后返回值乘以符号即可

## Solution 1: Implement

```cpp
class Solution {
 public:
  int divide(int dividend, int divisor) {
    long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
    if (m < n) return 0;
    while (m >= n) {
      long long t = n, p = 1;
      while (m > (t << 1)) {
        t <<= 1;
        p <<= 1;
      }
      res += p;
      m -= t;
    }
    if ((dividend < 0) ^ (divisor < 0)) res = -res;
    return res > INT_MAX ? INT_MAX : res;
  }
};
```

## Solution 2: Recursion

```cpp
class Solution {
 public:
  int divide(int dividend, int divisor) {
    long long res = 0;
    long long m = abs((long long)dividend), n = abs((long long)divisor);
    if (m < n) return 0;
    long long t = n, p = 1;
    while (m > (t << 1)) {
      t <<= 1;
      p <<= 1;
    }
    res += p + divide(m - t, n);
    if ((dividend < 0) ^ (divisor < 0)) res = -res;
    return res > INT_MAX ? INT_MAX : res;
  }
};
```