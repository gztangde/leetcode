---
title: Leetcode 109. Convert Sorted List to Binary Search Tree
date: 2019-01-25 14:07:02
updated: 2019-01-25 14:07:02
categories: 
- [Leetcode]
- [Leetcode, Tree]
- [Leetcode, Depth-First-Search]
- [Leetcode, Linked-List]
tags: Leetcode
notshow: true
top:
---

# Question

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of  _every_  node never differ by more than 1.

**Example:**

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

```
      0
     / \
   -3   9
   /   /
 -10  5

```

**Difficulty**:Medium

**Category**:Linked List, Depth-First-Search

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) { return sortedListToBst(head, getlength(head)); }

 private:
  TreeNode* sortedListToBst(ListNode* head, int len) {
    if (len == 0) return nullptr;
    if (len == 1) return new TreeNode(head->val);
    ListNode* mid = getnthnode(head, len / 2 + 1);
    ListNode* mid_r = getnthnode(head, len / 2 + 2);

    TreeNode* root = new TreeNode(mid->val);
    root->left = sortedListToBst(head, len / 2);
    root->right = sortedListToBst(mid_r, (len - 1) / 2);
    return root;
  }

  int getlength(ListNode* node) {
    int n = 0;
    while (node) {
      ++n;
      node = node->next;
    }
    return n;
  }

  ListNode* getnthnode(ListNode* node, int n) {
    while (--n) node = node->next;
    return node;
  }
};
```


