---
title: Leetcode 145. Binary Tree Postorder Traversal
date: 2018-11-22 06:09:31
updated: 2018-11-22 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree, return the postorder traversal of its nodes' values.

![](/images/in-post/2018-11-22-Leetcode-145-Binary-Tree-Postorder-Travesal/2018-11-25-23-35-50.png)

**Difficulty**:Hard

**Category**:Tree, Hard

<!-- more -->

------------

# Analyze

非递归的实现按照下图中的方式进行实现：

![](/images/in-post/2018-11-22-Leetcode-145-Binary-Tree-Postorder-Travesal/2018-11-25-23-37-09.png)

图片来自于：[二叉树经典面试题解析一：用非递归实现二叉树的前序遍历，中序遍历，后序遍历](https://blog.csdn.net/sofia_m/article/details/78975165)

------------

# Solution

```cpp

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> res;
      stack<const TreeNode *> sta;

      const TreeNode *p = root, *q = nullptr;
      do {
        while (p != nullptr) {
          sta.push(p);
          p = p->left;
        }
        q = nullptr;
        while (!sta.empty()) {
          p = sta.top();
          sta.pop();
          if (p->right == q) {
            res.push_back(p->val);
            q = p;
          } else {
            sta.push(p);
            p = p->right;
            break;
          }
        }
      } while (!sta.empty());
      return res;
    }
};
```

## Solution 2: 非递归(不使用堆栈) -- Morris Traversal

参考博客:[Morris Traversal方法遍历二叉树（非递归，不用栈，O(1)空间）](http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html)


后续遍历稍显复杂，需要建立一个临时节点dump，令其左孩子是root。并且还需要一个子过程，就是倒序输出某两个节点之间路径上的各个节点。

**步骤：**

当前节点设置为临时节点dump。

1. 如果当前节点的左孩子为空，则将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

  a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

  b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。**倒序输出从当前节点的左孩子到该前驱节点这条路径上的所有节点。**当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。

```cpp
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    TreeNode dump(-1);
    dump.left = root;
    vector<int> ans;
    TreeNode *cur = &dump, *pre = nullptr;
    while (cur) {
      if (!cur->left) {
        cur = cur->right;
      } else {
        pre = cur->left;
        while (pre->right && pre->right != cur) pre = pre->right;
        if (!pre->right) {
          pre->right = cur;
          cur = cur->left;
        } else {
          savePostorder(cur->left, pre, ans);
          pre->right = nullptr;
          cur = cur->right;
        }
      }
    }
    return ans;
  }

 private:
  void reverse(TreeNode* from, TreeNode* to) {
    if (from == to) return;
    TreeNode *x = from, *y = from->right, *z = nullptr;
    while (true) {
      z = y->right;
      y->right = x;
      x = y;
      y = z;
      if (x == to) break;
    }
  }
  void savePostorder(TreeNode* from, TreeNode* to, vector<int>& ans) {
    reverse(from, to);
    TreeNode* p = to;
    while (true) {
      ans.emplace_back(p->val);
      if (p == from) break;
      p = p->right;
    }
    reverse(to, from);
  }
};
```