---
title: Leetcode 958. Check Completeness of a Binary Tree
date: 2019-02-14 01:06:45
updated: 2019-02-14 01:06:45
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a binary tree, determine if it is a  _complete binary tree_.

**Definition of a complete binary tree from  [Wikipedia](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees):**  
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h  nodes inclusive at the last level h.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-1.png)**

**Input:** [1,2,3,4,5,6]
**Output:** true
**Explanation:** Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

**Example 2:**

**![](https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-2.png)**

**Input:** [1,2,3,4,5,null,7]
**Output:** false
**Explanation:** The node with value 7 isn't as far left as possible.  

**Note:**

1.  The tree will have between 1 and 100 nodes.

**Difficulty**:Medium

**Category**:

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  bool isCompleteTree(TreeNode *root) {
    vector<vector<TreeNode *>> ans;
    int count = 0;
    traverse(root, 1, ans);
    if (ans.size() < 2) return true;
    for (int i = 0; i < ans.size() - 1; ++i) {
      // cout << pow(2,i) << endl;
      if (ans[i].size() != pow(2, i)) return false;
    }

    vector<TreeNode *> prev = ans[ans.size() - 2];
    int n = prev.size();
    count = 0;
    for (int i = 0; i < n; ++i) {
      if (prev[i]->left)
        count++;
      else
        break;
      if (prev[i]->right)
        count++;
      else
        break;
    }
    if (count != ans.back().size()) return false;
    return true;
  }

 private:
  void traverse(TreeNode *root, int level, vector<vector<TreeNode *>> &res) {
    if (!root) return;

    if (level > res.size()) res.push_back(vector<TreeNode *>());
    res[level - 1].push_back(root);
    traverse(root->left, level + 1, res);
    traverse(root->right, level + 1, res);
  }
};
```