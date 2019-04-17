class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    levelorder(root, 0, res);
    return res;
  }
  void levelorder(TreeNode* node, int level, vector<vector<int>>& res) {
    if (!node) return;
    if (res.size() == level) res.push_back({});
    res[level].push_back(node->val);
    if (node->left) levelorder(node->left, level + 1, res);
    if (node->right) levelorder(node->right, level + 1, res);
  }
};