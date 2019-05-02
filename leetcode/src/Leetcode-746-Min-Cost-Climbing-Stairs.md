---
title: Leetcode 746. Min Cost Climbing Stairs
date: 2018-11-19 18:09:31
updated: 2018-11-19 18:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

On a staircase, the  `i`-th step has some non-negative cost  `cost[i]`  assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

**Example 1:**  

> **Input:** cost = [10, 15, 20]
**Output:** 15
**Explanation:** Cheapest is start on cost[1], pay that cost and go to the top.

**Example 2:**  

> **Input:** cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
**Output:** 6
**Explanation:** Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

**Note:**  

1. `cost`  will have a length in the range  `[2, 1000]`.
2. Every  `cost[i]`  will be an integer in the range  `[0, 999]`.

**Difficulty**:Easy

**Category**:Array, Dynamic Programming

<!-- more -->

# Analyze

# Solution

## Solution 1: DP

这道题目不是求步数，而是每个台阶上都有一个cost，让我们求爬到顶端的最小cost是多少。这道题目还是用 `Dynamic Programming` 来做。这里我们定义一个一维的dp数组，其中`dp[i] = 爬到第i层的最小cost`，然后我们来想dp[i]如何推导。我们来思考一下如何才能到第i层呢？是不是只有两种可能性，一个是从第i-2层上直接跳上来，一个是从第i-1层上跳上来。不会再有别的方法，所以我们的dp[i]只和前两层有关系，所以可以写做如下：

`dp[i] = min(dp[i- 2] + cost[i - 2], dp[i - 1] + cost[i - 1])`

最后我们返回最后一个数字dp[n]即可，参见代码如下：

```cpp
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int len = cost.size();
    vector<int> vec_cost(len + 1, 0);

    for (int i = 2; i < len + 1; ++i) {
      vec_cost[i] = min(vec_cost[i - 2] + cost[i - 2], vec_cost[i - 1] + cost[i - 1]);
    }
    return vec_cost.back();
  }
};
```

对空间复杂度进行优化,**dp[i]仅仅依赖前面两个的值dp[i-1], dp[i-2]**，所以我们不必把整个dp数组都记录下来，只需用两个变量 prev 和 cur 来记录前两个值，然后不停的用新得到的值来覆盖它们就好了。我们初始化 `prev = 0, cur = 0`，然后遍历 cost 数组.

优化之后空间复杂度 `O(n) --> O(1)`

```cpp
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int prev = 0, cur = 0;
    for (int& c : cost) {
      int temp = cur;
      cur = min(prev, cur) + c;
      prev = temp;
    }
    return min(prev, cur);
  }
};
```

## Solution 2: Recursive

```cpp
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    unordered_map<int, int> memo;
    return helper(cost, cost.size(), memo);
  }
  int helper(vector<int>& cost, int i, unordered_map<int, int>& memo) {
    if (memo.count(i)) return memo[i];
    if (i <= 1) return memo[i] = cost[i];
    return memo[i] = (i == cost.size() ? 0 : cost[i]) + min(helper(cost, i - 1, memo), helper(cost, i - 2, memo));
  }
};
```