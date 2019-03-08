---
title: Leetcode 988. Smallest String Starting From Leaf
date: 2019-02-03 00:57:46
updated: 2019-02-03 00:57:46
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given the  `root`  of a binary tree, each node has a value from  `0`  to  `25`representing the letters  `'a'`  to  `'z'`: a value of  `0`  represents  `'a'`, a value of  `1`  represents  `'b'`, and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

_(As a reminder, any shorter prefix of a string is lexicographically smaller: for example,  `"ab"`  is lexicographically smaller than  `"aba"`. A leaf of a node is a node that has no children.)_

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/01/30/tree1.png)**

**Input:** [0,1,2,3,4,3,4]
**Output:** "dba"

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/01/30/tree2.png)**

**Input:** [25,1,3,1,3,0,2]
**Output:** "adz"

**Example 3:**

**![](https://assets.leetcode.com/uploads/2019/02/01/tree3.png)**

**Input:** [2,2,1,null,1,0,null,0]
**Output:** "abc"

**Note:**

1.  The number of nodes in the given tree will be between  `1`  and  `1000`.
2.  Each node in the tree will have a value between  `0`  and  `25`.

**Difficulty**:Medium

**Category**:

<!-- more -->

------------

# Analyze

# Solution

```cpp
class Solution {
 public:
  string smallestFromLeaf(TreeNode* root) {
    if (!root) return "";
    if (!root->left && !root->right) {
      char temp = root->val + 'a';
      return string(1, temp);
    }
    string l = smallestFromLeaf(root->left);
    string r = smallestFromLeaf(root->right);
    char temp = root->val + 'a';
    if (l == "") return r + temp;
    if (r == "") return l + temp;
    return min(l + temp, r + temp);
  }
};
```