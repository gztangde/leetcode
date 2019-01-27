
# Question

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


------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty() || (s.length() > 1 && s[0] == '0')) return 0;

    vector<int> f(s.length() + 1, 0);
    f[0] = 1;
    for (size_t i = 1; i <= s.length(); ++i) {
      f[i] = s[i - 1] == '0' ? 0 : f[i - 1];
      if (i >= 2 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
        f[i] += f[i - 2];
      }
    }
    return f[s.length()];
  }
};
```
