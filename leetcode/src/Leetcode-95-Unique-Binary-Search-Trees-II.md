---
title: Leetcode 95. Unique Binary Search Trees II
date: 2019-01-25 12:31:08
updated: 2019-01-25 12:31:08
categories: 
- [Leetcode]
- [Leetcode, Dynamic-Programming]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given an integer  _n_, generate all structurally unique  **BST's**  (binary search trees) that store values 1 ... _n_.

**Example:**

```
**Input:** 3
**Output:**
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]

```

**Explanation:**
The above output corresponds to the 5 unique BST's shown below:

```
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

```

**Difficulty**:Medium

**Category**:Dynamic-Programming, Tree

<!-- more -->

# Solution

```cpp
class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTrees(1, n);
  }

 private:
  vector<TreeNode*> generateTrees(int start, int end) {
    vector<TreeNode*> ans;
    if (start > end) {
      ans.emplace_back(nullptr);
      return ans;
    }
    for (int k = start; k <= end; ++k) {
      vector<TreeNode*> leftsub = generateTrees(start, k - 1);
      vector<TreeNode*> rightsub = generateTrees(k + 1, end);
      for (auto& m : leftsub) {
        for (auto& n : rightsub) {
          TreeNode* temp = new TreeNode(k);
          temp->left = m;
          temp->right = n;
          ans.emplace_back(temp);
        }
      }
    }
    return ans;
  }
};
```


