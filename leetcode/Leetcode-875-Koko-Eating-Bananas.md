---
title: Leetcode 875. Koko Eating Bananas
date: 2019-03-12 17:27:46
updated: 2019-03-12 17:27:46
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Leetcode 875. Koko Eating Bananas

Koko loves to eat bananas. There are  `N` piles of bananas, the  `i`-th pile has  `piles[i]`  bananas. The guards have gone and will come back in  `H`  hours.

Koko can decide her bananas-per-hour eating speed of  `K`. Each hour, she chooses some pile of bananas, and eats K bananas from that pile. If the pile has less than  `K`  bananas, she eats all of them instead, and won't eat any more bananas during this hour.

Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.

Return the minimum integer  `K`  such that she can eat all the bananas within  `H`  hours.

**Example 1:**

**Input:** piles = [3,6,7,11], H = 8
**Output:** 4

**Example 2:**

**Input:** piles = [30,11,23,4,20], H = 5
**Output:** 30

**Example 3:**

**Input:** piles = [30,11,23,4,20], H = 6
**Output:** 23

**Note:**

- `1 <= piles.length <= 10^4`
- `piles.length <= H <= 10^9`
- `1 <= piles[i] <= 10^9`

**Difficulty**:Medium

**Category**:

# Solution

`Koko`　吃香蕉的速度是 `K` , 吃香蕉的最大速度去所有香蕉堆里面的最大值就好，所以有`left = 1, right = *max_element(piles.begin(), piles.end()) + 1`; 其中最右边的值是可以不选取的，为此我们计算按照这个取得的中间速度计算 `kolo`能不能在这个中间速度`mid`内吃完香蕉。如果吃完的时间花费小于限制的时间，那我们就减下吃香蕉的速度，反之就增加吃香蕉的速度。

## Solution 1: Binary Search

Time complexity: O(log max_speed), Space complexity: O(1)

```cpp
class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int H) {
    // 1) [l, r) -- This is the range for the number of piles
    int left = 1, right = *max_element(piles.begin(), piles.end()) + 1;
    while (left < right) {
      int mid = left + (right - left) / 2, h = 0;
      for (int& pile : piles) h += (pile + mid - 1) / mid;
      h <= H ? right = mid : left = mid + 1;  // Can finished
    }
    return left;
  }
};
```