---
title: Leetcode 543. Diameter of Binary Tree
date: 2019-01-14 11:26:02
updated: 2019-01-14 11:26:02
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Leetcode 543. Diameter of Binary Tree

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the  **longest**  path between any two nodes in a tree. This path may or may not pass through the root.

**Example:**  
Given a binary tree  

```
          1
         / \
        2   3
       / \     
      4   5    

```

Return  **3**, which is the length of the path [4,2,1,3] or [5,2,1,3].

**Note:**  The length of path between two nodes is represented by the number of edges between them.

**Difficulty**:Easy

**Category**:Tree

<!-- more -->

------------

# Solution

Time complexity: O(n)
Space complexity: O(n)

> Runtime: 16 ms, faster than 99.52% of C++ online submissions for Diameter of Binary Tree.
> Memory Usage: 20.5 MB, less than 43.81% of C++ online submissions for Diameter of Binary Tree.

```cpp
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int max_len = 0;
    dfs(root, max_len);
    return max_len;
  }

 private:
  int dfs(TreeNode* root, int& max_len) {
    if (!root) return 0;

    int left = dfs(root->left, max_len);
    int right = dfs(root->right, max_len);

    // Count the edge [left -> root] and [right -> root]
    max_len = max(max_len, left + right);
    return max(right, left) + 1;
  }
};
```