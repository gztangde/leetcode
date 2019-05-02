---
title: Leetcode 563. Binary Tree Tilt
date: 2019-01-13 19:37:05
updated: 2019-01-13 19:37:05
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree, return the tilt of the  **whole tree**.

The tilt of a  **tree node**  is defined as the  **absolute difference**  between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

The tilt of the  **whole tree**  is defined as the sum of all nodes' tilt.

![](/images/in-post/2019-01-13-Leetcode-563-Binary-Tree-Tilt/2019-01-13-19-38-07.png)

**Note:**

1.  The sum of node values in any subtree won't exceed the range of 32-bit integer.
2.  All the tilt values won't exceed the range of 32-bit integer.

**Difficulty**:Easy

**Category**:Tree

<!-- more -->

# Analyze

# Solution

```cpp
// Runtime: 12ms
class Solution {
 public:
  int findTilt(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
  }

 private:
  int dfs(TreeNode* root, int& ans) {
    if (!root) return 0;
    int l = dfs(root->left, ans);
    int r = dfs(root->right, ans);
    ans += abs(l - r);
    return l + r + root->val;
  }
};
```


