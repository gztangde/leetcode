
# Question
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the  **longest**  path between any two nodes in a tree. This path may or may not pass through the root.

**Example:**  
Given a binary tree  

```
          1
         / \
        2   3
       / \     
      4   5    

```

Return  **3**, which is the length of the path [4,2,1,3] or [5,2,1,3].

**Note:**  The length of path between two nodes is represented by the number of edges between them.

**Difficulty**:Easy
**Category**:Tree


------------

# Analyze

------------

# Solution

```cpp
// Runtime: 8ms
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int max_len = 0;
    dfs(root, max_len);
    return max_len;
  }

 private:
  int dfs(TreeNode* root, int& max_len) {
    if (!root) return 0;
    int l = dfs(root->left, max_len);
    int r = dfs(root->right, max_len);
    max_len = max(max_len, l + r);
    return max(l, r) + 1;
  }
};
```

