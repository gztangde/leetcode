
# Question

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys  **less than**  the node's key.
- The right subtree of a node contains only nodes with keys  **greater than**  the node's key.
- Both the left and right subtrees must also be binary search trees.

**Example 1:**

![](/images/in-post/2019-01-12-Leetcode-98-Validate-Binary-Search-Tree/2019-01-12-22-59-53.png)

**Difficulty**:Medium
**Category**:Tree, Depth-First-Search


------------

# Analyze

------------

# Solution

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Runtime: 8ms
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (!root) return true;
    long pre = LONG_MIN;
    return inorder(root, pre);
  }

 private:
  bool inorder(TreeNode* root, long& pre) {
    if (!root) return true;
    bool l = inorder(root->left, pre);
    if (root->val <= pre)
      return false;
    else
      pre = root->val;

    bool r = inorder(root->right, pre);
    return r & l;
  }
};
```

