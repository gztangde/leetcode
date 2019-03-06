---
title: Leetcode 426. Convert Binary Search Tree to Sorted Doubly Linked List
date: 2019-03-06 13:52:46
updated: 2019-03-06 13:52:46
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Leetcode 426. Convert Binary Search Tree to Sorted Doubly Linked List

题目大意：输入是一个二叉搜索树，将其转化为双向链表输出

Convert a BST to a sorted circular doubly-linked list `in-place`. Think of the left and right pointers as synonymous to the previous and next pointers in a doubly-linked list.

Let's take the following BST as an example, it may help you understand the problem better:

![](https://leetcode.com/static/images/problemset/BSTDLLOriginalBST.png)

We want to transform this BST into `a circular doubly linked list`. Each node in a doubly linked list `has a predecessor and successor`. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

The figure below shows the circular doubly linked list for the BST above. The "head" symbol means the node it points to is the smallest element of the linked list.

![](https://leetcode.com/static/images/problemset/BSTDLLReturnDLL.png)

Specifically, we want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. We should return the pointer to the first element of the linked list.

The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.

![](https://leetcode.com/static/images/problemset/BSTDLLReturnBST.png)

**Difficulty**:Medium

**Category**:

# Analyze

Cite: [Convert Binary Search Tree to Sorted Doubly Linked List 将二叉搜索树转为有序双向链表](https://www.cnblogs.com/grandyang/p/9615871.html)

转化成双向链表后，每个结点都有`left`和`right`指针指向左右两个结点，不管其原来是否是叶结点还是根结点，转换后统统没有区别。

其次，我们发现这是个循环双向链表，即首尾结点是相连的，原先的二叉搜索树中的最左结点和最右结点，现在也互相连接起来了。最后，我们发现返回的结点不再是原二叉搜索树的根结点root了，而是最左结点，即最小值结点。

跟二叉搜索树有关的题，肯定要利用其性质，即`左<根<右`，即左子结点值小于根结点值小于右子结点值。而且十有八九都得用中序遍历来解，因为中序遍历的顺序就是左根右啊，跟性质吻合。我们观察原二叉搜索树中结点4连接着结点2和结点5，而在双向链表中，`连接的是结点3和结点5，这就是为啥我们要用中序遍历了，因为只有中序遍历，结点3之后才会遍历到结点4，这时候我们可以将结点3和结点4串起来`。决定了用中序遍历之后，就要考虑是迭代还是递归的写法，博主建议写递归的，一般写起来都比较简洁，而且递归是解树类问题的神器啊，十有八九都是用递归，一定要熟练掌握。再写中序遍历之前，其实还有难点，因为我们需要把相邻的结点连接起来，所以`我们需要知道上一个遍历到的结点是什么，所以用一个变量pre，来记录上一个遍历到的结点。还需要一个变量head，来记录最左结点`，这样的话，在递归函数中，先判空，之后对左子结点调用递归，这样会先一直递归到最左结点，此时如果head为空的话，说明当前就是最左结点，赋值给head和pre，对于之后的遍历到的结点，那么可以和pre相互连接上，然后pre赋值为当前结点node，再对右子结点调用递归即可

# Solution

## Solution 1: Recursive

```cpp
class Solution {
 public:
  Node* treeToDoublyList(Node* root) {
    if (!root) return NULL;
    Node *head = NULL, *pre = NULL;
    inorder(root, pre, head);
    pre->right = head;
    head->left = pre;
    return head;
  }
  void inorder(Node* node, Node*& pre, Node*& head) {
    if (!node) return;
    inorder(node->left, pre, head);
    if (!head) {
      head = node;
      pre = node;
    } else {
      pre->right = node;
      node->left = pre;
      pre = node;
    }
    inorder(node->right, pre, head);
  }
};
```

## Solution 2: Iteration

```cpp
class Solution {
 public:
  Node* treeToDoublyList(Node* root) {
    if (!root) return NULL;
    Node *head = NULL, *pre = NULL;
    stack<Node*> st;
    while (root || !st.empty()) {
      while (root) {
        st.push(root);
        root = root->left;
      }
      root = st.top();
      st.pop();
      if (!head) head = root;
      if (pre) {
        pre->right = root;
        root->left = pre;
      }
      pre = root;
      root = root->right;
    }
    head->left = pre;
    pre->right = head;
    return head;
  }
};
```

## Solution 3: Divide and Conquer

```cpp
class Solution {
 public:
  Node* treeToDoublyList(Node* root) {
    if (!root) return NULL;
    Node* leftHead = treeToDoublyList(root->left);
    Node* rightHead = treeToDoublyList(root->right);
    root->left = root;
    root->right = root;
    return connect(connect(leftHead, root), rightHead);
  }
  Node* connect(Node* node1, Node* node2) {
    if (!node1) return node2;
    if (!node2) return node1;
    Node *tail1 = node1->left, *tail2 = node2->left;
    tail1->right = node2;
    node2->left = tail1;
    tail2->right = node1;
    node1->left = tail2;
    return node1;
  }
};
```