---
title: Leetcode 129. Sum Root to Leaf Numbers
date: 2019-01-12 21:21:18
updated: 2019-01-12 21:21:18
categories: 
- [Leetcode]
- [Leetcode,Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree containing digits from  `0-9`  only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path  `1->2->3`  which represents the number  `123`.

Find the total sum of all root-to-leaf numbers.

**Note:** A leaf is a node with no children.

![](/images/in-post/2019-01-12-Leetcode-129-Sum-Root-to-Leaf-Numbers/2019-01-12-21-22-20.png)

**Difficulty**:Medium

**Category**:Tree, Depth-First-Search

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
class Solution {
 public:
  int sumNumbers(TreeNode* root) {
    if (!root) return 0;
    int ans = 0;
    return sumNumbers(root, ans);
  }

 private:
  int sumNumbers(TreeNode* root, int ans) {
    if (!root) return 0;
    ans = ans * 10 + root->val;
    if (!root->left && !root->right) {
      return ans;
    }

    int l = sumNumbers(root->left, ans);
    int r = sumNumbers(root->right, ans);

    // If this is not the last one,
    // return l + r;
    return l + r;
  }
};
```


