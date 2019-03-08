---
title: Leetcode 637. Average of Levels in Binary Tree
date: 2019-01-14 16:00:10
updated: 2019-01-14 16:00:10
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

**Example 1:**  

**Input:**

```
    3
   / \
  9  20
    /  \
   15   7

```

**Output:** [3, 14.5, 11]
**Explanation:**
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

**Note:**  

1. The range of node's value is in the range of 32-bit signed integer.

**Difficulty**:Medium

**Category**:Tree

<!-- more -->

------------

# Analyze

# Solution

## Solution 1: DFS

利用的递归的先序遍历，但是其根据判断当前层数 level 跟结果 res 中已经初始化的层数之间的关系对比，能把当前结点值累计到正确的位置，而且该层的结点数也自增1，这样我们分别求了两个数组，一个数组保存了每行的所有结点值，另一个保存了每行结点的个数，这样对应位相除就是我们要求的结果了.

Time Complexity: O(n)
Space Complexity: O(n)

> Runtime: 24 ms, faster than 99.64% of C++ online submissions for Average of Levels in Binary Tree.
> Memory Usage: 22.3 MB, less than 28.32% of C++ online submissions for Average of Levels in Binary Tree.

```cpp
class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    if (root == nullptr) return {};
    vector<pair<long long, int>> sum_count; // [sumForlevel, cnt]
    vector<double> ans;
    preorder(root, 0, sum_count);

    for (const auto& p : sum_count) ans.push_back(static_cast<double>(p.first) / p.second);
    return ans;
  }

 private:
  void preorder(TreeNode* root, int depth, vector<pair<long long, int>>& sum_count) {
    if (root == nullptr) return;
    if (depth >= sum_count.size()) sum_count.push_back({0, 0});
    sum_count[depth].first += root->val;
    ++sum_count[depth].second;
    preorder(root->left, depth + 1, sum_count);
    preorder(root->right, depth + 1, sum_count);
  }
};
```

## Solution 2: Iteration

Time Complexity: O(n)
Space Complexity: O(h)

```cpp
class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    if (root == nullptr) return {};
    vector<double> ans;
    vector<TreeNode*> curr, next;
    curr.push_back(root);

    // process every level one by one
    while (!curr.empty()) {
      long long sum = 0;
      for (const auto& node : curr) {
        sum += node->val;
        if (node->left) next.push_back(node->left);
        if (node->right) next.push_back(node->right);
      }

      ans.push_back(static_cast<double>(sum) / curr.size());

      curr.swap(next);
      next.clear();
    }

    return ans;
  }
};
```

也可以使用 `queue` 来实现：

```cpp
class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    if (!root) return {};
    vector<double> res;
    queue<TreeNode*> q{{root}};
    while (!q.empty()) {
      int n = q.size();
      double sum = 0;
      for (int i = 0; i < n; ++i) {
        TreeNode* t = q.front();
        q.pop();
        sum += t->val;
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      res.push_back(sum / n);
    }
    return res;
  }
};
```