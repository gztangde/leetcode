
# Question

**Difficulty**:Medium
**Category**:


------------

# Analyze

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

![](/images/in-post/leetcode/2018-11-26-00-23-11.png)

------------

# Solution

```cpp
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    traverse(root, 1, res);
    std::reverse(res.begin(), res.end());
    return res;
  }
  void traverse(TreeNode const *root, int level, vector<vector<int>> &res) {
    if (!root) return;

    if (level > res.size()) res.push_back(vector<int>());
    res[level - 1].push_back(root->val);
    traverse(root->left, level + 1, res);
    traverse(root->right, level + 1, res);
  }
};
```
