
# Question

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

**Example 1:**

> **Input:** "Hello"
> **Output:** "hello"

**Example 2:**

> **Input:** "here"
> **Output:** "here"

**Example 3:**

> **Input:** "LOVELY"
> **Output:** "lovely"



# Solution

```cpp
class Solution {
public:
    string toLowerCase(string str) {
      int len = str.size();
      for (int i = 0; i < len; ++i) {
        if (str[i] >=65 && str[i] <= 90) {
          str[i] += 32;
        }
      }
      return str;
    }
};
```