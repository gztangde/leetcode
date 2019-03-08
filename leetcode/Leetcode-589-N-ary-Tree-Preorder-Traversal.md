---
title: Leetcode 589. N ary Tree Preorder Traversal
date: 2019-01-24 23:13:11
updated: 2019-01-24 23:13:11
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given an n-ary tree, return the  _preorder_  traversal of its nodes' values.

For example, given a  `3-ary`  tree:

![](/images/in-post/2019-01-24-Leetcode-589-N-ary-Tree-Preorder-Traversal/2019-01-24-23-14-33.png)

**Difficulty**:Easy

**Category**:Tree

<!-- more -->

------------

# Analyze

# Solution

```cpp
class Solution {
 public:
  vector<int> preorder(Node* root) {
    if (!root) return {};
    ans.push_back(root->val);
    for (auto& c : root->children) preorder(c);
    return ans;
  }

 private:
  vector<int> ans;
};
```


