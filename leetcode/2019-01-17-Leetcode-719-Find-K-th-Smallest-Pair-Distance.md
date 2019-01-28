---
title: Leetcode 719. Find K th Smallest Pair Distance
date: 2019-01-17 21:23:14
updated: 2019-01-17 21:23:14
categories: 
- [Leetcode]
- [Leetcode, Array]
- [Leetcode, Binary-Search]
- [Leetcode, Heap]
tags: Leetcode
notshow: true
top:
---

# Question

Given an integer array, return the k-th smallest  **distance**  among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

**Example 1:**  

> **Input:**
> nums = [1,3,1]
> k = 1
> **Output: 0** 
> **Explanation:**
> Here are all the pairs:
> (1,3) -> 2
> (1,1) -> 0
> (3,1) -> 2
> Then the 1st smallest distance pair is (1,1), and its distance is 0.

**Note:**  

1.  `2 <= len(nums) <= 10000`.
2.  `0 <= nums[i] < 1000000`.
3.  `1 <= k <= len(nums) * (len(nums) - 1) / 2`.

**Difficulty**:Hard
**Category**:Array, Binary-Search, Heap

<!-- more -->

------------

# Analyze

The first way, we can think about use the **Brute Force/bucket sorting** .

![](/images/in-post/2019-01-17-Leetcode-719-Find-K-th-Smallest-Pair-Distance/2019-01-17-21-25-24.png)

------------

# Solution

```cpp

```


