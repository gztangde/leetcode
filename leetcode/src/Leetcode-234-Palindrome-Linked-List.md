---
title: Leetcode 234. Palindrome Linked List
date: 2019-01-25 19:11:17
updated: 2019-01-25 19:11:17
categories: 
- [Leetcode]
- [Leetcode, Linked-List]
- [Leetcode, Two-Points]
tags: Leetcode
notshow: true
top:
---

# Question

Given a singly linked list, determine if it is a palindrome.

**Example 1:**

**Input:** 1->2
**Output:** false

**Example 2:**

**Input:** 1->2->2->1
**Output:** true

**Follow up:**  
Could you do it in O(n) time and O(1) space?

**Difficulty**:Easy

**Category**:Linked-List, Two-Points

<!-- more -->

# Solution

```cpp
// Runtime: 1484ms
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    int len = getlength(head);
    int left = 1, right = len;
    while (left < right) {
      if (getnthnode(head, left)->val == getnthnode(head, right)->val) {
        left++;
        right--;
      } else 
        return false;
    }
    return true;
  }
 private:
  
  int getlength(ListNode* node) {
    int n = 0;
    while (node) {
      ++n;
      node = node->next;
    }
    return n;
  }

  ListNode* getnthnode(ListNode* node, int n) {
    while (--n) node = node->next;
    return node;
  }
};
```

## Solution 2: 

```cpp
// Runtime: 1484ms
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    int len = getlength(head);
    vector<ListNode*> rec;
    rec.reserve(len);
    while (head) {
      rec.emplace_back(head);
      head = head->next;
    }

    int left = 0, right = len - 1;
    while (left < right)
      if (rec[left++]->val != rec[right--]->val) return false;

    return true;
  }

 private:
  int getlength(ListNode* node) {
    int n = 0;
    while (node) {
      ++n;
      node = node->next;
    }
    return n;
  }
};
```


