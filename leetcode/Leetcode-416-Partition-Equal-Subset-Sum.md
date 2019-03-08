---
title: Leetcode 416. Partition Equal Subset Sum
date: 2019-03-06 13:38:45
updated: 2019-03-06 13:38:45
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Leetcode 416. Partition Equal Subset Sum

题目大意： 给了我们一个数组，问我们这个数组能不能分成两个非空子集合，使得两个子集合的元素之和相同

Given a  **non-empty**  array containing  **only positive integers**, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

**Note:**  

1. Each of the array element will not exceed 100.
2. The array size will not exceed 200.

**Example 1:**

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].

**Example 2:**

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

**Difficulty**:Medium

**Category**:

# Analyze

Cite: [Partition Equal Subset Sum 相同子集和分割](http://www.cnblogs.com/grandyang/p/5951422.html)

首先，原数组所有数字和一定是偶数，不然根本无法拆成两个和相同的子集合，那么我们只需要算出原数组的数字之和，然后除以2，就是我们的`target`。 那么问题就转换为能不能找到一个非空子集合，使得其数字之和为target。开始我想的是遍历所有子集合，算和，但是这种方法无法通过OJ的大数据集合。于是乎，动态规划 Dynamic Programming 就是我们的不二之选。我们定义一个一维的dp数组，其中dp[i]表示原数组是否可以取出若干个数字，其和为i。那么我们最后只需要返回dp[target]就行了。初始化dp[0]为true，由于题目中限制了所有数字为正数，那么就不用担心会出现和为0或者负数的情况。关键问题就是要找出状态转移方程了，我们需要遍历原数组中的数字，对于遍历到的每个数字nums[i]，需要更新dp数组，我们的最终目标是想知道dp[target]的boolean值，就要想办法用数组中的数字去凑出target，因为都是正数，所以只会越加越大，那么加上nums[i]就有可能会组成区间 [nums[i], target] 中的某个值，那么对于这个区间中的任意一个数字j，如果 dp[j - nums[i]] 为true的话，说明现在已经可以组成 j-nums[i] 这个数字了，再加上nums[i]，就可以组成数字j了，那么dp[j]就一定为true。如果之前dp[j]已经为true了，当然还要保持true，所以还要‘或’上自身，于是状态转移方程如下


# Solution

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1) return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};
```