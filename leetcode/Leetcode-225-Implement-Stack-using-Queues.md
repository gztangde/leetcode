---
title: Leetcode 225. Implement Stack using Queues
date: 2019-01-22 17:18:42
updated: 2019-01-22 17:18:42
categories: 
- [Leetcode]
- [Leetcode, Stack]
- [Leetcode, Design]
tags: Leetcode
notshow: true
top:
---

# Question

Implement the following operations of a stack using queues.

- push(x) -- Push element x onto stack.
- pop() -- Removes the element on top of the stack.
- top() -- Get the top element.
- empty() -- Return whether the stack is empty.

**Example:**

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false

**Notes:**

- You must use  _only_  standard operations of a queue -- which means only  `push to back`,  `peek/pop from front`,  `size`, and  `is empty`operations are valid.
- Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
- You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

**Difficulty**:Easy

**Category**:Stack, Design

<!-- more -->

------------

# Analyze

# Solution

```cpp
class MyStack {
 public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) {
    q_.push(x);
    for (int i = 0; i < q_.size() - 1; ++i) {
      q_.push(q_.front());
      q_.pop();
    }
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int temp = q_.front();
    q_.pop();
    return temp;
  }

  /** Get the top element. */
  int top() { return q_.front(); }

  /** Returns whether the stack is empty. */
  bool empty() { return q_.empty(); }

 private:
  queue<int> q_;
};
```


