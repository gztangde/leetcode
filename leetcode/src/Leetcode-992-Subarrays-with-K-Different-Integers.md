---
title: Leetcode 992. Subarrays with K Different Integers
date: 2019-02-09 23:20:42
updated: 2019-02-09 23:20:42
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Leetcode 992. Subarrays with K Different Integers

Given an array  `A`  of positive integers, call a (contiguous, not necessarily distinct) subarray of  `A`  _good_  if the number of different integers in that subarray is exactly  `K`.

(For example,  `[1,2,3,1,2]`  has  `3`  different integers:  `1`,  `2`, and  `3`.)

Return the number of good subarrays of  `A`.

**Example 1:**

**Input:** A = [1,2,1,2,3], K = 2
**Output:** 7
**Explanation:** Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].

**Example 2:**

**Input:** A = [1,2,1,3,4], K = 3
**Output:** 3
**Explanation:** Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

**Difficulty**:Hard

**Category**:

<!-- more -->

# Solution

## Solution 1:

From [devidxu](https://leetcode.com/devidxu/) in leetcode Weekly contest 123.

```cpp
class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& A, int K) {
    int idx = 0, result = 0;
    unordered_map<int, int> counter;
    int start = 0, end = 0;
    if (K == 0) return 0;
    while (idx < A.size()) {
      // idx is the first element in the subarray
      if (idx == 0)
        updateRange(A, start, end, K, counter);
      else {
        int prev = A[idx - 1];
        if (--counter[prev] == 0) {
          counter.erase(prev);
          updateRange(A, start, end, K, counter);
        }
      }
      if (counter.size() < K) break;
      result += end + 1 - start;
      idx += 1;
    }
    return result;
  }

  void updateRange(vector<int>& A, int& start, int& end, int k, unordered_map<int, int>& counter) {
    // Remove the first element count--
    while (start < A.size() && counter.size() < k) {
      counter[A[start]] += 1;
      start += 1;
    }
    if (counter.size() < k) return;
    // Counter.size() > k, then we need to 
    while (end < A.size() && counter.count(A[end])) {
      end += 1;
    }
  }
};
```

## Solution 2:

```cpp
class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& A, int K) { 
    return count(A, K) - count(A, K - 1);
  }

 private:
  int count(vector<int>& a, int K) {
    int n = a.size();
    vector<int> f(n + 1, 0);
    int diff = 0;
    int prev = 0;
    int ret = 0;
    for (int i = 0; i < n; i++) {
      // If this is the first element in the f[a[i]]
      if (++f[a[i]] == 1) {
        diff++;
      }
      while (diff > K) {
        if (--f[a[prev++]] == 0) {
          diff--;
        }
      }
      ret += i - prev + 1;
    }
    return ret;
  }
};
```

## Solution 3

```cpp
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i, s, t) for (int i = (s); i < (t); i++)
#define FILL(x, v) memset(x, v, sizeof(x))

const int INF = (int)1E9;

class Solution {
 public:
  int subarraysWithKDistinct(vector<int> &A, int K) { 
    return solve(A, K) - solve(A, K + 1); 
  }

 private:
  // Remove the first element
  void remove(map<int, int> &cnt, int v) {
    if (--cnt[v] == 0) cnt.erase(v);
  }
  
  int solve(VI &A, int K) {
    int n = A.size();
    map<int, int> cnt;
    int j = 0, ans = 0;
    REP(i, 0, n) {
      cnt[A[i]]++;
      while (cnt.size() >= K) remove(cnt, A[j++]);
      ans += j;
    }
    return ans;
  }
};
```

# Follow up

Give an array of letters and a window size k, return subarrays of size k with no duplicates

Solution: Two pointers + indirection
Let f(x) denote the number of subarrays with x or less distinct numbers.
ans = f(K) – f(K-1)
It takes O(n) Time and O(n) Space to compute f(x)

```cpp
// Author: Huahua
// vector: 56 ms, 10.1 MB
// Hashtable: 126 ms, 25 MB
class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& A, int K) {
    // Returns the number of subarrays with k or less distinct numbers.
    auto subarrys = [&A](int k) {
      vector<int> count(A.size() + 1);
      int ans = 0;
      int i = 0;
      for (int j = 0; j < A.size(); ++j) {
        if (count[A[j]]++ == 0) --k;
        while (k < 0)
          if (--count[A[i++]] == 0) ++k;
        ans += j - i + 1;
      }
      return ans;
    };
    return subarrys(K) - subarrys(K - 1);
  }
};
```