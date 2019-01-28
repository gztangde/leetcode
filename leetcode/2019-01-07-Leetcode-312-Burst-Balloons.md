---
title: Leetcode 312. Burst Balloons
date: 2019-01-07 09:09:31
updated: 2019-01-07 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given  `n`  balloons, indexed from  `0`  to  `n-1`. Each balloon is painted with a number on it represented by array  `nums`. You are asked to burst all the balloons. If the you burst balloon  `i`  you will get  `nums[left] * nums[i] * nums[right]`  coins. Here  `left`  and  `right`  are adjacent indices of  `i`. After the burst, the  `left`  and  `right`  then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

**Note:**

- You may imagine  `nums[-1] = nums[n] = 1`. They are not real therefore you can not burst them.
- 0 ≤  `n`  ≤ 500, 0 ≤  `nums[i]`  ≤ 100

**Example:**

> **Input:** `[3,1,5,8]`
> **Output:** `167 
> **Explanation:**` nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> [] coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

**Difficulty**:Hard

**Category**:Dynamic-Programming, Divide-And-Conquer

<!-- more -->

------------

# Analyze

------------

# Solution

![](/images/in-post/2019-01-07-Leetcode-312-Burst-Balloons/2019-01-07-20-31-26.png)

```cpp
class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    const int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    // c[i][j] = maxCoin(nums[i:j+1])
    vector<vector<int>> c(n + 2, vector<int>(n + 2, 0));

    for (int l = 1; l <= n; ++l) {
      for (int i = 1; i <= n - l + 1; ++i) {
        int j = i + l - 1;
        for (int k = i; k <= j; ++k) {
          c[i][j] = max(c[i][j], c[i][k - 1] + c[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1]);
        }
      }
    }

    return c[1][n];
  }
};
```

<!-- TODO:怎么可以得到第一层的循环条件是对应的长度呢 -->