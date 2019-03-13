---
title: Leetcode 547. Friend Circles
date: 2019-03-12 21:21:19
updated: 2019-03-12 21:21:19
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Leetcode 547. Friend Circles

题目大意：求朋友圈的个数, 判断在 n 个人里面有多少个朋友圈

There are  **N**  students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a  **direct**  friend of B, and B is a  **direct**  friend of C, then A is an  **indirect**  friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a  **N*N**  matrix  **M**  representing the friend relationship between students in the class. If M[i][j] = 1, then the ithand jth  students are  **direct**  friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

**Example 1:**  

**Input:** 

```
[[1,1,0],
 [1,1,0],
 [0,0,1]]
```
**Output:** 2

**Explanation:**The 0th and 1st students are direct friends, so they are in a friend circle.   
The 2nd student himself is in a friend circle. So return 2.

**Example 2:**  

**Input:** 

```
[[1,1,0],
 [1,1,1],
 [0,1,1]]
```

**Output:** 1

**Explanation:**The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

**Note:**  

1. N is in range [1,200].
2. M[i][i] = 1 for all students.
3. If M[i][j] = 1, then M[j][i] = 1.

**Difficulty**:Medium

**Category**:

# Solution

那么比较直接的解法就是DFS搜索，对于某个人，遍历其好友，然后再遍历其好友的好友，那么我们就能把属于同一个朋友圈的人都遍历一遍，我们同时标记出已经遍历过的人，然后累积朋友圈的个数，再去对于没有遍历到的人在找其朋友圈的人，这样就能求出个数。

## Solution 1: DFS

Time complexity: O(n^2), Space complexity: O(n)

```cpp

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    int n = M.size(), ans = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
      if (visited[i]) continue;
      dfs(M, i, visited);
      ++ans;
    }
    return ans;
  }

 private:
  void dfs(vector<vector<int>>& M, int k, vector<bool>& visited) {
    visited[k] = true;
    for (int i = 0; i < M.size(); ++i) {
      if (!M[k][i] || visited[i]) continue;
      dfs(M, i, visited);
    }
  }
};
```

我们也可以不使用多余的空间来记录，直接在原有的元素上操作就好： cite:[花花酱 LeetCode 547. Friend Circles](https://zxi.mytechroad.com/blog/graph/leetcode-547-friend-circles/)

```cpp
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    if (M.empty()) return 0;
    int n = M.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (!M[i][i]) continue;
      ++ans;
      dfs(M, i, n);
    }
    return ans;
  }

 private:
  void dfs(vector<vector<int>>& M, int curr, int n) {
    // Visit all friends (neighbors)
    for (int i = 0; i < n; ++i) {
      if (!M[curr][i]) continue;
      M[curr][i] = M[i][curr] = 0;
      dfs(M, i, n);
    }
  }
};
```

## Solution 2: BFS

```cpp
class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    int n = M.size(), res = 0;
    vector<bool> visited(n, false);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (visited[i]) continue;
      q.push(i);
      while (!q.empty()) {
        int t = q.front();
        q.pop();
        visited[t] = true;
        for (int j = 0; j < n; ++j) {
          if (!M[t][j] || visited[j]) continue;
          q.push(j);
        }
      }
      ++res;
    }
    return res;
  }
};
```

## Solution 3: Union Find

初始时给每一个对象都赋上不同的标签，然后对于属于同一类的对象，在root中查找其标签，如果不同，那么将其中一个对象的标签赋值给另一个对象，注意root数组中的数字跟数字的坐标是有很大关系的，root存的是属于同一组的另一个对象的坐标，这样通过getRoot函数可以使同一个组的对象返回相同的值.

```cpp
class UnionFindSet {
 public:
  UnionFindSet(int n) {
    parents_ = vector<int>(n + 1, 0);
    ranks_ = vector<int>(n + 1, 0);

    for (int i = 0; i < parents_.size(); ++i) parents_[i] = i;
  }

  bool Union(int u, int v) {
    int pu = Find(u);
    int pv = Find(v);
    if (pu == pv) return false;

    if (ranks_[pu] > ranks_[pv]) {
      parents_[pv] = pu;
    } else if (ranks_[pv] > ranks_[pu]) {
      parents_[pu] = pv;
    } else {
      parents_[pu] = pv;
      ++ranks_[pv];
    }

    return true;
  }

  int Find(int id) {
    if (id != parents_[id]) parents_[id] = Find(parents_[id]);
    return parents_[id];
  }

 private:
  vector<int> parents_;
  vector<int> ranks_;
};

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    UnionFindSet s(n);
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (M[i][j] == 1) s.Union(i, j);

    unordered_set<int> circles;
    for (int i = 0; i < n; ++i) circles.insert(s.Find(i));

    return circles.size();
  }
};
```