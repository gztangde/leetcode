
# Question


Given a list of non negative integers, arrange them such that they form the largest number.

**Example 1:**

> **Input:** `[10,2]`
> **Output:** "`210"`

**Example 2:**

> **Input:** `[3,30,34,5,9]`
> **Output:** "`9534330"`

**Difficulty**:Medium
**Category**:


------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    string res = "";
    sort(nums.begin(), nums.end(),
         [](int x, int y) { return to_string(x) + to_string(y) > to_string(y) + to_string(x); });

    for (auto num : nums) res += to_string(num);

    // Deal with the situation with res == "00000"
    return res[0] == '0' ? "0" : res;
  }
};
```