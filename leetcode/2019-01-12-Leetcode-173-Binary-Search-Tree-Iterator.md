---
title: Leetcode 173. Binary Search Tree Iterator
date: 2019-01-12 21:50:49
updated: 2019-01-12 21:50:49
categories: 
- [Leetcode]
- [Leetcode, Stack]
- [Leetcode, 1_Tree]
- [Leetcode, Design]
tags: Leetcode
notshow: true
top:
---

# Question

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling  `next()`  will return the next smallest number in the BST.

**Example:**

![](/images/in-post/2019-01-12-Leetcode-173-Binary-Search-Tree-Iterator/2019-01-12-21-51-24.png)

**Note:**

- `next()`  and  `hasNext()`  should run in average O(1) time and uses O(_h_) memory, where  _h_  is the height of the tree.
- You may assume that `next()` call will always be valid, that is, there will be at least a next smallest number in the BST when  `next()`  is called.

**Difficulty**:Medium
**Category**:Stack, Tree, Design

<!-- more -->

------------

# Analyze

------------

# Solution

Using stack solve this problem.

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
// Runtime: 48ms
class BSTIterator {
 public:
  BSTIterator(TreeNode* root) { inorder(root, s); }

  /** @return the next smallest number */
  int next() {
    int x = s.top();
    s.pop();
    return x;
  }

  void inorder(TreeNode* root, std::stack<int>& s) {
    if (!root) return;
    inorder(root->right, s);
    s.push(root->val);
    inorder(root->left, s);
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return s.size(); }

 private:
  std::stack<int> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```

<!-- 
------------

# Leetcode Question Summary


------------ -->
