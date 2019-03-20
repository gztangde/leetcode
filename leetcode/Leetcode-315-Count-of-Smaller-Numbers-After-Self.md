---
title: Leetcode 315. Count of Smaller Numbers After Self
date: 2019-03-19 16:46:56
updated: 2019-03-19 16:46:56
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Question

You are given an integer array  _nums_  and you have to return a new  _counts_  array. The  _counts_  array has the property where  `counts[i]`  is the number of smaller elements to the right of  `nums[i]`.

**Example:**

**Input:** [5,2,6,1]
**Output:** `[2,1,1,0]
**Explanation:**`
To the right of 5 there are **2** smaller elements (2 and 1).
To the right of 2 there is only **1** smaller element (1).
To the right of 6 there is **1** smaller element (1).
To the right of 1 there is **0** smaller element.

**Difficulty**:Medium

**Category**:

# Solution

## Solution 1: Binary Indexed Tree (Fenwick Tree)

Time complexity: O(n log n), Space complexity: O(k), k: # of unique elements

```cpp
class FenwickTree {
 public:
  FenwickTree(int n) : sum_(n + 1, 0) {}

  void update(int i, int delta) {
    while (i < sum_.size()) {
      sum_[i] += delta;
      i += lowbit(i);
    }
  }

  int query(int i) const {
    int sum = 0;
    while (i > 0) {
      sum += sum_[i];
      i -= lowbit(i);
    }
    return sum;
  }

 private:
  vector<int> sum_;
  static inline int lowbit(int x) { return x & (-x); }
};

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    // Sort the unique number
    set<int> sorted(nums.begin(), nums.end());
    unordered_map<int, int> ranks;
    int rank = 0;
    for (const int num : sorted) ranks[num] = ++rank;

    vector<int> ans;
    FenwickTree tree(ranks.size());

    for (int i = nums.size() - 1; i >= 0; --i) {
      // Check how many numbers are smaller than the current number.
      // ranks[nums[i]] is the rank in for this number
      ans.push_back(tree.query(ranks[nums[i]] - 1));
      // Increase the count of the rank of current number.
      tree.update(ranks[nums[i]], 1);
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};
```

## Solution 2: Binary Search (插入排序)

从给定数组的最后一个元素开始, 使用二分插入的方式插入建立一个新的数组,这样新的数组就是有序的了,这个时候该数字在新数组中的坐标就是原数组中其右边所有最小数字的个数. 

```cpp
class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> temp, ans(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i) {
      // Binary Search
      int left = 0, right = temp.size();
      while (left < right) {
        int mid = left + (right - left) / 2;
        // Find the right position in the new array
        temp[mid] >= nums[i] ? right = mid : left = mid + 1;
      }
      ans[i] = right;
      temp.insert(temp.begin() + right, nums[i]);
    }
    return ans;
  }
};
```