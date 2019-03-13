---
title: Leetcode 138. Copy List with Random Pointer
date: 2018-11-21 06:09:31
updated: 2018-11-21 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a  [**deep copy**](https://en.wikipedia.org/wiki/Object_copying#Deep_copy)  of the list.

**Example 1:**

**![](https://discuss.leetcode.com/uploads/files/1470150906153-2yxeznm.png)**

**Input:**

```
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
```

**Explanation:**

* Node 1's value is 1, both of its next and random pointer points to Node 2.
* Node 2's value is 2, its next pointer points to null and its random pointer points to itself.

**Note:**

1. You must return the  **copy of the given head** as a reference to the cloned list.

**Difficulty**:Medium

**Category**:HashTable, Linked List

<!-- more -->

# Analyze

这道题目看上去是比较麻烦的，因为你不能够同时完成所有内容的`Deep copy`, 因为每个节点的`random`是不知道的，所以是不能够在第一次拷贝的时候就完全完成拷贝。可以分成下面几个步骤完成。

- 在当前节点中，拷贝一个节点包含了`Next`节点以及`int label`的数值，然后将这个节点添加到当前现在的list里面去，最后在将其分出来。
- 完成 `rondom` 节点内容的拷贝工作
- 分解两个List

# Solution

## Solution 1: Iterative

Use the next pointer of each node to store its copy.

Time complexity: O(1), Space complexity: O(1)

```cpp
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    Node dummy(-1, nullptr, nullptr);
    Node* new_cur = &dummy;

    // Copy the Next node and val
    // Add it after the original node
    for (Node* cur = head; cur != nullptr;) {
      Node* node = new Node(cur->val, nullptr, nullptr);
      node->next = cur->next;
      cur->next = node;
      cur = node->next;
    }

    // Copy the random node
    for (Node* cur = head; cur != nullptr;) {
      // Copy the random node
      if (cur->random != nullptr) cur->next->random = cur->random->next;
      cur = cur->next->next;
    }

    for (Node* cur = head; cur != nullptr;) {
      new_cur->next = cur->next;
      new_cur = new_cur->next;
      cur->next = cur->next->next;
      cur = cur->next;
    }

    return dummy.next;
  }
};
```

另外一种写法：

```cpp
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return NULL;
    }
    copies[head] = new Node(head->val, NULL, NULL);
    Node* node = head;
    while (node) {
      Node *next = node->next, *random = node->random;
      if (next && copies.find(next) == copies.end()) {
        copies[next] = new Node(next->val, NULL, NULL);
      }
      if (random && copies.find(random) == copies.end()) {
        copies[random] = new Node(random->val, NULL, NULL);
      }
      copies[node]->next = next ? copies[next] : NULL;
      copies[node]->random = random ? copies[random] : NULL;
      node = next;
    }
    return copies[head];
  }

 private:
  unordered_map<Node*, Node*> copies;
};
```

## Solution 2: Recursive

```cpp
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    if (copies.find(head) == copies.end()) {
      copies[head] = new Node(head->val, NULL, NULL);
      copies[head]->next = copyRandomList(head->next);
      copies[head]->random = copyRandomList(head->random);
    }
    return copies[head];
  }

 private:
  unordered_map<Node*, Node*> copies;
};
```