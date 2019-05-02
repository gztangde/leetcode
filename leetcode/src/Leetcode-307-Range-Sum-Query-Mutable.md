---
title: Leetcode 307. Range Sum Query Mutable
date: 2019-03-19 16:27:53
updated: 2019-03-19 16:27:53
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Leetcode 307. Range Sum Query Mutable

题目大意：给你一个数组，让你求一个范围之内所有元素的和，数组元素可以更改。

Given an integer array  _nums_, find the sum of the elements between indices  _i_  and  _j_  (_i_  ≤  _j_), inclusive.

The  _update(i, val)_  function modifies  _nums_  by updating the element at index  _i_  to  _val_.

**Example:**

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

**Note:**

1. The array is only modifiable by the  _update_  function.
2. You may assume the number of calls to  _update_  and  _sumRange_  function is distributed evenly.

**Difficulty**:Medium

**Category**:

# Analyze

# Solution

## Solution 1: Fenwick Tree (Binary Indexed Tree)

在这道题目中可以考虑使用 `Binary Indexed Tree` 的数据结构来求解, 这种数据结构可以得到 `query`, `update` 的时间复杂度都为 O(log n)

Time complexity: init O(nlogn), query: O(logn), update: O(logn)

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

class NumArray {
 public:
  NumArray(vector<int> nums) : nums_(std::move(nums)), tree_(nums_.size()) {
    for (int i = 0; i < nums_.size(); ++i) tree_.update(i + 1, nums_[i]);
  }

  void update(int i, int val) {
    tree_.update(i + 1, val - nums_[i]);
    nums_[i] = val;
  }

  int sumRange(int i, int j) { return tree_.query(j + 1) - tree_.query(i); }

 private:
  vector<int> nums_;
  FenwickTree tree_;
};

```

## Brute Force

这道题目直接使用 Brute force 的方式来求解也是可以通过的, 只需要使用一个`data`来保存当前数组的数据,然后每次 `updata` 的时候变化数据, `sumRange()` 的时候求取区间的和, 这样就可以得到结果了.

Time complexity: init O(1), update: O(1), sumrange O(j - i)

```cpp
class NumArray {
 public:
  NumArray(vector<int> nums) : data(std::move(nums)) {}

  void update(int i, int val) { data[i] = val; }

  int sumRange(int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; ++k) sum += data[k];
    return sum;
  }

 private:
  vector<int> data;
};
```

## Solution 3: Segment Tree

```cpp
class SegmentTreeNode {
 public:
  SegmentTreeNode(int start, int end, int sum, SegmentTreeNode* left = nullptr, SegmentTreeNode* right = nullptr)
      : start(start), end(end), sum(sum), left(left), right(right) {}
  SegmentTreeNode(const SegmentTreeNode&) = delete;
  SegmentTreeNode& operator=(const SegmentTreeNode&) = delete;
  ~SegmentTreeNode() {
    delete left;
    delete right;
    left = right = nullptr;
  }

  int start;
  int end;
  int sum;
  SegmentTreeNode* left;
  SegmentTreeNode* right;
};

class NumArray {
 public:
  NumArray(vector<int> nums) {
    nums_.swap(nums);
    if (!nums_.empty()) root_.reset(buildTree(0, nums_.size() - 1));
  }

  void update(int i, int val) { updateTree(root_.get(), i, val); }

  int sumRange(int i, int j) { return sumRange(root_.get(), i, j); }

 private:
  vector<int> nums_;
  std::unique_ptr<SegmentTreeNode> root_;

  SegmentTreeNode* buildTree(int start, int end) {
    if (start == end) {
      return new SegmentTreeNode(start, end, nums_[start]);
    }
    int mid = start + (end - start) / 2;
    auto left = buildTree(start, mid);
    auto right = buildTree(mid + 1, end);
    auto node = new SegmentTreeNode(start, end, left->sum + right->sum, left, right);
    return node;
  }

  void updateTree(SegmentTreeNode* root, int i, int val) {
    if (root->start == i && root->end == i) {
      root->sum = val;
      return;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if (i <= mid) {
      updateTree(root->left, i, val);
    } else {
      updateTree(root->right, i, val);
    }
    root->sum = root->left->sum + root->right->sum;
  }

  int sumRange(SegmentTreeNode* root, int i, int j) {
    if (i == root->start && j == root->end) {
      return root->sum;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if (j <= mid) {
      return sumRange(root->left, i, j);
    } else if (i > mid) {
      return sumRange(root->right, i, j);
    } else {
      return sumRange(root->left, i, mid) + sumRange(root->right, mid + 1, j);
    }
  }
};
```

# Relative questions

博客文章链接: [Range Sum Query - Mutable 区域和检索 - 可变](http://www.cnblogs.com/grandyang/p/4985506.html)