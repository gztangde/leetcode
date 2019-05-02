---
title: Leetcode 506. Relative Ranks
date: 2019-01-21 16:06:34
updated: 2019-01-21 16:06:34
categories: 
- [Leetcode]
- [Leetcode, Binary-Search]
tags: Leetcode
notshow: true
top:
---

# Question

Given scores of  **N**  athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

**Example 1:**  

> **Input:** [5, 4, 3, 2, 1]
> **Output:** ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
> **Explanation:** The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".   
> For the left two athletes, you just need to output their relative ranks according to their scores.

**Note:**  

1.  N is a positive integer and won't exceed 10,000.
2.  All the scores of athletes are guaranteed to be unique.

**Difficulty**:Easy

**Category**:Binary-Search

<!-- more -->

# Analyze

在这道题目中,给出了你一些人的分数,输入他们的排名, 前面三名使用`Gold, Medal, Silver Medal, Bronze Medal`替代,后面的输出排名的数字号码就好了.

# Solution

```cpp
class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    vector<string> ans;
    vector<int> s(nums);
    sort(s.begin(), s.end());
    vector<string> medals{"Gold", "Silver", "Bronze"};
    for (int i = 0; i < nums.size(); ++i) {
      int rank = s.end() - std::lower_bound(s.begin(), s.end(), nums[i]);
      if (rank <= 3) {
        ans.push_back(medals[rank - 1] + " Medal");
      } else
        ans.push_back(std::to_string(rank));
    }
    return ans;
  }
};
```
