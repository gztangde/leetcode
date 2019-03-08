---
title: Leetcode 590. N ary Tree Postorder Traversal
date: 2019-01-24 23:20:41
updated: 2019-01-24 23:20:41
categories: 
- [Leetcode]
- [Leetcode, Easy]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given an n-ary tree, return the  _postorder_  traversal of its nodes' values.

For example, given a  `3-ary`  tree:

![](/images/in-post/2019-01-24-Leetcode-590-N-ary-Tree-Postorder-Traversal/2019-01-24-23-21-11.png)

**Difficulty**:Easy

**Category**:Tree

<!-- more -->

------------

# Analyze

# Solution

```cpp
class Solution {
 public:
  vector<int> postorder(Node* root) {
    if (!root) return {};
    for (auto& c : root->children) postorder(c);
    ans.emplace_back(root->val);
    return ans;
  }

 private:
  vector<int> ans;
};
```


