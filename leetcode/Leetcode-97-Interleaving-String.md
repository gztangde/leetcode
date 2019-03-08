---
title: Leetcode 97. Interleaving String
date: 2018-12-22 09:09:31
updated: 2018-12-22 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given  _s1_,  _s2_,  _s3_, find whether  _s3_  is formed by the interleaving of  _s1_  and  _s2_.

**Example 1:**

> **Input:** s1 = "aabcc", s2 = "dbbca", _s3_ = "aadbbcbcac"
> **Output:** true

**Example 2:**

> **Input:** s1 = "aabcc", s2 = "dbbca", _s3_ = "aadbbbaccc"
> **Output:** false

**Difficulty**:Hard

**Category**:String, Dynamic-Programming

<!-- more -->

# Analyze

这一道题目先判断前提条件是否符合： `字符串s1和字符串s2的长度之和必须等于字符串s3的长度。`， 并且如果s1和s2是空值的时候，直接返回`true`。这道题目使用动态规划来求解。

设状态`f[i][j]` 表示`s1[0,i]`和`s2[0,j]`能够组合匹配`s3[0,i+j]`。

- 如果s1的最后一个字符=s3的最后一个字符，那么`f[i][j] = f[i-1][j]`
- 如果s2的最后一个字符=s3的最后一个字符，那么`f[i][j] = f[i][j-1]`

这就可以得到**状态变化公式**为：

```cpp
f[i][j] = (s1[i - 1] == s3 [i + j - 1] && f[i - 1][j]) || (s2[j - 1] == s3 [i + j - 1] && f[i][j - 1]);
```

几个主要部分：

- 初始化状态记录的二维数组， 使用`s1.length（）+1`的长度初始化行数，使用`s2.length()+1`的长度初始化每行的数据个数

`vector<vector<bool>> f(s1.length() + 1, vector<bool>(s2.length() + 1, true));`

- 对二维数组`f`进行边界初始化：`f[0][j]`和`f[i][0]`, 在这里对`f[i][0]`初始化的时候只需要判断上一个状态`f[i-1][0]`的状态和`s1[i-1] == s3[i-1]`就可以了。 对`f[0][j]`初始化的时候只需要判断上一个状态`f[0][j-1]`和`s2[j-1] == s3[j-1]`即可。(继续判断下一个元素是否相等的必要条件是上一个的状态是true)。(注明：这里对`f[0][0]`直接使用初始的`True`即可)

```cpp
for (unsigned int i = 1; i <= s1.length(); ++i) {
  f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
}

for (unsigned int i = 1; i <= s2.length(); ++i) {
  f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];
}
```

# Solution

```cpp
// f[i][j] = (s1[i - 1] == s3 [i + j - 1] && f[i - 1][j]) || (s2[j - 1] == s3 [i + j - 1] && f[i][j - 1]);
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s3.length() != s1.length() + s2.length()) return false;

    vector<vector<bool>> f(s1.length() + 1, vector<bool>(s2.length() + 1, true));
    for (unsigned int i = 1; i <= s1.length(); ++i) {
      f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
    }

    for (unsigned int i = 1; i <= s2.length(); ++i) {
      f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];
    }

    for (unsigned int i = 1; i <= s1.length(); ++i) {
      for (unsigned int j = 1; j <= s2.length(); ++j) {
        f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);
      }
    }
    return f[s1.length()][s2.length()];
  }
};
```
