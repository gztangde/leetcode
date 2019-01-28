---
title: Leetcode 668. Kth Smallest Number in Multiplication Table
date: 2019-01-15 21:40:37
updated: 2019-01-15 21:40:37
categories: 
- [Leetcode]
- [Leetcode, ]
tags: Leetcode
notshow: true
top:
---

# Question

Nearly every one have used the  [Multiplication Table](https://en.wikipedia.org/wiki/Multiplication_table). But could you find out the  `k-th`  smallest number quickly from the multiplication table?

Given the height  `m`  and the length  `n`  of a  `m * n`  Multiplication Table, and a positive integer  `k`, you need to return the  `k-th`smallest number in this table.

**Example 1:**  

```
**Input:** m = 3, n = 3, k = 5
**Output:** 
**Explanation:** 
The Multiplication Table:
1	2	3
2	4	6
3	6	9

The 5-th smallest number is 3 (1, 2, 2, 3, 3).
```

**Example 2:**  

```
**Input:** m = 2, n = 3, k = 6
**Output:** 
**Explanation:** 
The Multiplication Table:
1	2	3
2	4	6

The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
```

**Note:**  

1.  The  `m`  and  `n`  will be in the range [1, 30000].
2.  The  `k`  will be in the range [1, m * n]

**Difficulty**:Hard
**Category**:

<!-- more -->

------------

# Analyze

**在矩阵中使用二分搜索**

这道题目的难度在于数据规模非常巨大(Range: [1, 30000]),这就要求我们需要使用到`Binary 搜索`来解决这个问题.

![](/images/in-post/2019-01-15-Leetcode-668-Kth-Smallest-Number-in-Multiplication-Table/2019-01-15-21-45-16.png)

如果使用暴力搜索的方式的话,拿这道题目肯定内存是不够使用的. The memory can't enough for us to generate the table. We need to build this problem in O(n*log n)

- Each line, the elements have beed sorted, so we can choose the binary search in this case.

In this case, we can use the `x/i` as the number which can compare with the other element in a new row.

------------

# Solution

```cpp
class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    int left = 0, right = m * n + 1;
    while(left < right) {
      int mid = left + (right - left) / 2;
      if (rowLessCount(m, n , mid) >= k)
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }
 private:
  int rowLessCount(int& m, int& n, int mid) {
    int count = 0;
    // Count the number for the row
    // Don't ust the i == 0, so this question, i = 1 && i <= m
    for (int i = 1; i <= m; ++i) 
      count += min(n, mid/i);
    return count;
  }
};
```


