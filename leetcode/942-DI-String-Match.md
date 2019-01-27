
# Question

Given a string  `S`  that  **only**  contains "I" (increase) or "D" (decrease), let  `N = S.length`.

Return  **any**  permutation  `A`  of  `[0, 1, ..., N]`  such that for all  `i = 0, ..., N-1`:

- If  `S[i] == "I"`, then  `A[i] < A[i+1]`
- If  `S[i] == "D"`, then  `A[i] > A[i+1]`

**Example 1:**

> **Input:** "IDID"
> **Output:** [0,4,1,3,2]

**Example 2:**

> **Input:** "III"
> **Output:** [0,1,2,3]

**Example 3:**

> **Input:** "DDI"
> **Output:** [3,2,0,1]

**Difficulty**:Easy
**Category**:Math


------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  vector<int> diStringMatch(string S) {
    const int n = S.length();
    vector<int> ans(n + 1, INT_MIN);
    int h = n, l = 0;
    for (int i = 0; i < n; i++) S[i] == 'I' ? ans[i] = l++ : ans[i] = h--;
    ans[n] = h;
    return ans;
  }
};
```

适当进行一些优化：

```cpp
class Solution {
 public:
  vector<int> diStringMatch(string S) {
    const int n = S.length();
    vector<int> ans;
    ans.reserve(n+1);
    int h = n, l = 0;
    for (int i = 0; i < n; i++) S[i] == 'I' ? ans.emplace_back(l++) : ans.emplace_back(h--);
    ans.emplace_back(h);
    return ans;
  }
};
```
