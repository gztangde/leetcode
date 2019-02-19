---
title: Leetcode 301. Remove Invalid Parentheses
date: 2019-02-19 15:07:45
updated: 2019-02-19 15:07:45
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

**Note:** The input string may contain letters other than the parentheses  `(`  and  `)`.

**Example 1:**

**Input:** "()())()"
**Output:** ["()()()", "(())()"]

**Example 2:**

**Input:** "(a)())()"
**Output:** ["(a)()()", "(a())()"]

**Example 3:**

**Input:** ")("
**Output:** [""]

**Difficulty**:Hard
**Category**:DFS, BFS

<!-- more -->

------------

# Solution

## Solution 1: DFS

```cpp
// Runtime: 8 ms, faster than 97.09% of C++ online submissions for Remove Invalid Parentheses.
// Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for Remove Invalid Parentheses.
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    int l_cnt = 0, r_cnt = 0;

    // l_cnt and r_cnt is the number "()" which we need to remove;
    for (char& c : s) {
      if (c == '(')
        ++l_cnt;
      else if (c == ')')
        l_cnt == 0 ? ++r_cnt : --l_cnt;
    }

    dfs(s, 0, l_cnt, r_cnt, ans);
    if (ans.empty()) ans.emplace_back("");
    return ans;
  }

 private:
  bool isValidParentheses(string& s) {
    int cnt = 0;
    for (char& a : s) {
      if (a == '(')
        cnt++;
      else if (a == ')')
        cnt--;
      if (cnt < 0) return false;
    }
    return cnt == 0;
  }

  void dfs(string& s, int start, int l_cnt, int r_cnt, vector<string>& ans) {
    if (l_cnt == 0 && r_cnt == 0) {
      if (isValidParentheses(s)) ans.emplace_back(s);
      return;
    }

    for (int i = start; i < s.length(); ++i) {
      // deal with the repetitive element.
      if (i != start && s[i] == s[i - 1]) continue;
      if (s[i] == '(' || s[i] == ')') {
        string cur = s;
        cur.erase(i, 1);
        if (r_cnt > 0 && s[i] == ')')
          dfs(cur, i, l_cnt, r_cnt - 1, ans);
        else if (l_cnt > 0 && s[i] == '(')
          dfs(cur, i, l_cnt - 1, r_cnt, ans);
      }
    }
  }
};
```

<!-- TODO: Understand the following solution. -->

<!-- https://leetcode.com/problems/remove-invalid-parentheses/discuss/75027/easy-short-concise-and-fast-java-dfs-3-ms-solution -->

另外一种解法:

```cpp
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    dfs(s, 0, 0, ans, "()");
    return ans;
  }

 private:
  void dfs(const string &s, int last_i, int last_j, vector<string> &res, string p) {
    int n = s.size();
    int cnt = 0;
    for (int i = last_i; i < n; ++i) {
      if (s[i] == p[0])
        ++cnt;
      else if (s[i] == p[1])
        --cnt;
      if (cnt >= 0) continue;

      for (int j = last_j; j <= i; ++j) {
        if (s[j] != p[1]) continue;
        if (j > last_j && s[j - 1] == p[1]) continue;
        dfs(s.substr(0, j) + s.substr(j + 1, n - j - 1), i, j, res, p);
      }
      return;
    }

    string s1 = s;
    reverse(s1.begin(), s1.end());
    if (p[0] == '(')
      dfs(s1, 0, 0, res, ")(");
    else
      res.push_back(s1);
  }
};
```