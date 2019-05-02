---
title: Leetcode 98. Validate Binary Search Tree
date: 2019-01-12 22:59:15
updated: 2019-01-12 22:59:15
categories: 
- [Leetcode]
- [Leetcode, 1_Tree]
- [Leetcode, 1_Tree, DFS]
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys  **less than**  the node's key.
- The right subtree of a node contains only nodes with keys  **greater than**  the node's key.
- Both the left and right subtrees must also be binary search trees.

**Example 1:**

![](/images/in-post/2019-01-12-Leetcode-98-Validate-Binary-Search-Tree/2019-01-12-22-59-53.png)

**Difficulty**:Medium

**Category**:Tree, Depth-First-Search

# Solution

Note: in order to cover the range of -2^31 ~ 2^31-1, we need to use long or nullable integer.

Time complexity: O(n)
Space complexity: O(n)

```cpp
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    long pre = LONG_MIN;
    return inorder(root, pre);
  }

 private:
  bool inorder(TreeNode* root, long& pre) {
    if (!root) return true;
    bool left = inorder(root->left, pre);
    // Deal with root->val
    if (root->val <= pre)
      return false;
    else
      pre = root->val;

    bool right = inorder(root->right, pre);
    return left && right;
  }
};
```

# Follow up

如果限制不能使用 `long` 的数据类型的话， 我们可以考虑使用 `TreeNode*`.

Traverse the tree and limit the range of each subtree and check whether root’s value is in the range.

Time complexity: O(n)
Space complexity: O(n)

```cpp
class Solution {
 public:
  bool isValidBST(TreeNode* root) { 
    return isValidBST(root, nullptr, nullptr);
  }

 private:
  bool isValidBST(TreeNode* root, int* min_val, int* max_val) {
    if (!root) return true;
    if ((min_val && root->val <= *min_val) || (max_val && root->val >= *max_val)) return false;

    return isValidBST(root->left, min_val, &root->val) && isValidBST(root->right, &root->val, max_val);
  }
};
```