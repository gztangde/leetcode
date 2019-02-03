---
title: Leetcode Build Binary Tree
date: 2019-01-23 00:20:49
updated: 2019-01-23 00:20:49
categories: 
- [Leetcode]
tags: Leetcode
notshow: true
top:
---

这种题目是构造一个二叉树, 题目给的输入是其他数据结构. 相关题目有以下几种情况:

* [Convert Sorted Array To Binary Search Tree](../Leetcode-108-Convert-Sorted-Array-To-Binary-Search-Tree/)
* [Convert Sorted List to Binary Search Tree](../Leetcode-109-Convert-Sorted-List-to-Binary-Search-Tree/)
* [Construct Binary Tree From Preorder and Inorder Traversal](../Leetcode-105-Construct-Binary-Tree-From-Preorder-and-Inorder-Traversal/)
* [Construct Binary Tree From Inorder And Postorder Traversal](../Leetcode-106-Construct-Binary-Tree-From-Inorder-And-Postorder-Traversal/)

# Introduce

**第一道题目:** [Convert Sorted Array To Binary Search Tree](../Leetcode-108-Convert-Sorted-Array-To-Binary-Search-Tree/)

数组是有序的, 我们每一次取中点作为根结点, 然后递归构建左右子树就好. 递归的写法:
* 要把根root先new出来
* 然后它的左节点接到递归左边部分的返回值，右节点接到递归右边部分的返回值
* 最后将root返回回去

**部分示例代码:**

```cpp
int mid = (start + end) / 2;
TreeNode* root = new TreeNode(nums[mid]);
root->left = sortedArrayToBST(nums, start, mid - 1);
root->right = sortedArrayToBST(nums, mid + 1, end);
return root;
```

**第二道题目:**[Convert Sorted List to Binary Search Tree](../Leetcode-109-Convert-Sorted-List-to-Binary-Search-Tree/)

这道题目是將有序的 `Array` 换成了 `List`, 但都是有序的, 这道题目和上一道 [Convert Sorted Array To BST](../Leetcode-108-Convert-Sorted-Array-To-Binary-Search-Tree/) 是一样的, 多出来的步骤是找到 `List的长度` 以及得到`nth`结点信息的过程. 

**部分示例代码:**

```cpp
TreeNode* sortedListToBst(ListNode* head, int len) {
  if (len == 0) return nullptr;
  if (len == 1) return new TreeNode(head->val);
  ListNode* mid = getnthnode(head, len / 2 + 1);
  ListNode* mid_r = getnthnode(head, len / 2 + 2);

  TreeNode* root = new TreeNode(mid->val);
  root->left = sortedListToBst(head, len / 2);
  root->right = sortedListToBst(mid_r, (len - 1) / 2);
  return root;
}
```

[Construct Binary Tree From Preorder and Inorder Traversal](../Leetcode-105-Construct-Binary-Tree-From-Preorder-and-Inorder-Traversal/)和题目[Construct Binary Tree From Inorder And Postorder Traversal](../Leetcode-106-Construct-Binary-Tree-From-Inorder-And-Postorder-Traversal/) 是比较一样的.

如果给定了`先序`和`中序`，并且里面的元素不重复，可以得到这样几个条件：
* 先序的第一个元素一定是跟
* 可以更加先序里面的根节点到中序里面找到对应的节点，因为没有重复元素
* 根据中序里面找到的根节点可以将其分为左右两个部分，分别对左右两个部分递归调用原函数

如果题目给定了`后序`和`中序`，并且里面的元素不重复，可以得到这样几个条件：

- 后序的最后一个元素一定是跟节点
- 可以在后序里面的根节点到中序里面找到对应的节点，因为没有重复元素
- 根据中序里面找到的根节点可以将其分为左右两个部分，分别对左右两个部分递归调用原函数
