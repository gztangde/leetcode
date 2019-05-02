---
title: Leetcode 915. Partition Array into Disjoint Intervals
date: 2019-01-19 00:05:56
updated: 2019-01-19 00:05:56
categories: 
- [Leetcode]
- [Leetcode, Array]
tags: Leetcode
notshow: true
top:
---

# Question

Given an array  `A`, partition it into two (contiguous) subarrays `left` and  `right` so that:

- Every element in  `left` is less than or equal to every element in  `right`.
- `left`  and  `right`  are non-empty.
- `left` has the smallest possible size.

Return the  **length**  of  `left`  after such a partitioning(分割). It is guaranteed that such a partitioning exists.

**Example 1:**
> **Input:** [5,0,3,8,6]
> **Output:** 3
> **Explanation:** left = [5,0,3], right = [8,6]

**Example 2:**
> **Input:** [1,1,1,0,6,12]
> **Output:** 4
> **Explanation:** left = [1,1,1,0], right = [6,12]

**Note:**

1. `2 <= A.length <= 30000`
2. `0 <= A[i] <= 10^6`
3. It is guaranteed there is at least one way to partition  `A`  as described.

**Difficulty**:Medium

**Category**:Array

<!-- more -->

# Solution

## Solution: Search

```cpp
class Solution {
 public:
  int partitionDisjoint(vector<int>& A) {
    // 1) Begin with the second
    multiset<int> record(A.begin() + 1, A.end());
    // 2) Use the first element to init the left_max
    int left_max = A[0];
    for (int i = 1; i < A.size(); ++i) {
      // 3) When the record.begin() > left_max,
      // it means all the other elements is biger than the left elements.
      if (*record.begin() >= left_max) return i;
      record.erase(record.equal_range(A[i]).first);
      left_max = max(left_max, A[i]);
    }
    return -1;
  }
};
```


