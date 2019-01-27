
# Question

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

![](/images/in-post/2018-11-26-Leetcode-100-Same-Tree/2018-11-26-00-40-18.png)

**Difficulty**:Easy
**Category**:Tree, Depth-first-Search


------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  }
};
```