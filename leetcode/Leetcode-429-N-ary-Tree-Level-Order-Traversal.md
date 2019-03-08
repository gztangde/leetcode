---
title: Leetcode 429. N ary Tree Level Order Traversal
date: 2019-01-24 23:25:36
updated: 2019-01-24 23:25:36
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example, given a  `3-ary`  tree:

![](/images/in-post/2019-01-24-Leetcode-429-N-ary-Tree-Level-Order-Traversal/2019-01-24-23-26-01.png)

We should return its level order traversal:

```
[
     [1],
     [3,2,4],
     [5,6]
]
```
**Note:**

1.  The depth of the tree is at most  `1000`.
2.  The total number of nodes is at most  `5000`.

**Difficulty**:Easy

**Category**:Tree

<!-- more -->

# Analyze

# Solution

```cpp

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    travllevel(root, 1, ans);
    return ans;
  }
  void travllevel(Node* root, int level, vector<vector<int>>& ans) {
    if (!root) return;
    if (level > ans.size()) ans.emplace_back(vector<int>());
    ans[level - 1].emplace_back(root->val);
    for (auto& c : root->children) travllevel(c, level + 1, ans);
  }
};
```


