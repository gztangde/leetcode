---
title: Leetcode 961. N-Repeated Element in Size 2N Array
date: 2019-01-08 09:09:31
updated: 2019-01-08 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

In a array  `A`  of size  `2N`, there are  `N+1`  unique elements, and exactly one of these elements is repeated N times.

Return the element repeated  `N`  times.

**Example 1:**

> **Input:** [1,2,3,3]
> **Output:** 3

**Example 2:**

> **Input:** [2,1,2,5,3,2]
> **Output:** 2

**Example 3:**

> **Input:** [5,1,5,2,5,3,5,4]
> **Output:** 5

**Note:**

1. `4 <= A.length <= 10000`
2. `0 <= A[i] < 10000`
3. `A.length`  is even

**Difficulty**:Easy

**Category**:Hash-Table

<!-- more -->

------------

# Analyze

# Solution

## Solution 1: Ust Set

```cpp
class Solution {
 public:
  int repeatedNTimes(vector<int>& A) {
    unordered_set<int> rec;
    for (int i = 0; i < A.size(); ++i) {
      if (rec.count(A[i]))
        return A[i];
      else
        rec.insert(A[i]);
    }
  }
};
```

## Solution 2: Use Hash-Table

```cpp
class Solution {
 public:
  int repeatedNTimes(vector<int>& A) {
    int n = A.size();
    unordered_map<int, int> m;
    for (int& a : A) {
      if (++m[a] >= n / 2) return a;
    }
    return 0;
  }
};
```

## Solution 3: Use array

This solution come from https://leetcode.com/yubowenok/

> Runtime: 52 ms, faster than 36.81% of C++ online submissions for N-Repeated Element in Size 2N Array.
> Memory Usage: 11.1 MB, less than 0.94% of C++ online submissions for N-Repeated Element in Size 2N Array.

```cpp
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 10005

int cnt[MAXN];
class Solution {
public:
  int repeatedNTimes(vector<int>& A) {
    FILL(cnt, 0);
    int n = A.size() / 2, ans = -1;
    REP(i,0,2*n) {
      if (++cnt[A[i]] >= n) return A[i];
    }
  }
};
```