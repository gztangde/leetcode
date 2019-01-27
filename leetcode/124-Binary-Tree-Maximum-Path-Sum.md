
# Question

Given a  **non-empty**  binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain  **at least one node**  and does not need to go through the root.

![](/images/in-post/2019-01-12-Leetcode-124-Binary-Tree-Maximum-Path-Sum/2019-01-12-21-02-38.png)

**Difficulty**:Hard
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
class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    if (!root) return 0;
    int ans = INT_MIN;
    maxPathSum(root, ans);
    return ans;
  }

 private:
  int maxPathSum(TreeNode* root, int& ans) {
    if (!root) return 0;
    int l = max(0, maxPathSum(root->left, ans));
    int r = max(0, maxPathSum(root->right, ans));
    int sum = l + r + root->val;
    // Only use the ans to record, don't use it to return
    ans = max(sum, ans);
    return max(l, r) + root->val;
  }
};
```

