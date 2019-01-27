---
title: Leetcode 888. Fair Candy Swap
date: 2018-12-25 09:09:31
updated: 2018-12-25 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Alice and Bob have candy bars of different sizes:  `A[i]`  is the size of the  `i`-th bar of candy that Alice has, and  `B[j]`  is the size of the  `j`-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy. (_The total amount of candy a person has is the sum of the sizes of candy bars they have._)

Return an integer array  `ans` where  `ans[0]`  is the size of the candy bar that Alice must exchange, and  `ans[1]`  is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them. It is guaranteed an answer exists.

**Example 1:**

> **Input:** A = [1,1], B = [2,2]
> **Output:** [1,2]

**Example 2:**

> **Input:** A = [1,2], B = [2,3]
> **Output:** [1,2]

**Example 3:**

> **Input:** A = [2], B = [1,3]
> **Output:** [2,3]

**Example 4:**

> **Input:** A = [1,2,5], B = [2,4]
> **Output:** [5,4]

**Note:**

- `1 <= A.length <= 10000`
- `1 <= B.length <= 10000`
- `1 <= A[i] <= 100000`
- `1 <= B[i] <= 100000`
- It is guaranteed that Alice and Bob have different total amounts of candy.
- It is guaranteed there exists an answer.

**Difficulty**:Easy
**Category**:Array

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int sum_a = 0, sum_b = 0;
    std::unordered_set<int> set_b;
    for (int x : A) sum_a += x;
    for (int x : B) {
      sum_b += x;
      set_b.insert(x);
    }
    int diff = (sum_b - sum_a) / 2;

    for (int x : A) {
      std::unordered_set<int>::const_iterator it = set_b.find(x + diff);
      if (it != set_b.end()) {
        return {x, x + diff};
      }
    }

    return {};
  }
};
```