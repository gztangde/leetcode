
# Question

Given two strings **s1** and **s2**, write a function to return true if **s2** contains the permutation of **s1**. In other words, one of the first string's permutations is the **substring** of the second string.

**Example 1:** 
> **Input:**s1 = "ab" s2 = "eidbaooo"
> **Output:**True
> **Explanation:** s2 contains one permutation of s1 ("ba").

**Example 2:**

> **Input:** s1= "ab" s2 = "eidboaoo"
> **Output:** False

**Note:**

1. The input strings only contain lower case letters.
2. The length of both given strings is in range [1, 10,000].



# Solution

```cpp
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<int> vec1(127), vec2(127);
    for (int i = 0; i < n1; ++i) {
      vec1[s1[i]]++;
      vec2[s2[i]]++;
    }

    if (vec1 == vec2) return true;
    for (int i = n1; i < n2; ++i) {
      --vec2[s2[i - n1]];
      ++vec2[s2[i]];
      if (vec1 == vec2) return true;
    }
    return false;
  }
};
```