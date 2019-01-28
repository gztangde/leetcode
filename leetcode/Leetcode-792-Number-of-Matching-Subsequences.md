
# Question

Given string  `S`  and a dictionary of words  `words`, find the number of  `words[i]`  that is a subsequence of  `S`.

**Example :**
**Input:** 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
**Output:** 3
**Explanation:** There are three words in `words` that are a subsequence of `S`: "a", "acd", "ace".

**Note:**

- All words in  `words`  and  `S`  will only consists of lowercase letters.
- The length of  `S`  will be in the range of  `[1, 50000]`.
- The length of  `words`  will be in the range of `[1, 5000]`.
- The length of  `words[i]`  will be in the range of  `[1, 50]`.

**Difficulty**:Medium
**Category**:String, HashTable


------------

# Analyze

给你一些单词和一个字符串,判断哪些单词是这个字符串的子序列.

![](/images/in-post/2019-01-21-Leetcode-792-Number-of-Matching-Subsequences/2019-01-21-17-32-31.png)

![](/images/in-post/2019-01-21-Leetcode-792-Number-of-Matching-Subsequences/2019-01-21-17-32-40.png)


------------

# Solution

## Solution 1: Brute Force

```cpp
class Solution {
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    int ans = 0;
    unordered_map<string, bool> m;
    for (const string& word : words) {
      auto it = m.find(word);
      if (it == m.end()) {
        // Not found;
        bool match = isMatch(word, S);
        m[word] = match;
        ans += m[word];
      } else {
        ans += it->second;
      }
    }
    return ans;
  }

 private:
  bool isMatch(const string& word, string& s) {
    int left = 0;
    for (const char c : word) {
      bool found = false;
      for (int i = left; i < s.length(); ++i) {
        if (s[i] == c) {
          found = true;
          left = i + 1;
          break;
        }
      }
      if (!found) return false;
    }
    return true;
  }
};
```


