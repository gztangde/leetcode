---
title: Leetcode 946. Validate Stack Sequences
date: 2019-02-01 20:41:14
updated: 2019-02-01 20:41:14
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given two sequences  `pushed`  and  `popped` **with distinct values**, return  `true`  if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

**Example 1:**

**Input:** pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
**Output:** true
**Explanation:** We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

**Example 2:**

**Input:** pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
**Output:** false
**Explanation:** 1 cannot be popped before 2.

**Note:**

1. `0 <= pushed.length == popped.length <= 1000`
2. `0 <= pushed[i], popped[i] < 1000`
3. `pushed`  is a permutation of  `popped`.
4. `pushed`  and  `popped`  have distinct values.

**Difficulty**:Medium

**Category**:Stack

<!-- more -->

# Solution

```cpp
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s;
    auto it = popped.begin();
    for (int& e : pushed) {
      s.push(e);
      while (!s.empty() && s.top() == *it) {
        s.pop();
        ++it;
      }
    }
    return it == popped.end();
  }
};
```

## Solution 2: Stack

```cpp
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> r(n, -1);
    stack<int> s;
    for (int i = 0; i < 2 * n; ++i) {
      // Deal with the element;
      int temp = nums[i % n];
      while (!s.empty() && temp > nums[s.top()]) {
        r[s.top()] = temp;
        s.pop();
      }
      // save the element;
      if (i < n) s.push(i);
    }
    return r;
  }
};
```