class Solution {
 public:
  bool isCousins(TreeNode* root, int x, int y) {
    if ((level(root, x, 1) == level(root, y, 1)) && !(isSibling(root, x, y))) return true;
    return false;
  }

 private:
  bool isSibling(TreeNode* root, int a, int b) {
    if (!root) return false;
    if (root->left && root->right) {
      if ((root->left->val == a && root->right->val == b) || (root->right->val == a && root->left->val == b)) {
        return true;
      }
    }
    return isSibling(root->left, a, b) || isSibling(root->right, a, b);
  }

  int level(TreeNode* root, int target, int lev) {
    if (!root) return 0;
    if (root->val == target) return lev;

    int l = level(root->left, target, lev + 1);
    if (l != 0) return l;
    return level(root->right, target, lev + 1);
  }
};