---
title: Leetcode 94. Binary Tree Inorder Traversal
date: 2018-11-21 06:09:31
updated: 2018-11-21 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

![](/images/in-post/2018-11-22-Leetcode-94-Binary-Tree-Inorder-Traversal/2018-11-22-14-27-48.png)

**Difficulty**:Medium
**Category**:Tree, Stack, Hash Table

<!-- more -->

------------

# Analyze

![](/images/in-post/2018-11-22-Leetcode-144-Binary-Tree-Preorder-Traversal/2018-11-22-19-57-03.png)

图片来自于：[二叉树经典面试题解析一：用非递归实现二叉树的前序遍历，中序遍历，后序遍历](https://blog.csdn.net/sofia_m/article/details/78975165)

和前序非递归遍历方法一样，只是改变了遍历的次序问题, 输出的位置变化了一下就好了。下面的代码也来自于上面的博客：

```cpp
//中序非递归
void _InOrderNR(pNode _pRoot) {
  pNode pCur = _pRoot;
  stack<pNode> s;
  while (pCur || !s.empty()) {
    //将左侧节点依次压栈
    while (pCur) {
      s.push(pCur);
      pCur = pCur->_pLeft;
    }
    //栈中节点的左子树已经遍历完
    //栈中节点自身和右子树还没有遍历
    //开始依次访问栈顶节点的右子树，通过循环将该右子树的左侧节点依次压栈
    pNode pTop = s.top();
    cout << pTop->_data << "  ";
    s.pop();
    pCur = pTop->_pRight;  //循环的子问题
  }
}
```

------------

# Solution

## Solution 1: 使用递归的方式完成

对左子结点调用递归函数，根节点访问值，右子节点再调用递归函数.

```cpp
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inorder(root, ans);
    return ans;
  }
 private:
  void inorder(TreeNode* root, vector<int>& ans) {
    if (!root) return;
    inorder(root->left, ans);
    ans.emplace_back(root->val);
    inorder(root->right, ans);
  }
};
```

## Solution 2: 非递归的实现方式(使用堆栈)

从根节点开始，先将根节点压入栈，然后再将其所有左子结点压入栈，然后取出栈顶节点，保存节点值，再将当前指针移到其右子节点上，若存在右子节点，则在下次循环时又可将其所有左子结点压入栈中。这样就保证了访问顺序为左-根-右.

```cpp
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> sta;
    TreeNode* p = root;
    while (p || !sta.empty()) {
      if (p) {
        sta.push(p);
        p = p->left;
      } else {  // p == nullptr && !stack.isEmpty()
        p = sta.top();
        sta.pop();
        res.emplace_back(p->val);
        p = p->right;
      }
    }
    return res;
  }
};
```

## Solution 3: 非递归(不使用堆栈) -- Morris Traversal, O(1)空间复杂度

> A binary tree is threaded by making all right child pointers that would normally be null point to the inorder successor of the node (if it exists), and all left child pointers that would normally be null point to the inorder predecessor of the node.

参考博客:[Morris Traversal方法遍历二叉树（非递归，不用栈，O(1)空间）](http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html)

1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
   1. 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
   2. 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
3. 重复以上1、2直到当前节点为空。

```cpp
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;
    TreeNode *cur = root, *pre;
    while (cur) {
      if (!cur->left) {
        ans.emplace_back(cur->val);
        cur = cur->right;
      } else {
        pre = cur->left;
        while (pre->right && pre->right != cur) pre = pre->right;
        if (!pre->right) {
          pre->right = cur;
          cur = cur->left;
        } else {
          pre->right = nullptr;
          ans.emplace_back(cur->val);
          cur = cur->right;
        }
      }
    }
    return ans;
  }
};
```
