---
title: Leetcode 96. Unique Binary Search Trees
date: 2018-11-27 09:09:31
updated: 2018-11-27 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
mathjax: true
top:
---

# Question
Given  _n_, how many structurally unique  **BST's**  (binary search trees) that store values 1 ... _n_?

**Example:**

```
**Input:** 3
**Output:** 5
**Explanation:** Given _n_ = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

**Difficulty**:Medium

**Category**:Tree, DP

<!-- more -->

------------

# Analyze

修改一下上图中展示的顺序:

![](/images/in-post/2018-11-27-Leetcode-96-Unique-Binary-Search-Trees/2019-01-25-11-16-57.png)

- 以1为根的数的个数,等于左子树的个数 * 右子树的个数. 左子树是0个元素的树木(记作1),右子树是两个元素的树.

当数组为 1,2,3,4,5, ... n的时候,基于下面的规则构建的BST树木具有唯一性质: 以 i 为根结点的树, 其左子树由[1, i-1] 构成, 其右子树由 [i+1, n]构成. 定义f[i]为以[1,i]能够产生的`Unique Binary Search Tree`的数目. 
- 如果数组为空,那么只有一种BST, 空树, f(0) = 1;
- 如果数组只有一个元素,那么只有一种BST, 它自己, f(1) = 1;
- 两个元素: f(2) = f(0)*f(1) + f(1) * f(0);
- 三个元素: f(3) = f(0) * f(2) + f(1) * f(1) + f(2) * f(0);
- $f(i) = \sum_{k-1}^i f(k-1) * f(i-k)$

# Solution

```cpp
class Solution {
 public:
  int numTrees(int n) {
    // Defint f[i] is the number for the BST in [1, i]
    // f[0] = 1, f[1] = 1, f[2] = 2;
    // f[2] = f[0] * f[1]
    // f[3] = f[0] * f[2] + f[1] * f[1] + f[2]* f[1]
    // f[i] = f[0] * f[i-1] + ... + f[i-1] * f[0]
    vector<int> f(n + 1, 0);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int k = 1; k <= i; ++k) {
        f[i] += f[k - 1] * f[i - k];
      }
    }
    return f[n];
  }
};
```