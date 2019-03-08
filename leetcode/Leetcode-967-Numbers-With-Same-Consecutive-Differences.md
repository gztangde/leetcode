---
title: Leetcode 967. Numbers With Same Consecutive Differences
date: 2019-02-10 15:29:13
updated: 2019-02-10 15:29:13
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Return all  **non-negative**  integers of length  `N`  such that the absolute difference between every two consecutive digits is  `K`.

Note that  **every**  number in the answer  **must not**  have leading zeros  **except**  for the number  `0`  itself. For example,  `01`  has one leading zero and is invalid, but  `0`  is valid.

You may return the answer in any order.

**Example 1:**

**Input:** N = 3, K = 7
**Output:** [181,292,707,818,929]
**Explanation:** Note that 070 is not a valid number, because it has leading zeroes.

**Example 2:**

**Input:** N = 2, K = 1
**Output:** [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

**Note:**

1. `1 <= N <= 9`
2. `0 <= K <= 9`

**Difficulty**:Medium

**Category**:

<!-- more -->

# Analyze

# Solution 1

```cpp
class Solution {
 public:
  vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> ans;
    if (N == 1) ans.emplace_back(0);
    for (int i = 1; i < 10; ++i) {
      numsSameConsecDiff(i, N - 1, K, ans);
    }
    return ans;
  }
  void numsSameConsecDiff(int num, int N, int& K, vector<int>& ans) {
    if (N == 0) {
      ans.emplace_back(num);
      return;
    }
    int last = num % 10;
    if (last + K <= 9) {
      int cur = last + K;
      numsSameConsecDiff(num * 10 + cur, N - 1, K, ans);
    }
    if (last - K >= 0 & K > 0) {
      int cur = last - K;
      numsSameConsecDiff(num * 10 + cur, N - 1, K, ans);
    }
  }
};
```

## Solution 2

```cpp
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i, s, t) for (int i = (s); i < (t); i++)
#define FILL(x, v) memset(x, v, sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

class Solution {
 public:
  int N, K;

  vector<int> numsSameConsecDiff(int _N, int _K) {
    N = _N;
    K = _K;
    VI ans;
    if (N == 1) {
      REP(i, 0, 10) ans.push_back(i);
      return ans;
    }
    REP(s, 1, 10) solve(1, s, s, ans);
    return ans;
  }

 private:
  void solve(int i, int ld, int val, VI &ans) {
    // DFS return value
    if (i == N) {
      ans.push_back(val);
      return;
    }
    REP(t, 0, 2) {
      // Two situation in this loop
      // - or +
      int d = t == 0 ? ld + K : ld - K;
      if (K == 0 && t == 1) continue;
      if (0 <= d && d <= 9) {
        solve(i + 1, d, val * 10 + d, ans);
      }
    }
  }
};
```