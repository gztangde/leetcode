---
title: Leetcode 199. Binary Tree Right Side View
date: 2019-01-12 22:19:11
updated: 2019-01-12 22:19:11
categories: 
- [Leetcode]
- [Leetcode, 1_Tree]
- [Leetcode, Tree, DFS]
- [Leetcode, Tree, BFS]
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree, imagine yourself standing on the  _right_  side of it, return the values of the nodes you can see ordered from top to bottom.

![](/images/in-post/2019-01-12-Leetcode-199-Binary-Tree-Right-Side-View/2019-01-12-22-19-46.png)

**Difficulty**:Medium

**Category**:Tree, Depth-First-Search, Breadth-First-Search

<!-- more -->

# Analyze

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
// Runtime: 4ms
class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    std::vector<int> ans;
    rightSideView(root, 0, ans);
    return ans;
  }

 private:
  void rightSideView(TreeNode* root, int dep, std::vector<int>& ans) {
    if (!root) return;
    if (dep == ans.size()) {
      ans.push_back(root->val);
    }
    rightSideView(root->right, dep + 1, ans);
    rightSideView(root->left, dep + 1, ans);
  }
};
```


