---
title: Leetcode 641. Design Circular Deque
date: 2019-02-01 13:42:35
updated: 2019-02-01 13:42:35
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Design your implementation of the circular double-ended queue (deque).

Your implementation should support following operations:

- `MyCircularDeque(k)`: Constructor, set the size of the deque to be k.
- `insertFront()`: Adds an item at the front of Deque. Return true if the operation is successful.
- `insertLast()`: Adds an item at the rear of Deque. Return true if the operation is successful.
- `deleteFront()`: Deletes an item from the front of Deque. Return true if the operation is successful.
- `deleteLast()`: Deletes an item from the rear of Deque. Return true if the operation is successful.
- `getFront()`: Gets the front item from the Deque. If the deque is empty, return -1.
- `getRear()`: Gets the last item from Deque. If the deque is empty, return -1.
- `isEmpty()`: Checks whether Deque is empty or not.
- `isFull()`: Checks whether Deque is full or not.

**Example:**

MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
circularDeque.insertLast(1);			// return true
circularDeque.insertLast(2);			// return true
circularDeque.insertFront(3);			// return true
circularDeque.insertFront(4);			// return false, the queue is full
circularDeque.getRear();  			// return 2
circularDeque.isFull();				// return true
circularDeque.deleteLast();			// return true
circularDeque.insertFront(4);			// return true
circularDeque.getFront();			// return 4

**Note:**

- All values will be in the range of [0, 1000].
- The number of operations will be in the range of [1, 1000].
- Please do not use the built-in Deque library.

**Difficulty**:Medium

**Category**:

<!-- more -->

------------

# Analyze

# Solution

```cpp
class MyCircularDeque {
 public:
  MyCircularDeque(int n) : buffer(n, -1), cnt(0), k(n), front(n - 1), rear(0){ }

  bool insertFront(int value) {
    if (cnt == k) return false;
    buffer[front--] = value;
    front = (front + k) % k;
    ++cnt;
    return true;
  }

  bool insertLast(int value) {
    if (cnt == k) return false;
    buffer[rear++] = value;
    rear %= k;
    ++cnt;
    return true;
  }

  bool deleteFront() {
    if (cnt == 0) return false;
    front = (front + 1) % k;
    --cnt;
    return true;
  }

  bool deleteLast() {
    if (cnt == 0) return false;
    rear = (rear - 1 + k) % k;
    --cnt;
    return true;
  }

  int getFront() { return cnt == 0 ? -1 : buffer[(front + 1) % k]; }
  int getRear() { return cnt == 0 ? -1 : buffer[(rear - 1 + k) % k]; }
  bool isEmpty() { return cnt == 0; }
  bool isFull() { return cnt == k; }

 private:
  vector<int> buffer;
  int cnt;
  int k;
  int front;
  int rear;
};

```