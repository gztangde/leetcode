---
title: Leetcode 91. Decode Ways
date: 2018-12-23 09:09:31
updated: 2018-12-23 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Leetcode 91. Decode Ways

A message containing letters from  `A-Z`  is being encoded to numbers using the following mapping:

> 'A' -> 1
> 'B' -> 2
> ...
> 'Z' -> 26

Given a  **non-empty**  string containing only digits, determine the total number of ways to decode it.

**Example 1:**

> **Input:** "12"
> **Output:** 2
> **Explanation:** It could be decoded as "AB" (1 2) or "L" (12).

**Example 2:**

> **Input:** "226"
> **Output:** 3
> **Explanation:** It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

**Difficulty**:Medium

**Category**:String, Dynamic-Programming

<!-- more -->

# Solution

## Solution 1: DP

建立一位dp数组，长度比输入数组长多多2，全部初始化为1，因为斐波那契数列的前两项也为1，然后从第三个数开始更新，对应数组的第一个数。对每个数组首先判断其是否为0，若是将改为dp赋0，若不是，赋上一个dp值，此时相当如加上了dp[i - 1], 然后看数组前一位是否存在，如果存在且满足前一位不是0，且和当前为一起组成的两位数不大于26，则当前dp值加上dp[i - 2], 至此可以看出来跟斐波那契数组的递推式一样.

Use f[n] = how many ways for the 0 to n:

* If s[n] != 0, f[n] = f[n-1] + f[n-2]; (s[n-1] and s[n] have the number 10 - 26)
* If s[n] == 0, f[n] = f[n-2]

Time complexity: O(n)
Space complexity: O(n)

```cpp
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty() || (s.length() > 1 && s[0] == '0')) return 0;

    // Set dp vector and the edge value
    vector<int> f(s.length() + 1, 0);
    f[0] = 1;
    for (size_t i = 1; i <= s.length(); ++i) {
      // If the elements is 0, then 
      f[i] = s[i - 1] == '0' ? 0 : f[i - 1];
      if (i >= 2 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
        f[i] += f[i - 2];
      }
    }
    return f[s.length()];
  }
};
```

来源于博客：[Decode Ways 解码方法](http://www.cnblogs.com/grandyang/p/4313384.html)

如果是 O (n) 的空间复杂度， 也可以使用下面的这种写法：

```cpp
class Solution {
 public:
  int numDecodings(string s) {
    if (s.length() == 0) return 0;
    return ways(s, 0, s.length() - 1);
  }

 private:
  int ways(const string& s, int l, int r) {
    if (m_ways.count(l)) return m_ways[l];
    if (s[l] == '0') return 0;
    if (l >= r) return 1;  // Single digit or empty.

    int w = ways(s, l + 1, r);
    const int prefix = (s[l] - '0') * 10 + (s[l + 1] - '0');

    if (prefix <= 26) w += ways(s, l + 2, r);

    m_ways[l] = w;
    return w;
  }

  // Use l as key.
  unordered_map<int, int> m_ways;
};
```

我们再来看一种空间复杂度为O(1)的解法，我们用两个变量c1, c2来分别表示 s[i-1] 和 s[i-2] 的解码方法，然后我们从 `i = 1` 开始遍历，也就是字符串的第二个字符，我们判断如果当前字符为'0'，说明当前字符不能单独拆分出来，只能和前一个字符一起，我们先将c1赋为0，然后我们看前面的字符，如果前面的字符是1或者2时，我们就可以更新c1 = c1 + c2，然后c2 = c1 - c2，其实c2赋值为之前的c1，如果不满足这些条件的话，那么c2 = c1

Time complexity: O(n)
Space complexity: O(1)

```cpp
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty() || s.front() == '0') return 0;
    int c1 = 1, c2 = 1;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == '0') c1 = 0;
      if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
        c1 = c1 + c2;
        c2 = c1 - c2;
      } else {
        c2 = c1;
      }
    }
    return c1;
  }
};
```

另外一种写法：

```cpp
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    if (s.length() == 1) return 1;

    const int n = s.length();
    int w1 = 1;
    int w2 = 1;
    for (int i = 1; i < n; ++i) {
      int w = 0;
      if (!isValid(s[i]) && !isValid(s[i - 1], s[i])) return 0;
      if (isValid(s[i])) w = w1;
      if (isValid(s[i - 1], s[i])) w += w2;
      w2 = w1;
      w1 = w;
    }
    return w1;
  }

 private:
  bool isValid(const char c) { return c != '0'; }
  bool isValid(const char c1, const char c2) {
    const int num = (c1 - '0') * 10 + (c2 - '0');
    return num >= 10 && num <= 26;
  }
};
```

## Solution 2: Brute Force

该解法来源于博客：[花花酱 LeetCode 91. Decode Ways](https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-91-decode-ways/)

Time complexity: O(n^2)
Space complexity: O(n^2)

```cpp
// Author: Huahua
// Runtime: 6 ms
class Solution {
 public:
  int numDecodings(string s) {
    if (s.length() == 0) return 0;
    m_ways[""] = 1;
    return ways(s);
  }

 private:
  int ways(const string& s) {
    if (m_ways.count(s)) return m_ways[s];
    if (s[0] == '0') return 0;
    if (s.length() == 1) return 1;

    int w = ways(s.substr(1));
    const int prefix = stoi(s.substr(0, 2));

    if (prefix <= 26) w += ways(s.substr(2));

    m_ways[s] = w;
    return w;
  }

  unordered_map<string, int> m_ways;
};
```