---
title: Leetcode 22. Generate Parentheses
date: 2018-10-26 06:09:31
updated: 2018-10-22 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given  _n_  pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

<!-- more -->

For example, given  _n_  = 3, a solution set is:
> [
>  "((()))",
>  "(()())",
>  "(())()",
>  "()(())",
>  "()()()"
>]

# solution

```cpp
// Runtime: 16 ms, faster than 49.46% of C++ online submissions for Generate Parentheses.
// Memory Usage: 17.4 MB, less than 100.00% of C++ online submissions for Generate Parentheses.
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    generateParenthesisDFS(n, n, "", ans);
    return ans;
  }

 private:
  void generateParenthesisDFS(int left_n, int right_n, string out, vector<string>& ans) {
    if (left_n > right_n) return;
    if (left_n == 0 && right_n == 0) {
      ans.emplace_back(out);
    } else {
      if (left_n > 0) generateParenthesisDFS(left_n - 1, right_n, out + "(", ans);
      if (right_n > 0) generateParenthesisDFS(left_n, right_n - 1, out + ")", ans);
    }
  }
};
```

在 DFS 的函数中， 我们尽量不要使用太多的局部变量， 这样会造成栈的使用空间较多。 对上面的代码， 优化如下：

```cpp
// Runtime: 12 ms, faster than 92.06% of C++ online submissions for Generate Parentheses.
// Memory Usage: 14 MB, less than 100.00% of C++ online submissions for Generate Parentheses.
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string out;
    generateParenthesisDFS(n, n, out, ans);
    return ans;
  }

 private:
  void generateParenthesisDFS(int left_n, int right_n, string& out, vector<string>& ans) {
    if (left_n + right_n == 0) {
      ans.emplace_back(out);
      return;
    }
    if (left_n > right_n) return;

    if (left_n > 0) {
      generateParenthesisDFS(left_n - 1, right_n, out += "(", ans);
      out.pop_back();
    }
    if (right_n > 0) {
      generateParenthesisDFS(left_n, right_n - 1, out += ")", ans);
      out.pop_back();
    }
  }
};
```
