---
title: Leetcode 190. Reverse Bits
date: 2019-02-07 23:38:15
updated: 2019-02-07 23:38:15
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Reverse bits of a given 32 bits unsigned integer.

**Example 1:**

**Input:** 00000010100101000001111010011100
**Output:** 00111001011110000010100101000000
**Explanation:** The input binary string **00000010100101000001111010011100** represents the unsigned integer 43261596, so return 964176192 which its binary representation is **00111001011110000010100101000000**.

**Example 2:**

**Input:** 11111111111111111111111111111101
**Output:** 10111111111111111111111111111111
**Explanation:** The input binary string **11111111111111111111111111111101** represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is **10101111110010110010011101101001**.

**Note:**

-   Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
-   In Java, the compiler represents the signed integers using  [2's complement notation](https://en.wikipedia.org/wiki/Two%27s_complement). Therefore, in  **Example 2** above the input represents the signed integer  `-3` and the output represents the signed integer  `-1073741825`.

**Follow up**:

If this function is called many times, how would you optimize it?

**Difficulty**:Easy

**Category**:Bit-Manipulation

<!-- more -->

# Analyze

# Solution

后来看了看发现根本不需要这么麻烦，直接进行位移运算，因为是要翻转过来，所以一边向右位移输入的数字，一边根据右移后原数字跟1的与操作结果来将结果数字左移，最后直接返回就完了，完全不需要转成二进制又转回来，都是一样的。

不过这里要注意右移时要使用无符号右移。

```cpp
class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
      ans += n & 1;
      n >>= 1;
      if (i < 31) ans <<= 1;
    }
    return ans;
  }
};
```