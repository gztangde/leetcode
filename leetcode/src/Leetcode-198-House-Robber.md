---
title: Leetcode 198. House Robber
date: 2019-01-25 20:17:36
updated: 2019-01-25 20:17:36
categories: 
- [Leetcode]
tags: Leetcode
notshow: true
top:
---

# Question

题目大意: 相当于在一列数组中取出一个或多个不相邻数，使其和最大

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and  **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight  **without alerting the police**.

**Example 1:**

> **Input:** [1,2,3,1]
> **Output:** 4
> **Explanation:** Rob house 1 (money = 1) and then rob house 3 (money = 3).
             > Total amount you can rob = 1 + 3 = 4.

**Example 2:**

> **Input:** [2,7,9,3,1]
> **Output:** 12
> **Explanation:** Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             > Total amount you can rob = 2 + 9 + 1 = 12.

**Difficulty**:Easy

**Category**:Dynamic-Programming

<!-- more -->

# Solution

![](/images/in-post/2019-01-25-Leetcode-198-House-Robber/2019-01-25-20-42-28.png)

## Solution 1: DP

维护一个一位数组 dp，其中 dp[i] = 到 i 位置时不相邻数能形成的最大和，那么状态转移方程怎么写呢，我们先拿一个简单的例子来分析一下，比如说 nums 为 {3, 2, 1, 5}，那么我们来看我们的dp数组应该是什么样的，首先dp[0]=3没啥疑问，再看dp[1]是多少呢，由于3比2大，所以我们抢第一个房子的3，当前房子的2不抢，所以dp[1]=3，那么再来看dp[2]，由于不能抢相邻的，所以我们可以用再前面的一个的dp值加上当前的房间值，和当前房间的前面一个dp值比较，取较大值当做当前dp值，所以我们可以得到状态转移方程dp[i] = max(num[i] + dp[i - 2], dp[i - 1]), 由此看出我们需要初始化dp[0]和dp[1]，其中dp[0]即为num[0]，dp[1]此时应该为max(num[0], num[1])

```cpp
class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) dp[i] = max((i > 1 ? dp[i - 2] : 0) + nums[i], i > 0 ? dp[i - 1] : 0);
    return dp.back();
  }
};
```

优化空间复杂度 `O(n) ---> O(1)`, 定义两个变量 `robEven` 和 `robOdd`, 其中的 `robEven` 表示只抢劫偶数的房子,而 `robOdd` 表示只抢劫奇数房子. 在遍历的时候, 不断更新这两个变量. 这种奇偶数分开更新的方式可以保证数组的最大和的数字并不相邻.  

```cpp
class Solution {
 public:
  int rob(vector<int> &nums) {
    int robEven = 0, robOdd = 0, n = nums.size();
    for (int i = 0; i < n; ++i) i % 2 == 0 ? robEven = max(robEven + nums[i], robOdd) : robOdd = max(robEven, robOdd + nums[i]);
    return max(robEven, robOdd);
  }
};
```

另外一种方式,抢当前房子或不抢当前房子:

```cpp
class Solution {
 public:
  int rob(vector<int> &nums) {
    int rob = 0, notRob = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
      int preRob = rob, preNotRob = notRob;
      rob = preNotRob + nums[i];
      notRob = max(preRob, preNotRob);
    }
    return max(rob, notRob);
  }
};
```

## Solution 2: Recursion + Memorization

Time complexity: O(n), Space complexity: O(n)

```cpp
class Solution {
 public:
  int rob(vector<int>& nums) {
    const int n = nums.size();
    m_ = vector<int>(n, -1);
    return rob(nums, n - 1);
  }

 private:
  vector<int> m_;
  int rob(const vector<int>& nums, int i) {
    if (i < 0) return 0;
    if (m_[i] >= 0) return m_[i];
    m_[i] = max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
    return m_[i];
  }
};
```

