---
title: Leetcode 621. Task Scheduler
date: 2019-01-25 16:43:00
updated: 2019-01-25 16:43:00
categories: 
- [Leetcode]
- [Leetcode, Array]
- [Leetcode, Greedy]
- [Leetcode, Queue]
tags: Leetcode
notshow: true
top:
---

# Question

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval  **n**  that means between two  **same tasks**, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the  **least**  number of intervals the CPU will take to finish all the given tasks.

**Example:**

```
**Input:** tasks = ["A","A","A","B","B","B"], n = 2
**Output:** 8
**Explanation:** A -> B -> idle -> A -> B -> idle -> A -> B.
```

**Note:**

1. The number of tasks is in the range [1, 10000].
2. The integer n is in the range [0, 100].

**Difficulty**:Medium
**Category**:Array, Greedy, Queue

<!-- more -->

------------

# Analyze

------------

# Solution

<!-- TODO: You need to know why they need to add the other number of max_count -->
```cpp cpp
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> count(26, 0);
    for (const char& t : tasks) ++count[t - 'A'];
    const int max_count = *max_element(count.begin(), count.end());
    size_t ans = (max_count - 1) * (n + 1);
    ans += count_if(count.begin(), count.end(), [max_count](int x) { return x == max_count; });

    return max(tasks.size(), ans);
  }
};
```

<!-- 
------------

# Leetcode Question Summary


------------ -->
