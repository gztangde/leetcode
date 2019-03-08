---
title: Leetcode 996. Number of Squareful Arrays
date: 2019-02-18 16:48:06
updated: 2019-02-18 16:48:06
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given an array  `A`  of non-negative integers, the array is  _squareful_  if for every pair of adjacent elements, their sum is a perfect square.

Return the number of permutations of A that are squareful. Two permutations  `A1`  and  `A2`  differ if and only if there is some index  `i`  such that  `A1[i] != A2[i]`.

**Example 1:**

**Input:** [1,17,8]
**Output:** 2
**Explanation:** 
[1,8,17] and [17,8,1] are the valid permutations.

**Example 2:**

**Input:** [2,2,2]
**Output:** 1

**Note:**

1. `1 <= A.length <= 12`
2. `0 <= A[i] <= 1e9`

**Difficulty**:Hard

**Category**:

<!-- more -->

------------

# Analyze

# Solution 1: DFS

Time complexity: O(n!)
Space complexity: O(n)

```cpp
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Number of Squareful Arrays.
// Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Number of Squareful Arrays.
class Solution {
 public:
  int numSquarefulPerms(vector<int>& A) {
    std::sort(begin(A), end(A));
    vector<int> out;
    vector<int> used(A.size(), 0);
    int ans = 0;
    permuteUniqueDFS(A, used, out, ans);
    return ans;
  }

 private:
  void permuteUniqueDFS(vector<int>& nums, vector<int>& used, vector<int>& out, int& ans) {
    if (out.size() == nums.size()) {
      ++ans;
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (used[i]) continue;
      // Same number can be only used once at each depth.
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
      if (!out.empty() && !squareful(out.back(), nums[i])) continue;
      used[i] = 1;
      out.emplace_back(nums[i]);
      permuteUniqueDFS(nums, used, out, ans);
      out.pop_back();
      used[i] = 0;
    }
  }

  bool squareful(int x, int y) {
    int s = sqrt(x + y);
    return s * s == x + y;
  }
};
```

## Solution 2: DFS

This solution come from the [discuss](https://leetcode.com/problems/number-of-squareful-arrays/discuss/238562/C%2B%2BPython-Backtracking)

**Explanation**:

1. Count numbers ocuurrence.
2. For each number  `i`, find all possible next number  `j`  that  `i + j`  is square.
3. Backtracking using dfs.

**Time Complexity**  
It's  `O(N^N)`  if we have N different numbers and any pair sum is square.  
We can easily make case for N = 3 like [51,70,30].

Seems that no hard cases for this problem and int this way it reduces to O(N^2).

```cpp
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Number of Squareful Arrays.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Number of Squareful 
class Solution {
 public:
  int numSquarefulPerms(vector<int>& A) {
    res = 0;
    for (int& a : A) count[a]++;

    // For each number i, find all possible next number j that i + j is square.
    for (auto& i : count) {
      for (auto& j : count) {
        int x = i.first, y = j.first, s = sqrt(x + y);
        if (s * s == x + y) cand[x].insert(y);
      }
    }
    for (auto e : count) dfs(e.first, A.size() - 1);
    return res;
  }

 private:
  unordered_map<int, int> count;
  unordered_map<int, unordered_set<int>> cand;
  int res;

  void dfs(int x, int len) {
    count[x]--;
    if (len == 0) res++;
    for (int y : cand[x])
      if (count[y] > 0) dfs(y, len - 1);
    count[x]++;
  }
};
```

## Solution 3: depth

This solution come from: [花花酱 LeetCode 996. Number of Squareful Arrays](https://zxi.mytechroad.com/blog/searching/leetcode-996-number-of-squareful-arrays/)

<!-- TODO: Understand this solution -->

```cpp
class Solution {
 public:
  int numSquarefulPerms(vector<int>& A) {
    const int n = A.size();
    // For deduplication.
    std::sort(begin(A), end(A));
    // g[i][j] == 1 if A[i], A[j] are squareful.
    vector<vector<int>> g(n, vector<int>(n, 0));
    // dp[s][i] := number of ways to reach state s and ends with node i.
    vector<vector<int>> dp(1 << n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        int r = sqrt(A[i] + A[j]);
        if (r * r == A[i] + A[j]) g[i][j] = 1;
      }
    }

    // For the same numbers, only the first one can be the starting point.
    for (int i = 0; i < n; ++i)
      if (i == 0 || A[i] != A[i - 1]) dp[(1 << i)][i] = 1;

    int ans = 0;
    for (int s = 0; s < (1 << n); ++s)
      for (int i = 0; i < n; ++i) {
        if (!dp[s][i]) continue;
        for (int j = 0; j < n; ++j) {
          if (!g[i][j]) continue;
          if (s & (1 << j)) continue;
          // Only the first one can be used as the dest.
          if (j > 0 && !(s & (1 << (j - 1))) && A[j - 1] == A[j]) continue;
          dp[s | (1 << j)][j] += dp[s][i];
        }
      }

    for (int i = 0; i < n; ++i) ans += dp[(1 << n) - 1][i];
    return ans;
  }
};
```