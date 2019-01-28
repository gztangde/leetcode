
# Question

Given a binary tree, flatten it to a linked list in-place.

![](/images/in-post/2018-11-26-Leetcode-114-Flatten-Binary-Tree-To-Linked-List/2018-11-26-18-30-40.png)

**Difficulty**:Medium
**Category**:Tree, Depth-first-Search


------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  void flatten(TreeNode* root) {
    if (root == nullptr) return;

    flatten(root->left);
    flatten(root->right);

    if (root->left == nullptr) return;

    TreeNode* p = root->left;
    while (p->right) p = p->right;
    p->right = root->right;
    root->right = root->left;
    root->left = nullptr;
  }
};
```