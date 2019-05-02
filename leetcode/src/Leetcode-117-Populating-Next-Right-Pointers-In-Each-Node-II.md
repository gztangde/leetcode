---
title: Leetcode 117. Populating Next Right Pointers in Each Node II
date: 2018-11-26 19:09:31
updated: 2018-11-26 19:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree

```cpp
struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to  `NULL`.

Initially, all next pointers are set to  `NULL`.

**Note:**

- You may only use constant extra space.
- Recursive approach is fine, implicit stack space does not count as extra space for this problem.

**Example:**

Given the following binary tree,
![](/images/in-post/2018-11-26-Leetcode-117-Populating-Next-Right-Pointers-In-Each-Node-II/2018-11-26-18-52-35.png)

**Difficulty**:Medium

**Category**:Tree, Depth-First-Search

<!-- more -->

# Analyze

# Solution

```cpp
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    while (root) {
      TreeLinkNode *next = nullptr, *prev = nullptr;
      // Loop in the same level
      for (; root; root = root->next) {
        // The first one --> to find the next level
        if (!next) next = root->left ? root->left : root->right;

        if (root->left) {
          if (prev) prev->next = root->left;
          prev = root->left;
        }

        if (root->right) {
          if (prev) prev->next = root->right;
          prev = root->right;
        }
      }
      root = next;  // Next Level
    }
  }
};
```
