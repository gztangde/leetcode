---
title: Leetcode 155. Min Stack
date: 2019-01-22 17:20:53
updated: 2019-01-22 17:20:53
categories: 
- [Leetcode]
- [Leetcode, Stack]
- [Leetcode, Design]
tags: Leetcode
notshow: true
top:
---

# Question

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

- push(x) -- Push element x onto stack.
- pop() -- Removes the element on top of the stack.
- top() -- Get the top element.
- getMin() -- Retrieve the minimum element in the stack.

**Example:**  

> MinStack minStack = new MinStack();
> minStack.push(-2);
> minStack.push(0);
> minStack.push(-3);
> minStack.getMin();   --> Returns -3.
> minStack.pop();
> minStack.top();      --> Returns 0.
> minStack.getMin();   --> Returns -2.

**Difficulty**:Easy
**Category**:Stack, Design

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    s_.push(x);
    if (s_min.empty() || x <= getMin()) s_min.push(x);
  }

  void pop() {
    if (s_.top() == s_min.top()) s_min.pop();
    s_.pop();
  }

  int top() { return s_.top(); }

  int getMin() { return s_min.top(); }

 private:
  stack<int> s_;
  stack<int> s_min;
};
```


