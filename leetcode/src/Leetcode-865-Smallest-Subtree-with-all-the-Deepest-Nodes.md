---
title: Leetcode 865. Smallest Subtree with all the Deepest Nodes
date: 2019-03-06 16:27:51
updated: 2019-03-06 16:27:51
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Leetcode 865. Smallest Subtree with all the Deepest Nodes

题目：一棵二叉树有它的最大深度，找出包含了树中所有深度最大的结点的最深的子树。

Given a binary tree rooted at  `root`, the  _depth_  of each node is the shortest distance to the root.

A node is  _deepest_  if it **has the largest depth possible among any node in the entire tree.**

The subtree of a node is that node, plus the set of all descendants of that node.

**Return the node with the largest depth such that it contains all the deepest nodes in its subtree**.

**Example 1:**

**Input:** [3,5,1,6,2,0,8,null,null,7,4]
**Output:** [2,7,4]
**Explanation:**
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/01/sketch1.png)

We return the node with value 2, colored in yellow in the diagram.
The nodes colored in blue are the deepest nodes of the tree.
The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
Both the input and output have TreeNode type.

**Note:**

- The number of nodes in the tree will be between 1 and 500.
- The values of each node are unique.

**Difficulty**:Medium

**Category**:

# Analyze

这个题的模型其实比较左右子树的高度，`如果左右子树的高度相等，说明当前节点就是要求的`。这个解释是这样的：必须包含所有的最大高度的叶子，左右叶子高度相等，所以必须包含当前节点。

当左子树高度>右子树高度的时候，要求的节点在左边；反之，在右边。

所以，递归思路 + 一个pair。这个pair的思路是，保存了当前节点的深度和当前节点的最深子树节点。

Cite: [LeetCode 865. Smallest Subtree with all the Deepest Nodes](https://zxi.mytechroad.com/blog/tree/leetcode-865-smallest-subtree-with-all-the-deepest-nodes/)

![](/images/2019-03-06-17-01-35.png)

# Solution

## Solution 1: Recursion

Time complexity: O(n)
Space complexity: O(n)

> Runtime: 12 ms, faster than 74.90% of C++ online submissions for Smallest Subtree with all the Deepest Nodes.
> Memory Usage: 15.3 MB, less than 44.90% of C++ online submissions for Smallest Subtree with all the Deepest Nodes.

<!-- TODO：看明白这个题目需要求解的地方 -->

```cpp
class Solution {
 public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) { 
    return depth(root).second;
  }

 private:
  pair<int, TreeNode*> depth(TreeNode* root) {
    if (root == nullptr) return {-1, nullptr};
    auto left = depth(root->left);
    auto right = depth(root->right);
    int dl = left.first;
    int dr = right.first;
    return {max(dl, dr) + 1, dl == dr ? root : (dl > dr) ? left.second : right.second};
  }
};
```