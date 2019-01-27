
# Question

Given two words  _word1_  and  _word2_, find the minimum number of operations required to convert  _word1_  to  _word2_.

You have the following 3 operations permitted on a word:

1. Insert a character
2. Delete a character
3. Replace a character

**Example 1:**

> **Input:** word1 = "horse", word2 = "ros"
> **Output:** 3
> **Explanation:** 
> horse -> rorse (replace 'h' with 'r')
> rorse -> rose (remove 'r')
> rose -> ros (remove 'e')

**Example 2:**

> **Input:** word1 = "intention", word2 = "execution"
> **Output:** 5
> **Explanation:** 
> intention -> inention (remove 't')
> inention -> enention (replace 'i' with 'e')
> enention -> exention (replace 'n' with 'x')
> exention -> exection (replace 'n' with 'c')
> exection -> execution (insert 'u')

**Difficulty**:Hard
**Category**:String, Dynamic-Programming


------------

# Analyze

在这道题目中，使用动态规划的方式来求解。设状态`f[i][j]`表示`A[0,i]`和`B[0,j]`之间的最小编辑距离，假设两个`string`分别为`word1`和`word2`.

1. 如果`word1[i-1] == word2[j-1]`, 则`f[i][j] = f[i-1][j-1]`, 这就是表示`A[0, i]和B[0,j]`之间的编辑距离为`f[i][j]`.
2. 如果`word1[i-1] != word2[j-1]`, 则
   1. 如果`word1[i-1]`替换为`word2[j-1]`，那么`f[i][j] = f[i-1][j-1] + 1`
   2. 如果`word1[i-1]`后添加`word2[j-1]`，那么`f[i][j] = f[i][j-1] + 1`
   3. 如果`word1[i-1]`删除，那么`f[i][j] = f[i-1][j] + 1`

![](/images/in-post/2018-12-23-Leetcode-72-Edit-Distance/2018-12-23-23-13-17.png)

------------

# Solution

```cpp
class Solution {
 public:
  int minDistance(string word1, string word2) {
    const size_t m = word1.length();
    const size_t n = word2.length();
    int f[m + 1][n + 1];
    for (size_t i = 0; i <= m; ++i) {
      f[i][0] = i;
    }

    for (size_t j = 0; j <= n; ++j) {
      f[0][j] = j;
    }

    for (size_t i = 1; i <= m; ++i) {
      for (size_t j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          f[i][j] = f[i - 1][j - 1];
        } else {
          f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
        }
      }
    }
    return f[m][n];
  }
};
```

------------

# Leetcode Question Summary


------------
