---
title: Leetcode 108. Convert Sorted Array to Binary Search Tree
date: 2018-11-27 09:09:31
updated: 2018-11-27 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

![](/images/in-post/2018-11-27-Leetcode-108-Convert-Sorted-Array-To-Binary-Search-Tree/2018-11-27-16-06-04.png)

**Difficulty**:Easy

**Category**:Tree, Depth-first-Search

<!-- more -->

------------

# Analyze

# Solution

## Solution 1: Create any BST

**Runtime Error in this problem**

```cpp
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) { 
    return sortedArrayToBST(nums, 0, nums.size() - 1); 
  }

 private:
  TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);
    return root;
  }
};
```