
# Question

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

**Example 1:**
> **Input:** "abab"
> **Output:** True
> **Explanation:** It's the substring "ab" twice.

**Example 2:**
> **Input:** "aba"
> **Output:** False

**Example 3:**
> **Input:** "abcabcabcabc"
> **Output:** True
> **Explanation:** It's the substring "abc" four times. (And the substring "abcabc" twice.)



# Solution

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      int len = s.size();
      for(int i = 0; i < len/2; ++i) {
        if(len % (i+1) == 0) {
          int count = len / (i+1);
          string res = "";
          for(int j = 0; j < count; ++j) {
            res += s.substr(0, i+1);
          }
          if(res == s) return true;
        }
      }
      return false;
    }
};
```