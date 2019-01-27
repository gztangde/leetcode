
# Question

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

![](/images/in-post/2018-11-26-Leetcode-101-Symmetrix-Tree/2018-11-26-18-20-59.png)

**Difficulty**:Easy
**Category**:Tree, Depth-First-Search, Breadth-First-Search


------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return isSymmetric(root->left, root->right);
  }

  bool isSymmetric(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;
    return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
  }
};
```