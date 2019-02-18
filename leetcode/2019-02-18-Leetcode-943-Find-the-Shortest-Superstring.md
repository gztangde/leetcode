---
title: Leetcode 943. Find the Shortest Superstring
date: 2019-02-18 13:57:26
updated: 2019-02-18 13:57:26
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given an array A of strings, find any smallest string that contains each string in  `A`  as a substring.

We may assume that no string in  `A`  is substring of another string in  `A`.

**Example 1:**

**Input:** ["alex","loves","leetcode"]
**Output:** "alexlovesleetcode"
**Explanation:** All permutations of "alex","loves","leetcode" would also be accepted.

**Example 2:**

**Input:** ["catg","ctaagt","gcta","ttca","atgcatc"]
**Output:** "gctaagttcatgcatc"

**Note:**

1. `1 <= A.length <= 12`
2. `1 <= A[i].length <= 20`

**Difficulty**:Hard

**Category**: 

<!-- more -->

------------

# Analyze

在这道题目的输入规模情况，可以得到， 这个规模可以 $O(n^2)$

![](./images/2019-02-18-14-41-32.png)

------------

# Solution

```cpp
class Solution {
 public:
  string shortestSuperstring(vector<string>& A) {
    const int n = A.size();

    // 预处理阶段： 计算將单词 j 接到单词  i 后面的最小 Cost 是多少
    g_ = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        g_[i][j] = A[j].length();
        for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k)
          if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) 
            g_[i][j] = A[j].length() - k; // g_[i][j]表示將单词 j 放在 i后面
      }
    vector<int> path(n， -1); // 当前的路径---各个单词的 index
    best_len_ = INT_MAX;
    dfs(A, 0, 0, 0, path);

    string ans = A[best_path_[0]];
    for (int k = 1; k < best_path_.size(); ++k) {
      int i = best_path_[k - 1];
      int j = best_path_[k];
      ans += A[j].substr(A[j].length() - g_[i][j]);
    }
    return ans;
  }

 private:
  vector<vector<int>> g_;  //预处理
  vector<int> best_path_;
  int best_len_;
  // d: 当前搜素的深度， uesd: 表示那些单词已经被使用了， cur_len 当前路径所有单词的长度和
  void dfs(const vector<string>& A, int d, int used, int cur_len, vector<int>& path) {
    // 剪枝处理
    if (cur_len >= best_len_) return;
    if (d == A.size()) { // 表示所有的单词已经全部使用过了， 当前最优解
      best_len_ = cur_len;
      best_path_ = path;
      return;
    }

    for (int i = 0; i < A.size(); ++i) {
      if (used & (1 << i)) continue; // 判断当前单词是否已经使用过了
      path[d] = i; // 表示第 d 步使用的是 A[i] 这个单词
      dfs(A, d + 1, used | (1 << i), d == 0 ? A[i].length() : cur_len + g_[path[d - 1]][i], path);
      path[d] = -1;
    }
  }
};
```

## Solution 1: Search(DFS) + Pruning

Time complexity: O(n!)
Space complexity: O(n)

```cpp
// Runtime: 1076 ms, faster than 7.41% of C++ online submissions for Find the Shortest Superstring.
// Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Find the Shortest Superstring.
class Solution {
 public:
  string shortestSuperstring(vector<string>& A) {
    const int n = A.size();

    v_ = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        v_[i][j] = A[j].length();
        int p_len = A[i].length(), s_len = A[j].length();
        for (int cnt = min(p_len, s_len); cnt >= 0; --cnt)
          if (A[i].substr(p_len - cnt) == A[j].substr(0, cnt)) {
            v_[i][j] = s_len - cnt;
            break;
          }
      }
    }

    vector<int> path(n, -1);
    best_len = INT_MAX;
    shortestSuperstringDFS(A, 0, 0, 0, path);

    string ans = A[best_path[0]];
    for (int i = 1; i < best_path.size(); ++i) {
      int left = best_path[i - 1], right = best_path[i];
      ans += A[right].substr(A[right].length() - v_[left][right]);
    }
    return ans;
  }

 private:
  vector<vector<int>> v_;
  vector<int> best_path;
  int best_len;

  void shortestSuperstringDFS(vector<string>& A, int index, int used, int cur_len, vector<int>& path) {
    if (cur_len >= best_len) return;
    if (index == A.size()) {
      best_len = cur_len;
      best_path = path;
      return;
    }

    for (int i = 0; i < A.size(); ++i) {
      if (used & (1 << i)) continue;
      path[index] = i;
      shortestSuperstringDFS(A, index + 1, used | (1 << i),
                             index == 0 ? A[i].length() : cur_len + v_[path[index - 1]][i], path);
      path[index] = -1;
    }
  }
};
```