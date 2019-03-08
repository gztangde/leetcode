---
title: Leetcode 337. House Robber III
date: 2019-01-14 14:27:04
updated: 2019-01-14 14:27:04
categories: 
- [Leetcode]
- [Leetcode, ]
tags: Leetcode
notshow: true
top:
---

# Question

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

**Example 1:**
![](/images/in-post/2019-01-14-Leetcode-337-House-Robber-III/2019-01-14-14-27-51.png)

**Difficulty**:Medium

**Category**:Tree, Depth-First-Search

<!-- more -->

------------

# Analyze

# Solution

<!-- TODO: You need to find a better solution to do this question. -->

```cpp
// Runtime: 1276ms 7.41%
class Solution {
 public:
  int rob(TreeNode* root) {
    if (!root) return 0;
    int val = root->val;
    if (root->left) val += rob(root->left->left) + rob(root->left->right);
    if (root->right) val += rob(root->right->left) + rob(root->right->right);
    int val2 = rob(root->left) + rob(root->right);
    return max(val, val2);
  }
};
```


