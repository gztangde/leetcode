---
title: Leetcode 461. Hamming Distance
date: 2019-01-25 17:17:08
updated: 2019-01-25 17:17:08
categories: 
- [Leetcode]
- [Leetcode, Bit-Manipulation]
tags: Leetcode
notshow: true
top:
---

# Question

The  [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance)  between two integers is the number of positions at which the corresponding bits are different.

Given two integers  `x`  and  `y`, calculate the Hamming distance.

```
**Note:**  
0 ≤  `x`,  `y`  < 231.

**Example:**

**Input:** x = 1, y = 4

**Output:** 2

**Explanation:**
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
```

The above arrows point to positions where the corresponding bits are different.

**Difficulty**:Medium

**Category**:Bit-Manipulation

<!-- more -->

------------

# Analyze

------------

# Solution

## Solution 1

对两个数进行异或操作，位级表示不同的那一位为 1，统计有多少个 1 即可。

```cpp
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int c = x ^ y, ans = 0;
    while (c > 0) {
      ans += c & 1;
      c = c >> 1;
    }
    return ans;
  }
};
```

## Solution 2

使用 z&(z-1) 去除 z 位级表示最低的那一位。

```cpp
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int c = x ^ y, ans = 0;
    while (c > 0) {
      c &=  (c - 1);
      ++ans;
    }
    return ans;
  }
};
```