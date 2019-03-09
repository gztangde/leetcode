---
title: Closet Two Sum
date: 2019-03-08 23:40:34
updated: 2019-03-08 23:40:34
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

```cpp
// 2Sum Closest
int twoSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
  int diff = INT_MAX, res;
  int i = 0, j = nums.size() - 1;
  while (i < j) {
    int sum = nums[i] + nums[j];
    if (abs(sum - target) < diff) {
      res = sum;
      diff = abs(sum - target);
    }
    if (sum < target)
      i++;
    else if (sum > target)
      j--;
    else
      break;
  }
  return res;
}
```