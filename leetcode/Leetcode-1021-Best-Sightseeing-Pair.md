---
title: Leetcode 1021. Best Sightseeing Pair
date: 2019-03-24 19:42:22
updated: 2019-03-24 19:42:22
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Question

题目大意: 在一个数组中,找到满足一对元素,可以得到一定条件的最大值(和购买股票是一样的题型)

Given an array  `A`  of positive integers,  `A[i]`  represents the value of the  `i`-th sightseeing spot, and two sightseeing spots  `i`  and  `j` have distance  `j - i` between them.

The  _score_ of a pair (`i < j`) of sightseeing spots is (`A[i] + A[j] + i - j)`  : the sum of the values of the sightseeing spots,  **minus**  the distance between them.

Return the maximum score of a pair of sightseeing spots.

**Example 1:**

**Input:** [8,1,5,2,6]
**Output:** 11
**Explanation:** i = 0, j = 2, `A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11`

**Note:**

1. `2 <= A.length <= 50000`
2. `1 <= A[i] <= 1000`

**Difficulty**:Medium

**Category**:

# Solution

Time complexity: O(n), Space complexity: O(1)

```cpp
class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& A) {
    int ans = 0, left = INT_MIN;
    for (int i = 0; i < A.size(); ++i) {
      ans = max(ans, A[i] - i + left);
      left = max(left, A[i] + i);
    }
    return ans;
  }
};
```