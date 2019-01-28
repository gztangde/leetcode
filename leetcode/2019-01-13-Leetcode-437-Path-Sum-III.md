---
title: Leetcode 437. Path Sum III
date: 2019-01-13 14:19:01
updated: 2019-01-13 14:19:01
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

**Example:**

![](/images/in-post/2019-01-13-Leetcode-437-Path-Sum-III/2019-01-13-14-19-46.png)

**Difficulty**:Easy
**Category**:Tree

<!-- more -->

------------

# Analyze

------------

# Solution

<!-- TODO: This solution is not very good for this question -->

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Runtime: 36ms
class Solution {
 public:
  int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;
    int c = curSum(root, sum, 0);
    int l = pathSum(root->left, sum);
    int r = pathSum(root->right, sum);
    return c + l + r;
  }

 private:
  int curSum(TreeNode* root, int& sum, int cur) {
    if (!root) return 0;
    cur += root->val;
    int l = curSum(root->left, sum, cur);
    int r = curSum(root->right, sum, cur);
    return (cur == sum) + l + r;
  }
};
```


