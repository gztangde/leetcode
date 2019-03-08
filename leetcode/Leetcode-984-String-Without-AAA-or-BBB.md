---
title: Leetcode 984. String Without AAA or BBB
date: 2019-02-05 10:45:50
updated: 2019-02-05 10:45:50
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given two integers  `A`  and  `B`, return  **any**  string  `S`  such that:

- `S`  has length  `A + B`  and contains exactly  `A`  `'a'`  letters, and exactly  `B`  `'b'`  letters;
- The substring `'aaa'` does not occur in  `S`;
- The substring  `'bbb'`  does not occur in  `S`.

**Example 1:**

**Input:** A = 1, B = 2
**Output:** "abb" **Explanation:** "abb", "bab" and "bba" are all correct answers.

**Example 2:**

**Input:** A = 4, B = 1
**Output:** "aabaa"

**Note:**

1. `0 <= A <= 100`
2. `0 <= B <= 100`
3. It is guaranteed such an  `S`  exists for the given  `A`  and  `B`.

**Difficulty**:Medium

**Category**:

<!-- more -->

------------

# Analyze

# Solution

来自于讨论区的一个解法: [Clean C++/python solution](https://leetcode.com/problems/string-without-aaa-or-bbb/discuss/226740/Clean-C%2B%2Bpython-solution)

```cpp
class Solution {
 public:
  string strWithout3a3b(int A, int B) {
    if (A == 0)
      return string(B, 'b');
    else if (B == 0)
      return string(A, 'a');
    else if (A == B)
      return "ab" + strWithout3a3b(A - 1, B - 1);
    else if (A > B)
      return "aab" + strWithout3a3b(A - 2, B - 1);
    else
      return strWithout3a3b(A - 1, B - 2) + "abb";
  }
};
```