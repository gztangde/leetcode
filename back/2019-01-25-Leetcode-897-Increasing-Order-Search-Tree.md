---
title: Leetcode 897. Increasing Order Search Tree
date: 2019-01-25 14:25:28
updated: 2019-01-25 14:25:28
categories: 
- [Leetcode]
- [Leetcode, Tree]
- [Leetcode, Depth-First-Search]
tags: Leetcode
notshow: true
top:
---

# Question

Given a tree, rearrange the tree in  **in-order**  so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

**Example 1:**

```
**Input:** [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

**Output:** [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9
```

**Note:**

1. The number of nodes in the given tree will be between 1 and 100.
2. Each node will have a unique integer value from 0 to 1000.

**Difficulty**:Easy
**Category**:Tree, Depth-First-Search

<!-- more -->

------------

# Analyze

------------

# Solution

## Solution 1:使用递归: Time Limit Exceeded

```cpp cpp
class Solution {
 public:
  TreeNode* increasingBST(TreeNode* root) {
    if (!root) return root;
    vector<TreeNode*> ans;
    inorder(root, ans);
    std::cout << ans.size() << std::endl;
    TreeNode* p = root;
    p = ans[0];
    for (int i = 1; i < ans.size(); ++i) {
      p->right = ans[i];
      p = p->right;
    }

    return root;
  }
 private:
  void inorder(TreeNode* root, vector<TreeNode*>& ans) {
    if (!root) return;
    inorder(root->left, ans);
    ans.emplace_back(root);
    inorder(root->right, ans);
  }
};
```

## Solution 2

```cpp
class Solution {
 public:
  TreeNode* increasingBST(TreeNode* root) {
    return inorder(root, nullptr);
  }
 private:
  TreeNode* inorder(TreeNode* root, TreeNode* target) {
    if (!root) return target;
    TreeNode* ans = inorder(root->left, root);
    root->left =nullptr;
    root->right = inorder(root->right, target);
    return ans;
  }
};
```

## Solution 3

```cpp
class Solution {
 public:
  TreeNode* increasingBST(TreeNode* root) {
    TreeNode dump(0);
    prev_ = &dump;
    inorder(root);
    return dump.right;
  }
 private:
  TreeNode* prev_;
  void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    prev_->right = root;
    prev_ = root;
    prev_->left = nullptr;
    inorder(root->right);
  }
};
```

<!-- 
------------

# Leetcode Question Summary


------------ -->
