---
title: Leetcode 113. Path Sum II
date: 2019-01-12 20:16:55
updated: 2019-01-12 20:16:55
categories: 
- [Leetcode]
- [Leetcode, 1_Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

**Note:** A leaf is a node with no children.

**Example:**

Given the below binary tree and  `sum = 22`,

![](/images/in-post/2019-01-12-Leetcode-113-Path-Sum-II/2019-01-12-20-17-39.png)

**Difficulty**:Medium
**Category**:Tree, Depth-first Search

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
//Runtime: 8ms
class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    vector<int> cur;
    dfs(root, sum, cur, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int sum, vector<int>& cur, vector<vector<int>>& ans) {
    if (!root) return;
    if (!root->left && !root->right) {
      if (root->val == sum) {
        cur.push_back(root->val);
        ans.push_back(cur);
        cur.pop_back();
      }
      return;
    }
    cur.push_back(root->val);
    dfs(root->left, sum - root->val, cur, ans);
    dfs(root->right, sum - root->val, cur, ans);
    cur.pop_back();
  }
};
```


