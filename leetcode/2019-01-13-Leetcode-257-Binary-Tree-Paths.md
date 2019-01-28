---
title: Leetcode 257. Binary Tree Paths
date: 2019-01-13 00:22:41
updated: 2019-01-13 00:22:41
categories: 
- [Leetcode]
- [Leetcode, 1_Tree]
- [Leetcode, 1_Tree, DFS]
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree, return all root-to-leaf paths.

**Note:** A leaf is a node with no children.

**Example:**

![](/images/in-post/2019-01-13-Leetcode-257-Binary-Tree-Paths/2019-01-13-00-23-59.png)

**Difficulty**:Easy

**Category**:Tree, DFS

<!-- more -->

------------

# Analyze

------------

# Solution

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
// DFS
// Runtime: 4ms
class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string cur;
    binaryTreePaths(root, cur, ans);
    return ans;
  }

 private:
  void binaryTreePaths(TreeNode* root, string cur, vector<string>& ans) {
    if (!root) return;
    cur += to_string(root->val);
    if (!root->left && !root->right) {
      ans.push_back(cur);
    }
    cur += "->";
    binaryTreePaths(root->left, cur, ans);
    binaryTreePaths(root->right, cur, ans);
  }
};
```


