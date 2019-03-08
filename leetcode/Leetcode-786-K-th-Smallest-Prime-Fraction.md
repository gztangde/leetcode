---
title: Leetcode 786. K th Smallest Prime Fraction
date: 2019-01-19 17:42:14
updated: 2019-01-19 17:42:14
categories: 
- [Leetcode]
- [Leetcode, Binary-Search]
- [Leetcode, Heap]
tags: Leetcode
notshow: true
top:
---

# Question

A sorted list  `A`  contains 1, plus some number of primes. Then, for every p < q in the list, we consider the fraction p/q.

What is the  `K`-th smallest fraction considered? Return your answer as an array of ints, where  `answer[0] = p`  and  `answer[1] = q`.

**Examples:**
> **Input:** A = [1, 2, 3, 5], K = 3
> **Output:** [2, 5]
> **Explanation:**
> The fractions to be considered in sorted order are:
> 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
> The third fraction is 2/5.
> 
> **Input:** A = [1, 7], K = 1
> **Output:** [1, 7]

**Note:**

- `A`  will have length between  `2`  and  `2000`.
- Each  `A[i]`  will be between  `1`  and  `30000`.
- `K`  will be between  `1`  and  `A.length * (A.length - 1) / 2`.

**Difficulty**:Hard

**Category**:Binary-Search, Heap

<!-- more -->

# Analyze

在Leetcode里面有好几个类似的题目是利用了`Binary-Search`的方式去查找第`k`小的数.

![](/images/in-post/2019-01-19-Leetcode-786-K-th-Smallest-Prime-Fraction/2019-01-19-17-45-08.png)

根据input的数据大小,确定使用的方法是`Binary-search`.

# Solution

```cpp

```


