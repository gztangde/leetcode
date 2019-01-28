---
title: Leetcode 515. Find Largest Value in Each Tree Row
date: 2019-01-25 13:24:44
updated: 2019-01-25 13:24:44
categories: 
- [Leetcode]
- [Leetcode, Tree]
- [Leetcode, Depth-First-Search]
- [Leetcode, Breadth-First-Search]
tags: Leetcode
notshow: true
top:
---

# Question

You need to find the largest value in each row of a binary tree.

**Example:**  

```
**Input:** 

          1
         / \
        3   2
       / \   \  
      5   3   9 

**Output:** [1, 3, 9]
```

**Difficulty**:Medium

**Category**:Tree, Depth-First-Search, Breadth-First-Search

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  vector<int> largestValues(TreeNode* root) {
    vector<int> ans;
    traverse(root, 1, ans);
    return ans;
  }

 private:
  void traverse(TreeNode const* root, int level, vector<int>& res) {
    if (!root) return;
    if (level > res.size()) res.push_back(INT_MIN);
    if (root->val > res[level - 1]) res[level - 1] = root->val;
    traverse(root->left, level + 1, res);
    traverse(root->right, level + 1, res);
  }
};
```


