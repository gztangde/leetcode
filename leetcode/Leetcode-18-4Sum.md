---
title: Leetcode 18. 4Sum
date: 2018-11-19 06:09:31
updated: 2018-11-19 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array  `nums`  of  _n_  integers and an integer  `target`, are there elements  _a_,  _b_,  _c_, and  _d_  in  `nums`  such that  _a_  +  _b_  +  _c_  +  _d_  =  `target`? Find all unique quadruplets in the array which gives the sum of  `target`.

**Note:**

The solution set must not contain duplicate quadruplets.

**Example:**

> Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
> A solution set is:
> [
>  [-1,  0, 0, 1],
>  [-2, -1, 1, 2],
>  [-2,  0, 0, 2]
> ]

**Difficulty**:Medium

**Category**:Array, Hash Table, Two Points.

<!-- more -->

# Analyze

方案一： 对数组进行排序，然后固定两个值，寻找另外两个数值，左右夹逼的方式，这种情况的时间复杂度是`O(n^3)`

方案二： 使用一个`Hashmap`先缓存两个数的和，时间复杂度：平均`O(n^2)`, 最差`O(n^4)`, 空间复杂度`O(n^2)`

# Solution

**Solution 1（方案一）:先排序固定两个数值，然后夹逼的方式**

```cpp
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    set<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < int(nums.size() - 3); ++i) {
      for (int j = i + 1; j < int(nums.size() - 2); ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int left = j + 1, right = nums.size() - 1;

        while (left < right) {
          int sum = nums[i] + nums[j] + nums[left] + nums[right];
          if (sum == target) {
            vector<int> out{nums[i], nums[j], nums[left], nums[right]};
            res.insert(out);
            ++left;
            --right;
          } else if (sum < target)
            ++left;
          else
            --right;
        }
      }
    }
    return vector<vector<int>>(res.begin(), res.end());
  }
};
```

**Solution 2（方案一）:先排序固定两个数值，然后夹逼的方式**

第二种代码风格，来自：[《Leetcode 题解》](https://github.com/soulmachine/leetcode)

```cpp
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) return res;
    sort(nums.begin(), nums.end());

    auto last = nums.end();
    for (auto a = nums.begin(); a < prev(last, 3); ++a) {
      for (auto b = next(a); b < prev(last, 2); ++b) {
        auto c = next(b);
        auto d = prev(last);
        while (c < d) {
          if (*a + *b + *c + *d < target) {
            ++c;
          } else if (*a + *b + *c + *d > target) {
            --d;
          } else {
            res.push_back({*a, *b, *c, *d});
            ++c;
            --d;
          }
        }
      }
    }
    // Remove the repeating elements.
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
  }
};
```

**Solution 3（方案二）:HashMap**

第二种代码风格，来自：[《Leetcode 题解》](https://github.com/soulmachine/leetcode)

```cpp
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) return res;
    sort(nums.begin(), nums.end());

    unordered_map<int, vector<pair<int, int>>> cache;
    for (size_t a = 0; a < nums.size(); ++a) {
      for (size_t b = a + 1; b < nums.size(); ++b) {
        cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
      }
    }

    for (int c = 0; c < nums.size(); ++c) {
      for (size_t d = c + 1; d < nums.size(); ++d) {
        const int key = target - nums[c] - nums[d];
        if (cache.find(key) == cache.end()) continue;

        const auto& vec = cache[key];
        for (size_t k = 0; k < vec.size(); ++k) {
          if (c <= vec[k].second) {
            continue;
          }
          res.push_back({nums[vec[k].first], nums[vec[k].second], nums[c], nums[d]});
        }
      }
    }

    // Remove the repeating elements.
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
  }
};
```

------------

# Leetcode Question Summary

1. 不能使用Vector `emplace_back`函数的情况 （方案二）

如果要放入`vector`里面的内容，是一个数组，那么就不能够使用`emplac_back` 函数，需要使用push_bach函数。

**Error**

```cpp
vector<vector<int>> res;
res.emplace_back({*a, *b, *c, *d});
```

**True**

```cpp
vector<vector<int>> res;
res.push_back({*a, *b, *c, *d});
```