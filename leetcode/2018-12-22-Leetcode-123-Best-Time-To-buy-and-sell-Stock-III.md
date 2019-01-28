---
title: Leetcode 123. Best Time to Buy and Sell Stock III
date: 2018-12-22 09:09:31
updated: 2018-12-22 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Say you have an array for which the  _i_th  element is the price of a given stock on day  _i_.

Design an algorithm to find the maximum profit. You may complete at most  _two_  transactions.

**Note:** You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

**Example 1:**

> **Input:** [3,3,5,0,0,3,1,4]
> **Output:** 6
> **Explanation:** Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

**Example 2:**

> **Input:** [1,2,3,4,5]
> **Output:** 4
> **Explanation:** Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4. Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

**Example 3:**

> **Input:** [7,6,4,3,1]
> **Output:** 0
> **Explanation:** In this case, no transaction is done, i.e. max profit = 0.

**Difficulty**:Hard
**Category**:Dynamic-Programming

<!-- more -->

------------

# Analyze

思路参考[博客](http://www.cnblogs.com/grandyang/p/4281975.html), 在这道题目中我们使用了两个变量：

- `local`, 其中`local[i][j]`表示了在第`i`天达到`j`次交易数的时候，能够达到的最大利润。（并且最后一次交易必须发生在第i天）
- `global`, 其中`global[i][j]`表示在第`i`天达到`j`次交易的最大利润（这里不限制交易的位置）

```cpp
local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
global[i][j] = max(local[i][j], global[i - 1][j])
```

所以局部第`j`次交易的最大利润就是： 上一天的第`j-1`次交易的全局最大值+昨天到今天大约0的差值 Vs 上一天交易`j`次的局部最大利润+昨天到今天的价格差值。

- ‘global[i - 1][j - 1] + max(diff, 0)’这种情况就是，昨天交易得到的全局最大值+今天和昨天的差价，如果差价为负数，那么就加上的是0

所谓的全局最大利润：`global[i][j] = max(local[i][j], global[i - 1][j])`就是今天的局部最大利润，或者昨天的第‘j’次交易的最大利润（这说明昨天到今天没有利润的）

------------

# Solution

```cpp
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) return 0;
    int n = prices.size(), g[n][3] = {0}, l[n][3] = {0};
    for (int i = 1; i < prices.size(); ++i) {
      int diff = prices[i] - prices[i - 1];
      for (int j = 1; j <= 2; ++j) {
        l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
        g[i][j] = max(l[i][j], g[i - 1][j]);
      }
    }
    return g[n - 1][2];
  }
};
```

<!-- TODO: 
1. There is a way to record the different the positation the first buy the stock.

-->