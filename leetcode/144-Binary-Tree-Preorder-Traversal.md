
# Question

Given a binary tree, return the preorder traversal of its nodes' values.

![](/images/in-post/2018-11-22-Leetcode-144-Binary-Tree-Preorder-Traversal/2018-11-22-13-54-20.png)

**Difficulty**:Medium
**Category**:Tree, Stack


------------

# Analyze

这一道题目考察的是二叉树的深度遍历里面的`前序遍历`，在深度遍历里面有下面几种情况：

- 前序遍历：根结点 ---> 左子树 ---> 右子树
- 中序遍历：左子树---> 根结点 ---> 右子树
- 后序遍历：左子树 ---> 右子树 ---> 根结点

使用下图作为一个例子：

![](/images/in-post/2018-11-22-Leetcode-144-Binary-Tree-Preorder-Traversal/2018-11-22-18-49-53.png)

- 前序遍历: A->B->C->D->E->F->G->H->I->J->K->M->L
- 中序遍历: C->B->E->D->F->A->H->G->J->I->M->K->L
- 后序遍历: C->E->F->D->B->H->J->M->L->K->I->G->A

方案一：虽然这道题不让使用递归的方式来实现，但是还是将递归的版本写出来。

```cpp
class Solution {
 public
  void preOrderTraverse1(TreeNode root) {
    if (root != null) {
      System.out.print(root.val + "  ");
      preOrderTraverse1(root.left);
      preOrderTraverse1(root.right);
    }
  }
}
```

方案二：非递归的实现方式，就需要使用到`栈`来进行辅助实现 （**Solution 2**）

![](/images/in-post/2018-11-22-Leetcode-144-Binary-Tree-Preorder-Traversal/2018-11-22-19-57-03.png)

图片来自于：[二叉树经典面试题解析一：用非递归实现二叉树的前序遍历，中序遍历，后序遍历](https://blog.csdn.net/sofia_m/article/details/78975165)


- 前序遍历：根结点 ---> 左子树 ---> 右子树

根据前序遍历的顺序，优先访问根结点，然后在访问左子树和右子树。所以，对于任意结点node，第一部分即直接访问之，之后在判断左子树是否为空，不为空时即重复上面的步骤，直到其为空。若为空，则需要访问右子树。注意，在访问过左孩子之后，需要反过来访问其右孩子，所以，需要栈这种数据结构的支持。对于任意一个结点node，具体步骤如下：

- 访问之，并把结点node入栈，当前结点置为左孩子；
- 判断结点node是否为空，若为空，则取出栈顶结点并出栈，将右孩子置为当前结点；否则重复a)步直到当前结点为空或者栈为空（可以发现栈中的结点就是为了访问右孩子才存储的）

------------

# Solution

**Solution 2**：非递归的实现方式，使用栈进行实现。

```cpp
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<const TreeNode*> sta;
    if (root != nullptr) sta.push(root);

    while (!sta.empty()) {
      const TreeNode* temp = sta.top();
      sta.pop();
      res.emplace_back(temp->val);
      if (temp->right != nullptr) sta.push(temp->right);
      if (temp->left != nullptr) sta.push(temp->left);
    }
    return res;
  }
};
```

**Solution 2**:非递归的另外一种实现方式。

```cpp
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<const TreeNode*> sta;
    const TreeNode* p = root;
    while (p != nullptr || !sta.empty()) {
      if (p != nullptr) {
        res.emplace_back(p->val);
        sta.push(p);
        p = p->left;
      } else {  // p == nullptr && !stack.isEmpty()
        const TreeNode* temp = sta.top();
        sta.pop();
        p = temp->right;
      }
    }
    return res;
  }
};
```

网上的另外一种实现的方式，其实和上面`Solution 2`的方式是一样的，只是使用的是`while`循环处理的`p != nullptr`。源代码来自：[二叉树经典面试题解析一：用非递归实现二叉树的前序遍历，中序遍历，后序遍历](https://blog.csdn.net/sofia_m/article/details/78975165)

```cpp
//前序非递归
void _PreOrderNR(pNode _pRoot) {
  pNode pCur = _pRoot;
  stack<pNode> s;
  while (pCur || !s.empty()) {
    //将左侧节点依次压栈
    while (pCur) {
      cout << pCur->_data << "  ";
      s.push(pCur);
      pCur = pCur->_pLeft;
    }
    //开始依次访问栈顶节点的右子树，通过循环将该右子树的左侧节点依次压栈
    pNode pTop = s.top();
    s.pop();
    pCur = pTop->_pRight;  //循环的子问题
  }
}
```

## Solution 3: 非递归(不使用堆栈) -- Morris Traversal, O(1)空间复杂度

参考博客:[Morris Traversal方法遍历二叉树（非递归，不用栈，O(1)空间）](http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html)

1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
  a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。**输出当前节点（在这里输出，这是与中序遍历唯一一点不同）。**当前节点更新为当前节点的左孩子。
  b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。当前节点更新为当前节点的右孩子。
3. 重复以上1、2直到当前节点为空。


```cpp
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
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
          ans.emplace_back(cur->val);
          cur = cur->left;
        } else {
          pre->right = nullptr;
          cur = cur->right;
        }
      }
    }
    return ans;
  }
};
```