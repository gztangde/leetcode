---
title: Leetcode 501. Find Mode in Binary Search Tree
date: 2019-01-13 17:39:18
updated: 2019-01-13 17:39:18
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary search tree (BST) with duplicates, find all the  [mode(s)](https://en.wikipedia.org/wiki/Mode_(statistics))  (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys  **less than or equal to**  the node's key.
- The right subtree of a node contains only nodes with keys  **greater than or equal to**  the node's key.
- Both the left and right subtrees must also be binary search trees.

For example:  
Given BST  `[1,null,2,2]`,

![](/images/in-post/2019-01-13-Leetcode-501-Find-Mode-in-Binary-Search-Tree/2019-01-13-17-40-25.png)

return  `[2]`.

**Note:**  If a tree has more than one mode, you can return them in any order.

**Follow up:**  Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

**Difficulty**:Easy

**Category**:Tree

<!-- more -->

# Solution

```cpp
// Runtime: 16ms
class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    vector<int> ans;
    std::stack<TreeNode*> s;

    TreeNode* p = root;
    int preval = 0, count = 0, max_num = 0;
    while (p || !s.empty()) {
      if (p) {
        s.push(p);
        p = p->left;
      } else {
        TreeNode* t = s.top();
        s.pop();

        if (t->val == preval) count++;
        else {
          count = 1;
          preval = t->val;
        }

        if (count >= max_num) {
          if (count > max_num) ans.clear();
          ans.push_back(preval);
          max_num = count;
        } 

        p = t->right;
      }
    }
    return ans;
  }
};
```


