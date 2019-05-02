---
title: Leetcode 338. Counting Bits
date: 2019-02-09 18:50:41
updated: 2019-02-09 18:50:41
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a non negative integer number  **num**. For every numbers  **i**  in the range  **0 ≤ i ≤ num**calculate the number of 1's in their binary representation and return them as an array.

**Example 1:**

**Input:** 2
**Output:** [0,1,1]

**Example 2:**

**Input:** 5
**Output:** `[0,1,1,2,1,2]`

**Follow up:**

- It is very easy to come up with a solution with run time  **O(n*sizeof(integer))**. But can you do it in linear time  **O(n)**  /possibly in a single pass?
- Space complexity should be  **O(n)**.
- Can you do it like a boss? Do it without using any builtin function like  **__builtin_popcount**  in c++ or in any other language.

**Difficulty**:Medium

**Category**:

<!-- more -->

# Solution

## Solution 1

```cpp
class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> ans(num + 1, 0);
    bitset<32> bit(0);
    for (int i = 0; i < num + 1; ++i) {
      bit = i;
      ans[i] = (bit.count());
    }
    return ans;
  }
};
```

## Solution 2

对于数字 6(110)，它可以看成是 4(100) 再加一个 2(10)，因此 `dp[i] = dp[i & (i-1)] + 1`.

<!-- TODO: Understand this code to do something. -->

```cpp
class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> ans(num + 1, 0);
    for (int i = 1; i <= num; i++) {
      ans[i] = ans[i & (i - 1)] + 1;
    }
    return ans;
  }
};
```