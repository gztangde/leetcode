---
title: Leetcode Data Structure 1. Tree
date: 2019-01-12 13:10:08
updated: 2019-01-12 13:10:08
categories: 
- [Leetcode]
tags: Leetcode
notshow: true
top:
---

<!-- TOC -->

- [Summary](#summary)
- [Definition of a Binary Tree Node](#definition-of-a-binary-tree-node)
- [Binary Search Tree](#binary-search-tree)
- [Balanced Binary Tree](#balanced-binary-tree)
- [Tree Traversal](#tree-traversal)
- [How to Create a BST](#how-to-create-a-bst)
- [Key to solve the tree problem.](#key-to-solve-the-tree-problem)
- [Templates](#templates)
  - [Template 1: One root](#template-1-one-root)
  - [Template 2: Two root](#template-2-two-root)
- [Tree Problems](#tree-problems)
    - [1.Binary Tree Traversal](#1binary-tree-traversal)
    - [2.Build Binary Tree](#2build-binary-tree)
    - [3. Binary search Tree](#3-binary-search-tree)
    - [4. Recursion (Binary Tree)](#4-recursion-binary-tree)

<!-- /TOC -->

> All the pictures in this post are coming from the video: 
> [花花酱 LeetCode Binary Trees 二叉树 - 刷题找工作 SP12](https://www.youtube.com/watch?v=PbGl8_-bZxI&list=PLLuMmzMTgVK7ug02DDoQsf50OtwVDL1xd) 

# Summary

This page talk about the followed information:

- The definition of a Binary Tree Node
- Binary Search Tree
- Balanced Binary Tree
- Binary Tree Traversal
  - Pre-Order
  - **In-Order** (Important: It have been sorted)
  - Post-Order
- How to create a BST
- Key To Tree Problems: **Recursion**
- Templates:
  - Single root/Two rootse
  - Time Complexity: O(n) / Space Complexity: O(hight)

> For the Space Complexity, it may be equal to `n` if this tree only have the left node or right node.

<!-- more -->

------------

# Definition of a Binary Tree Node

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-13-30-04.png)

There are some tips for the definition of a Binary Tree Node:

- You need build your own destruction function for the `Struct TreeNode` because the `C++ new the Tree in the head`. So there may be memory leak. 
- This destruction function will delete all node in the tree by Recursion way. For example, when you delete the root node, it will run `delete left` firstly. After that, it will delete all the children node for the left node.

>　如果使用图的思想来看待这一个树的结构的话，那这就是一个有向，无环的图形．
> 树可以有很多个子节点, 但是二叉树最多只能有一个左孩子和一个右孩子.

The tree have the structure in logic like the above, but how the tree saved in the memory. Is it also like a tree graph? Of course, it isn't. The structure of the tree in the memory like the followed graph.

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-13-45-43.png)

In the memory, the tree's data are unordered. `There is a point in the stack to find the root of the tree in the memory.` So, if you want use a tree to sort the data, it is not effective because the tree's data is not continuous in the memory.

**How to do the Binary Tree Traversal**

If you want to do the preorder for the tree, the function will use the `point` for the root node which is saved in the stack to find the left node firstly and push the left node information in the stack. After that, deal with the right side. Like the above graph shows. When they finish one part, then pop the node in the stack.

> If you lose the root point in the stack, then no one can deal with the tree's data in the memory. This is a memory leak for c++;

------

# Binary Search Tree

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-14-01-21.png)

We want use a Binary Search Tree to do some element search work, so **we hope the Binary Search tree is also a balanced tree**. Because it may work faster than the tree like the first picture even though it is also a Binary search tree.

**Time Complexity**
- O(h)
- worst case: O(h) = O(n)
- Best case: O(h) = O(log(n))

---------

# Balanced Binary Tree

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-14-08-26.png)

**The height of left / right substrees are at most 1**

So, not all Balanced Binary Tree can be used for the BST. We often want find a perfect BST in the balanced Tree to do some search work. ( O(h) = O(log n) )

---------

# Tree Traversal

After we get a `Good BST`, we can use this tree to do the tree traversal.

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-14-13-06.png)

The `preorder, inorder, postorder` are the recursion function. There is just one different feature for these three method.
It is **when the function to handle the root node in the tree**.

In this part, when you change the function `print`, you can deal with the `root node` as the order of the output array.

> For a BST tree, the inorder function can give a sorted array as the output data. 

**We often use the inorder tree with the BST tree because the BST have this feature to get a sorted array data after the inorder function.**

For the first line, all of them is the code to deal with the boundary for the recursion function. This is a feature for the recursion function. 

--------

# How to Create a BST

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-14-23-20.png)

In this funciton, the recursion function is the `insert` function. In this function, there are a few works we need to do: 

- Deal with the boundary. If the `root == null`, it build a now node and add this node for it's father left node or right node. 
- To make the decision whether we need to go through the left way or right way.
- After finish this part, return the root node. 

> This part is talking about how to create an unbalanced BST. However, most times, we hope we can build a balanced BST to do the search work. (Deal with their height.)

-------------

# Key to solve the tree problem.

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-15-01-20.png)

> There is a different way to solve the tree problem, you need to think about it as the recursive way.

When you solve the tree problem, you need to think about how to use the left subtree output and the right-subtree output to build the output for question. (How you can use the recursive function return value to solve the problem.) Use the recursive way to think about this question.

------------

# Templates

## Template 1: One root

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-15-13-28.png)

There are four steps for this template:
1. Boundary conditions.
2. Deal with the root value.
3. recursive call funciton
4. compare ouput value

There are some problems like the followed.

**The Depth of Binary Tree (Leetcode 104)**

```cpp
public int maxDepth(TreeNode root) {
    if (root == null) return 0;
    return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
}
```

**Balanced Binary Tree(Leetcode 110)**

```java  java
private boolean result = true;

public boolean isBalanced(TreeNode root) {
  maxDepth(root);
  return result;
}

public int maxDepth(TreeNode root) {
  if (root == null) return 0;
  int l = maxDepth(root.left);
  int r = maxDepth(root.right);
  if (Math.abs(l - r) > 1) result = false;
  return 1 + Math.max(l, r);
}
```

**The Diameter of Binary Tree(Leetcode 543)**



## Template 2: Two root

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-15-20-16.png)

There are four steps for this template:
1. Boundary conditions.
2. Deal with the root value, it may fit with some conditions.
3. recursive call funciton
4. compare ouput value

-----------

# Tree Problems

### 1.Binary Tree Traversal

树的遍历有两种: 深度优先遍历和宽度优先遍历。 深度优先遍历又可以分为两种：先根遍历和后根遍历。 

- 树的先根遍历是：先访问树的根节点，然后依次先根遍历根的各个子树。树的先根遍历的结果与对应二叉树的先序遍历的结果是相同的。
- 数的后根遍历是： 先依次后根遍历树根的各个子树，然后访问根结点。树的后根遍历的结果与对应二叉树的后根遍历的结果是相同的。

在深度遍历里面有下面几种情况：

- 前序遍历：根结点 ---> 左子树 ---> 右子树
- 中序遍历：左子树---> 根结点 ---> 右子树
- 后序遍历：左子树 ---> 右子树 ---> 根结点

使用下图作为一个例子：

![](/images/in-post/2018-11-22-Leetcode-144-Binary-Tree-Preorder-Traversal/2018-11-22-18-49-53.png)

- 前序遍历: A->B->C->D->E->F->G->H->I->J->K->M->L
- 中序遍历: C->B->E->D->F->A->H->G->J->I->M->K->L
- 后序遍历: C->E->F->D->B->H->J->M->L->K->I->G->A

有以下这些问题:

- [Preorder](../Leetcode-144-Binary-Tree-Preorder-Traversal/), [Inorder](../Leetcode-94-Binary-Tree-Inorder-Traversal/), [Postorder](../Leetcode-145-Binary-Tree-Postorder-Travesal/), [N-arr Tree Preorder](../Leetcode-589-N-ary-Tree-Preorder-Traversal/), [N-arr Tree Postorder](../Leetcode-590-N-ary-Tree-Postorder-Traversal/)
方案: 递归或使用堆栈的非递归实现, 而多个子节点的实现,只需要将其装换为循环递归调用即可.

- [Level Order](../Leetcode-102-Binary-Tree-Level-Order-Traversal/), [Level Order II](../Leetcode-107-Binary-Tree-Level-Order-Traversal-II/), [Zigzag Level Order](../Leetcode-103-Binary-Tree-Zigzag-Level-Order-Traversal/), Vertical Order, [N-arr Tree Level Order](../Leetcode-429-N-ary-Tree-Level-Order-Traversal/)
- [Recover Binary Search Tree](../Leetcode-99-Recover-Binary-Search-Tree/)
- [Same Tree](../Leetcode-100-Same-Tree/)
- [Symmetric Tree](../Leetcode-101-Symmetrix-Tree/)
- [Balanced Binary Tree](../Leetcode-110-Balanced-Binary-tree/)
- [Flatten Binary Tree to Linked list](../Leetcode-114-Flatten-Binary-Tree-To-Linked-List/)
- [Population Next Right Pointers in Each Node II](../Leetcode-117-Populating-Next-Right-Pointers-In-Each-Node-II/)

### 2.Build Binary Tree

- [From Preorder and Inorder Traversal](../Leetcode-105-Construct-Binary-Tree-From-Preorder-and-Inorder-Traversal/)
- [From Inorder and Postorder Traversal](../Leetcode-106-Construct-Binary-Tree-From-Inorder-And-Postorder-Traversal/)

### 3. Binary search Tree

- [Unique Binary Search Trees](../Leetcode-96-Unique-Binary-Search-Trees/)
- [Unique Binary Search Trees II](../Leetcode-95-Unique-Binary-Search-Trees-II/)
- [Validate Binary Search Tree](../Leetcode-98-Validate-Binary-Search-Tree/)
- [Covert Sorted Array to Binary Search Tree]((../Leetcode-108-Convert-Sorted-Array-To-Binary-Search-Tree/))
- [Convert Sorted List to Binary Search Tree](../Convert-Sorted-List-to-Binary-Search-Tree/)

### 4. Recursion (Binary Tree)

- [Minimum Depth](../Leetcode-111-Minimum-Depth-of-Binary-Tree/), [Maximum Depth](../Leetcode-104-Maximum-Depth-of-Binary-Tree/)
- [Path Sum](../Leetcode-112-Path-Sum/), [Path Sum II](../Leetcode-113-Path-Sum-II/), [Maximum Path Sum](../Leetcode-124-Binary-Tree-Maximum-Path-Sum/), [Path Sum III](../Leetcode-437-Path-Sum-III/)
- [Populating Next Right Pointers in Each Node](../Leetcode-116-Populating-Next-Right-Pointers-In-Each-Node/)
- [Sum Root to Leaf Numbers](../Leetcode-129-Sum-Root-to-Leaf-Numbers/)