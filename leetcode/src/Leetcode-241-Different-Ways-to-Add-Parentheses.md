---
title: Leetcode 241. Different Ways to Add Parentheses
date: 2019-01-07 09:09:31
updated: 2019-01-07 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are  `+`,  `-`  and  `*`.

**Example 1:**

> **Input:** `"2-1-1"`
> **Output:** `[0, 2]`
> **Explanation:**
> ((2-1)-1) = 0
> (2-(1-1)) = 2

**Example 2:**
> **Input:** `"2*3-4*5"`
> **Output:** `[-34, -14, -10, -10, 10]`
> **Explanation:** (2*(3-(4*5))) = -34 
> ((2*3)-(4*5)) = -14 
> ((2*(3-4))*5) = -10 
> (2*((3-4)*5)) = -10 
> (((2*3)-4)*5) = 10

**Difficulty**:Medium

**Category**:DP, Divide-and-Conquer

<!-- more -->

# Analyze

寻找一个位置，对表达式进行分割，要求分割的位置是在各个操作符的地方。下面的图片来自于博客：[花花酱 LeetCode 241. Different Ways to Add Parentheses](http://zxi.mytechroad.com/blog/leetcode/leetcode-241-different-ways-to-add-parentheses/)

![](/images/in-post/2019-01-07-Leetcode-241-Different-Ways-to-Add-Parentheses/2019-01-07-22-43-05.png)

![](/images/in-post/2019-01-07-Leetcode-241-Different-Ways-to-Add-Parentheses/2019-01-07-22-43-54.png)

# Solution

```cpp
// Author: Huahua
namespace leetcode {
int add(int a, int b) { return a + b; }
int minus(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
}  // namespace leetcode

class Solution {
 public:
  vector<int> diffWaysToCompute(string input) { return ways(input); }

 private:
  unordered_map<string, vector<int>> m_;
  const vector<int>& ways(const string& input) {
    if (m_.count(input)) return m_[input];
    vector<int> res;

    for (int i = 0; i < input.length(); ++i) {
      const char op = input[i];
      if (op == '+' || op == '-' || op == '*') {
        const string left = input.substr(0, i);
        const string right = input.substr(i + 1);

        const vector<int>& l = ways(left);
        const vector<int>& r = ways(right);

        std::function<int(int, int)> f;

        switch (op) {
          case '+':
            f = leetcode::add;
            break;
          case '-':
            f = leetcode::minus;
            break;
          case '*':
            f = leetcode::multiply;
            break;
        }

        for (int a : l)
          for (int b : r) res.emplace_back(f(a, b));
      }
    }

    if (res.empty()) res.emplace_back(std::stoi(input));

    m_[input] = res;
    return m_[input];
  }
};
```
