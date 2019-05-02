---
title: Leetcode 862. Shortest Subarray with Sum at Least K
date: 2019-02-01 14:02:04
updated: 2019-02-01 14:02:04
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Return the  **length**  of the shortest, non-empty, contiguous subarray of  `A`  with sum at least  `K`.

If there is no non-empty subarray with sum at least  `K`, return  `-1`.

**Example 1:**

> **Input:** A = [1], K = 1
> **Output:** 1

**Example 2:**

> **Input:** A = [1,2], K = 4
> **Output:** -1

**Example 3:**

> **Input:** A = [2,-1,2], K = 3
> **Output:** 3

**Note:**

1. `1 <= A.length <= 50000`
2. `-10 ^ 5 <= A[i] <= 10 ^ 5`
3. `1 <= K <= 10 ^ 9`
  
**Difficulty**:Medium

**Category**:

<!-- more -->

# Solution

## Solution 1: Error---Time Limit Exceeded

> Runtime: 7164 ms, faster than 2.70% of C++ online submissions for Shortest Subarray with Sum at Least K.
> Memory Usage: 7.3 MB, less than 54.72% of C++ online submissions for Shortest Subarray with Sum at Least K.

```cpp
class Solution {
 public:
  int shortestSubarray(vector<int>& A, int K) {
    int ans = INT_MAX;
    A.insert(A.begin(), 0);
    const int n = A.size();
    for (int i = 1; i < n; ++i) A[i] = A[i-1] + A[i];
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (A[j + 1] - A[i] >= K) {
          ans = min(j + 1 - i, ans);
          break;
        }
      }
    }
    if (ans == INT_MAX) return -1;
    return ans;
  }
};
```

## Solution 2

<!-- TODO: Understand this solution -->

解法来源于: [C++/Java/Python O(N) Using Deque](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726/C%2B%2BJavaPython-O(N)-Using-Deque)

```cpp
class Solution {
 public:
  int shortestSubarray(vector<int> A, int K) {
    int n = A.size(), res = n + 1;
    vector<int> B(n + 1, 0);
    for (int i = 0; i < n; i++) B[i + 1] = B[i] + A[i];
    deque<int> d;
    for (int i = 0; i < n + 1; i++) {
      while (d.size() > 0 && B[i] - B[d.front()] >= K) {
        res = min(res, i - d.front());
        d.pop_front();
      }
      // If B[i]  < B[d.back()] then, pop it
      // Deque d will keep indexes of increasing B[i].
      while (d.size() > 0 && B[i] <= B[d.back()]) 
        d.pop_back();
      // Push the sum for the first i in the d
      d.push_back(i);
    }
    return res <= n ? res : -1;
  }
};
```