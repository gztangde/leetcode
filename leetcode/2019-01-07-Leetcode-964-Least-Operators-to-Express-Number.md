---
title: Leetcode 964. Least Operators to Express Number
date: 2019-01-07 09:09:31
updated: 2019-01-07 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a single positive integer  `x`, we will write an expression of the form  `x (op1) x (op2) x (op3) x ...` where each operator  `op1`,  `op2`, etc. is either addition, subtraction, multiplication, or division (`+`,  `-`,  `*`, or  `/)`. For example, with  `x = 3`, we might write  `3 * 3 / 3 + 3 - 3` which is a value of  3.

When writing such an expression, we adhere to the following conventions:

1. The division operator (`/`) returns rational numbers.
2. There are no parentheses placed anywhere.
3. We use the usual order of operations: multiplication and division happens before addition and subtraction.
4. It's not allowed to use the unary negation operator (`-`). For example, "`x - x`" is a valid expression as it only uses subtraction, but "`-x + x`" is not because it uses negation.

We would like to write an expression with the least number of operators such that the expression equals the given  `target`. Return the least number of operators used.

**Example 1:**

> **Input:** x = 3, target = 19
> **Output:** 5
> **Explanation:** 3 * 3 + 3 * 3 + 3 / 3.  The expression contains 5 operations.

**Example 2:**

> **Input:** x = 5, target = 501
> **Output:** 8
> **Explanation:** 5 * 5 * 5 * 5 - 5 * 5 * 5 + 5 / 5.  The expression contains 8 operations.

**Example 3:**

> **Input:** x = 100, target = 100000000
> **Output:** 3
> **Explanation:** 100 * 100 * 100 * 100.  The expression contains 3 operations.

**Note:**

- `2 <= x <= 100`
- `1 <= target <= 2 * 10^8`

**Difficulty**:Hard

**Category**:Dynamic-Programming, Math

<!-- more -->

------------

# Analyze

分析思路参考了博客： [花花酱 LeetCode 964. Least Operators to Express Number](https://zxi.mytechroad.com/blog/uncategorized/leetcode-964-least-operators-to-express-number/)

该题目具有的性质：

![](/images/in-post/2019-01-07-Leetcode-964-Least-Operators-to-Express-Number/2019-01-07-10-38-51.png)

1. 因为最后求解的`1 <= target <= 2 * 10^8`，因此最后一定是一个整数，所以中间的正数和负数所需要的操作符号个数的相同的，因此我们仅仅考虑绝对值的情况就好了。
2. 最后的操作符个数就是使用的`x`的个数减去`1`，相当于是最前面可以没有符号，后面的各个元素都是一个元素对应了一个符号（可能是`+， -， *, /`).
3. 只有在一种情况下能够得到`1`，那就是`x/x`

如何计算得到最合适的：

![](/images/in-post/2019-01-07-Leetcode-964-Least-Operators-to-Express-Number/2019-01-07-14-30-40.png)

搜索方式的解答过程如下图所示：

![](/images/in-post/2019-01-07-Leetcode-964-Least-Operators-to-Express-Number/2019-01-07-14-57-20.png)

动态规划的解答方式如下图所示：
![](/images/in-post/2019-01-07-Leetcode-964-Least-Operators-to-Express-Number/2019-01-07-15-02-49.png)

------------

# Solution

## Solution 1: set

使用`set`来保存所有的中间值，利用了`set`可以將`key`进行排序存储的特殊性，每一次都处理最小的元素，这样就可以最快的找到最短的方式得到结果

```cpp
class Solution {
 public:
  int leastOpsExpressTarget(int x, int target) {
    set<pair<int, int>> q_set;
    unordered_set<int> res;
    q_set.emplace(0, target);
    while (!q_set.empty()) {
      const auto it = begin(q_set);
      const int temp_count = it->first;
      const int temp_target = it->second;
      q_set.erase(it);
      if (temp_target == 0) return temp_count - 1;
      if (res.count(temp_target)) continue;
      res.insert(temp_target);
      int n = log(temp_target) / log(x);
      int next_target_l = temp_target - pow(x, n);
      q_set.emplace(temp_count + (n == 0 ? 2 : n), next_target_l);
      int next_target_r = pow(x, n + 1) - temp_target;
      q_set.emplace(temp_count + n + 1, next_target_r);
    }
    return -1;
  }
};
```

## Solution 2: heap

第二种方式来自于博客文章：[花花酱 LeetCode 964. Least Operators to Express Number](https://zxi.mytechroad.com/blog/uncategorized/leetcode-964-least-operators-to-express-number/)，基本的实现思路没有变化。

```cpp
class Solution {
 public:
  int leastOpsExpressTarget(int x, int target) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    unordered_set<int> s;
    q.emplace(0, target);
    while (!q.empty()) {
      const int c = q.top().first;
      const int t = q.top().second;
      q.pop();
      if (t == 0) return c - 1;
      if (s.count(t)) continue;
      s.insert(t);
      int n = log(t) / log(x);
      int l = t - pow(x, n);
      q.emplace(c + (n == 0 ? 2 : n), l);
      int r = pow(x, n + 1) - t;
      q.emplace(c + n + 1, r);
    }
    return -1;
  }
};
```

## Solution 3: DP --- Runtime error

```cpp
class Solution {
 public:
  int leastOpsExpressTarget(int x, int target) { return dp(x, target); }

 private:
  unordered_map<int, int> res_map;
  int dp(int x, int target) {
    if (target == 0) return 0;
    if (target < x) return min(2 * target - 1, 2 * (x - target));
    if (res_map.count(target)) return res_map.at(target);
    int n = log(target) / log(x);
    int p = pow(x, n);

    int left = target - p;
    if (target == p) {
      res_map[target] = n - 1;
      return n - 1;
    }
    int res = dp(x, left) + n;

    int right = p * x - target;
    if (right < target) res = min(res, dp(x, right) + n + 1);
    res_map[target] = res;
    return res;
  }
};
```

------------
