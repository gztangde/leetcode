---
title: Leetcode 1013. Pairs of Songs With Total Durations Divisible by 60
date: 2019-03-17 01:05:43
updated: 2019-03-17 01:05:43
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Question

In a list of songs, the  `i`-th song has a duration of `time[i]`  seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by  `60`. Formally, we want the number of indices  `i < j`  with  `(time[i] + time[j]) % 60 == 0`.

**Example 1:**

**Input:** [30,20,150,100,40]
**Output:** 3
**Explanation:** Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60

**Example 2:**

**Input:** [60,60,60]
**Output:** 3
**Explanation:** All three pairs have a total duration of 120, which is divisible by 60.

**Note:**

1.  `1 <= time.length <= 60000`
2.  `1 <= time[i] <= 500`

**Difficulty**:Medium

**Category**:

# Analyze


# Solution

```cpp
class Solution {
public:
  int numPairsDivisibleBy60(vector<int>& time) {
    int ans = 0;
    vector<int> vec(61, 0);
    for (int t : time) {
      t %= 60;
      if (t == 0) ans += vec[0];
      else ans += vec[60-t];
      vec[t]++;
    }
    return ans;
  }
};
```