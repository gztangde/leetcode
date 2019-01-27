
# Question

Given an integer  _n_, return the number of trailing zeroes in  _n_!.

**Example 1:**

> **Input:** 3
> **Output:** 0
> **Explanation:** 3! = 6, no trailing zero.

**Example 2:**

> **Input:** 5
> **Output:** 1
> **Explanation:** 5! = 120, one trailing zero.

**Difficulty**:Easy
**Category**:Math


------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  int trailingZeroes(int n) {
    if (n < 5)
      return 0;
    else
      return n / 5 + trailingZeroes(n / 5);
  }
};
```

