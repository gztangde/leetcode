---
title: Leetcode 559. Maximum Depth of N ary Tree
date: 2019-01-12 17:53:46
updated: 2019-01-12 17:53:46
categories: 
- [Leetcode]
- [Leetcode, ]
tags: Leetcode
notshow: true
top:
---

# Question

Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example, given a  `3-ary`  tree:

![](/images/in-post/2019-01-12-Leetcode-559-Maximum-Depth-of-N-ary-Tree/2019-01-12-17-54-38.png)

**Difficulty**:Easy
**Category**:Tree, Depth-First-Search, Breadth-First-Search

<!-- more -->

------------

# Analyze

So we use the template code for this `Tree Question`.

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-15-13-28.png)

There are four steps for this template:
1. Boundary conditions.
2. Deal with the root value.
3. recursive call funciton
4. compare ouput value

------------

# Solution

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
 public:
  int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    if (root->children.empty()) return 1;
    int len = root->children.size(), max_dep = 0;
    for (int i = 0; i < len; ++i) {
      int d = maxDepth(root->children[i]);
      max_dep = max(max_dep, d);
    }
    return max_dep + 1;
  }
};
```

<!-- 
------------

# Leetcode Question Summary


------------ -->
