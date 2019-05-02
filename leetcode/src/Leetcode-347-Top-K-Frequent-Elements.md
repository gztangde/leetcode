---
title: Leetcode 347. Top K Frequent Elements
date: 2019-01-31 19:02:31
updated: 2019-01-31 19:02:31
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a non-empty array of integers, return the  **_k_**  most frequent elements.

**Example 1:**

**Input:** nums = [1,1,1,2,2,3], k = 2
**Output:** [1,2]

**Example 2:**

**Input:** nums = [1], k = 1
**Output:** [1]

**Note:**

-   You may assume  _k_  is always valid, 1 ≤  _k_  ≤ number of unique elements.
-   Your algorithm's time complexity  **must be**  better than O(_n_  log  _n_), where  _n_  is the array's size.

**Difficulty**:Medium

**Category**:Bubble Sort

<!-- more -->

# Analyze

# Solution

## Solution 1: 桶排序

```cpp
// Bucket sort
// Runtime: 12ms > 99.14%
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int, int> m_;
    int max_freq = 1;
    for (int& num : nums) max_freq = max(++m_[num], max_freq);
    map<int, vector<int>> bucket;
    for (auto& val : m_) bucket[val.second].emplace_back(val.first);
    // Find the Top K frequent elements
    for (int i = max_freq; i >= 1; --i) {
      if (bucket.find(i) != bucket.end()) {
        ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
        if (ans.size() == k) return ans;
      } else
        continue;
    }
    return ans;
  }
};
```

## Solution 2: Quick Sort

```cpp
// Bucket sort
// Runtime: 12ms > 99.14%
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int, int> m_;
    for (int& num : nums) ++m_[num];
    priority_queue<pair<int, int>> q;
    for (auto& val : m_) {
      q.emplace(-val.second, val.first);
      if (q.size() > k) q.pop();
    }
    // Find the Top K frequent elements
    while (k--) {
      ans.emplace_back(q.top().second);
      q.pop();
    }
    return ans;
  }
};
```