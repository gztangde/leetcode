---
title: Leetcode 1012. Complement of Base 10 Integer
date: 2019-03-17 01:04:18
updated: 2019-03-17 01:04:18
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Leetcode 1012. Complement of Base 10 Integer

Every non-negative integer  `N` has a binary representation. For example, `5`  can be represented as  `"101"` in binary,  `11`  as  `"1011"` in binary, and so on. Note that except for  `N = 0`, there are no leading zeroes in any binary representation.

The  _complement_ of a binary representation is the number in binary you get when changing every  `1`  to a  `0`  and  `0`  to a  `1`. For example, the complement of  `"101"`  in binary is  `"010"`  in binary.

For a given number  `N`  in base-10, return the complement of it's binary representation as a base-10 integer.

**Example 1:**

**Input:** 5
**Output:** 2
**Explanation:** 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.

**Example 2:**

**Input:** 7
**Output:** 0
**Explanation:** 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10. 

**Example 3:**

**Input:** 10
**Output:** 5
**Explanation:** 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.

**Note:**

1.  `0 <= N < 10^9`

**Difficulty**:Easy

**Category**:

# Analyze


# Solution

```cpp
class Solution {
 public:
  int bitwiseComplement(int N) {
    if (N == 0) return 1;
    s_ = "";
    string num = toBinary(N);
    int right = num.size() - 1;
    int cnt = 1, ans = 0;
  
    for (; right >= 0; --right) {
      if (num[right] == '0') {
        ans += cnt;
      }
      cnt *= 2;
    }
    return ans;
  }

 private:
  string s_;
  string toBinary(int n) {
    s_ = (n % 2 == 0 ? '0' : '1') + s_;
    if (n / 2 != 0) {
      toBinary(n / 2);
    }
    return s_;
  }
};
```