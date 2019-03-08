---
title: Leetcode 99. Recover Binary Search Tree
date: 2019-01-24 23:41:24
updated: 2019-01-24 23:41:24
categories: 
- [Leetcode]
- [Leetcode, Tree]
- [Leetcode, Depth-First-Search]
tags: Leetcode
notshow: true
top:
---

# Question

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

**Example 1:**

```
Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
```

**Example 2:**

```
**Input:** [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

**Output:** [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3

```

**Follow up:**

- A solution using O(_n_) space is pretty straight forward.
- Could you devise a constant space solution?

**Difficulty**:Hard

**Category**:Tree, Depth-First-Search

<!-- more -->

------------

# Analyze

这道题目可以使用很多种方案来解决, 首先我们能够想到的就是使用`inorder`遍历,因为它可以得到一个每个节点位置的数值记录的数组和一个记录每个结点顺序的结点指针, 將包含数值的数组排序之后,重新赋值回去给记录指针的数组就可以了. (Solution 1)

# Solution

## Solution 1: 使用树的中序遍历

```cpp
// Time Complexity: O(n)
class Solution {
 public:
  void recoverTree(TreeNode* root) {
    vector<TreeNode*> list;
    vector<int> val;
    inorder(root, list, val);
    sort(val.begin(), val.end());
    for (int i = 0; i < val.size(); ++i) list[i]->val = val[i];
  }

 private:
  void inorder(TreeNode* root, vector<TreeNode*>& list, vector<int>& val) {
    if (!root) return;
    inorder(root->left, list, val);
    list.emplace_back(root);
    val.emplace_back(root->val);
    inorder(root->right, list, val);
  }
};
```

## Solution 3: --- Morris Traversal

```cpp
class Solution {
 public:
  void recoverTree(TreeNode* root) {
    TreeNode* first = nullptr, *second = nullptr, *parent = nullptr;
    TreeNode* cur = root, *pre = nullptr;
    while(cur){
      if (!cur->left) {
        if (parent && parent->val > cur->val) {
          if (!first) first = parent;
          second = cur;
        }
        parent = cur;
        cur = cur->right;
      } else {
        pre = cur->left;
        while(pre->right && pre->right != cur) pre = pre->right;
        if (!pre->right) {
          pre->right = cur;
          cur = cur->left;
        } else {
          pre->right = nullptr;
          if (parent->val > cur->val) {
            if (!first) first = parent;
            second = cur;
          }
          parent = cur;
          cur = cur->right;
        }
      }
    }
    if (first && second) swap(first->val, second->val);
  }
};
```