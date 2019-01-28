
# Question

You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

![](/images/in-post/2018-10-12-Leetcode-606-Construct-String-from-Binary-Tree/2018-10-14-02-17-11.png)



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
    string tree2str(TreeNode* t) {
      if (!t) return "";
      string res = to_string(t->val);
      string left = tree2str(t->left), right = tree2str(t->right);
      if (left == "" && right == "") { return res;}
      if (left == "") {return res+"()"+"("+ right +")";}
      if (right == "") {return res+"(" + left + ")";}
      return res+"(" + left + ")" + "(" + right+")";
    }
};
```