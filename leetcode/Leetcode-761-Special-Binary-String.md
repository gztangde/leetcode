---
title: Leetcode 761. Special Binary String
date: 2019-02-04 13:10:03
updated: 2019-02-04 13:10:03
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

_Special_  binary strings are binary strings with the following two properties:

- The number of 0's is equal to the number of 1's.
- Every prefix of the binary string has at least as many 1's as 0's.

Given a special string  `S`, a  _move_  consists of choosing two consecutive, non-empty, special substrings of  `S`, and swapping them.  _(Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.)_

At the end of any number of moves, what is the lexicographically largest resulting string possible?

**Example 1:**  

**Input:** S = "11011000"
**Output:** "11100100"
**Explanation:**
The strings "10" [occuring at S[1]] and "1100" [at S[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.

**Note:**

1. `S`  has length at most  `50`.
2. `S`  is guaranteed to be a  _special_  binary string as defined above.

**Difficulty**:Medium

**Category**:

<!-- more -->

# Analyze

输入,输出都是一个特色的二进制字符串, 需要满足要求为:

* 字符串中 `0` 和 `1` 的个数要相等
* 任何一个位置, 在前面的 `1` 的个素都要大于等于前面的 `0` 的个数.

这里要求我们能够通过交换字符串的方式, 生成字母顺序最大的特色字符串,.

# Solution

```cpp
class Solution {
 public:
  string makeLargestSpecial(string S) {
    int cnt = 0, i = 0;
    vector<string> v;
    string ans = "";
    for (int j = 0; j < S.size(); ++j) {
      cnt += (S[j] == '1') ? 1 : -1;
      if (cnt == 0) {
        v.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
        i = j + 1;
      }
    }
    sort(v.begin(), v.end(), greater<string>());
    for (int i = 0; i < v.size(); ++i) ans += v[i];
    return ans;
  }
};
```