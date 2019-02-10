---
title: Leetcode 989. Add to Array Form of Integer
date: 2019-02-10 00:22:12
updated: 2019-02-10 00:22:12
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

For a non-negative integer  `X`, the _array-form of  `X`_ is an array of its digits in left to right order. For example, if  `X = 1231`, then the array form is `[1,2,3,1]`.

Given the array-form  `A`  of a non-negative integer  `X`, return the array-form of the integer  `X+K`.

**Example 1:**

**Input:** A = [1,2,0,0], K = 34
**Output:** [1,2,3,4]
**Explanation:** 1200 + 34 = 1234

**Example 2:**

**Input:** A = [2,7,4], K = 181
**Output:** [4,5,5]
**Explanation:** 274 + 181 = 455

**Example 3:**

**Input:** A = [2,1,5], K = 806
**Output:** [1,0,2,1]
**Explanation:** 215 + 806 = 1021

**Example 4:**

**Input:** A = [9,9,9,9,9,9,9,9,9,9], K = 1
**Output:** [1,0,0,0,0,0,0,0,0,0,0]
**Explanation:** 9999999999 + 1 = 10000000000

**Note：**

1.  `1 <= A.length <= 10000`
2.  `0 <= A[i] <= 9`
3.  `0 <= K <= 10000`
4.  If  `A.length > 1`, then  `A[0] != 0`

**Difficulty**:Easy

**Category**:

<!-- more -->

------------

# Analyze

这是123次周赛的比赛题目, 使用`C++`来解决这个问题的时候,显得十分笨重, 在后面的题目中,会同时考虑使用 Python 来刷Leetcode的题目.

------------

# Solution

```cpp
class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& A, int k) {
    // vector<int> ans;
    int n = A.size(), carry = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (k > 0 || carry > 0) {
        A[i] = A[i] + k % 10 + carry;
        carry = A[i] / 10;
        A[i] = A[i] % 10;
        k = k / 10;
      }
    }
    while (k > 0 || carry > 0) {
      int temp = k % 10 + carry;
      A.insert(A.begin(), temp % 10);
      carry = temp / 10;
      k = k / 10;
    }
    return A;
  }
};
```

## Solution 2: Python

```python
class Solution(object):
  def addToArrayForm(self, A, K):
    v = ''.join([str(x) for x in A])
    v = int(v)
    v += K
    return [int(d) for d in str(v)]
```