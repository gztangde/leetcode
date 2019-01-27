
# Question

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

**Note:**  The length of path between two nodes is represented by the number of edges between them.

![](/images/in-post/2019-01-14-Leetcode-687-Longest-Univalue-Path/2019-01-14-14-04-36.png)

**Note:**  The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

**Difficulty**:Easy
**Category**:Tree, Recursion


------------

# Analyze

This problem: You need to find the longest path which each node have the same value in this tree.(The path can pass the root node.) **The output value not the node number. It is the side numbers.**

![](/images/in-post/2019-01-14-Leetcode-687-Longest-Univalue-Path/2019-01-14-14-09-28.png)

You can use the left len and right len and the root node together.

> Output 3 is `2`, not `3`.
 
------------

# Solution

```cpp
//Runtime: 60 ms
class Solution {
 public:
  int longestUnivaluePath(TreeNode* root) {
    int max_len = 0;
    dfs(root, max_len);
    return max_len;
  }

 private:
  int dfs(TreeNode* root, int& max_len) {
    if (!root) return 0;
    int l = dfs(root->left, max_len);
    int r = dfs(root->right, max_len);
    int l_len = 0, r_len = 0;
    // The l is the long for the root->left, So, it need to return l_len
    if (root->left && root->left->val == root->val) l_len = l + 1;
    if (root->right && root->right->val == root->val) r_len = r + 1;
    max_len = max(max_len, l_len + r_len);
    return max(l_len, r_len);
  }
};
```

