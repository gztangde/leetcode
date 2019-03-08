---
title: Leetcode 142. Linked List Cycle II
date: 2018-11-21 06:09:31
updated: 2018-11-21 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a linked list, return the node where the cycle begins. If there is no cycle, return  `null`.

**Note:**  Do not modify the linked list.

**Follow up**:  
Can you solve it without using extra space?

**Difficulty**:Medium

**Category**:Linked List, Two Points

<!-- more -->

# Analyze

这道题目，感觉更多的是考虑数学公式的推导的样子，如果是一个环，可以得到下面这个图形：

![](/images/in-post/2018-11-21-Leetcode-142-Linked-List-Cycle-II/2018-11-21-16-54-49.png)

图片来自于博客: [[算法][LeetCode]Linked List Cycle & Linked List Cycle II——单链表中的环](http://www.cnblogs.com/hiddenfox/p/3408931.html)

先对图中符号做下面的定义：
- `X`是链表头
- `Y`是环的第一个节点，也就是环的起点
- 'Z'是快慢节点的相遇位置
- 环的长度是`r = c + b`
- slow指针走过的距离是 `s = a + b`
- fast指针走过的距离是 `2s = a + n(c+b) + b`
- 相遇的时候fast指针在环里面已经走了n圈了

根据上面的图形，得到下面的推导：

- 2s = a + n(c+b) + b
- 2(a+b) = a + n(c+b) + b
- a+b = n(c+b)
- a = n(c+b) - b = （n-1)×（c+b） + c = (n-1)*r + c

所以如果在相遇的时候，重新定义一个`slow2`的慢指针，每次走一步，那么他们一定可以在环的起点位置相遇的。

# Solution

```cpp
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        ListNode *slow2 = head;

        while (slow2 != slow) {
          slow2 = slow2->next;
          slow = slow->next;
        }
        return slow2;
      }
    }
    return nullptr;
  }
};
```

<!-- TODO:完成一篇关于环的总结的文章 -->