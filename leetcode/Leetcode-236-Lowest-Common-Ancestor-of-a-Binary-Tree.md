---
title: Leetcode 236. Lowest Common Ancestor of a Binary Tree
date: 2019-01-13 01:34:23
updated: 2019-01-13 01:34:23
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

题目大意： 求二叉树的最小共同父节点的题

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the  [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow  **a node to be a descendant of itself**).”

Given the following binary tree: root = [3,5,1,6,2,0,8,null,null,7,4]

![](/images/in-post/2019-01-13-Leetcode-236-Lowest-Common-Ancestor-of-a-Binary-Tree/2019-01-13-01-34-55.png)

**Example 1:**

> **Input:** root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
> **Output:** 3
> **Explanation:** The LCA of nodes `5` and `1` is `3.`

**Example 2:**

> **Input:** root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
> **Output:** 5
> **Explanation:** The LCA of nodes `5` and `4` is `5`, since a node can be a descendant of itself according to the LCA definition.

**Note:**

- All of the nodes' values will be unique.
- p and q are different and both values will exist in the binary tree.

**Difficulty**:Medium

**Category**:Tree

# Solution

使用递归来求解，在递归函数中，我们首先看当前结点是否为空，若为空则直接返回空，若为p或q中的任意一个，也直接返回当前结点。否则的话就对其左右子结点分别调用递归函数，由于这道题限制了p和q一定都在二叉树中存在，那么如果当前结点不等于p或q，p和q要么分别位于左右子树中，要么同时位于左子树，或者同时位于右子树，那么我们分别来讨论：

* 若 **p 和 q 要么分别位于左右子树**中，那么对左右子结点调用递归函数，会分别返回p和q结点的位置，而当前结点正好就是p和q的最小共同父结点，直接返回当前结点即可，这就是题目中的例子1的情况。
* 若 **p 和 q 同时位于左子树**，这里有两种情况，一种情况是left会返回p和q中较高的那个位置，而right会返回空，所以我们最终返回非空的left即可，这就是题目中的例子2的情况。还有一种情况是会返回p和q的最小父结点，就是说当前结点的左子树中的某个结点才是p和q的最小父结点，会被返回。
* 若 **p 和 q 同时位于右子树**，同样这里有两种情况，一种情况是right会返回p和q中较高的那个位置，而left会返回空，所以我们最终返回非空的right即可，还有一种情况是会返回p和q的最小父结点，就是说当前结点的右子树中的某个结点才是p和q的最小父结点，会被返回，写法很简洁

Time complexity: O(n)
Space complexity: O(n)

```cpp
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if (l && r) return root;
    return l ? l : r;
  }
};
```