
# Question

Given a singly linked list  _L_:  _L_0→_L_1→…→_L__n_-1→_L_n,  
reorder it to:  _L_0→_L__n_→_L_1→_L__n_-1→_L_2→_L__n_-2→…

You may  **not**  modify the values in the list's nodes, only nodes itself may be changed.

**Example 1:**

> Given 1->2->3->4, reorder it to 1->4->2->3.

**Example 2:**

> Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

**Difficulty**:Medium
**Category**:Linked List


------------

# Analyze

利用快慢节点的方式，找到中间的节点，然后断开两个部分，然后将后面的链表翻转，在合并两个部分的单链表。

------------

# Solution

```cpp
class Solution {
 public:
  void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return;
    ListNode *slow = head, *fast = head, *left = head, *right = nullptr;

    while (fast && fast->next) {
      left = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    // Cut this list at the Middle.
    left->next = nullptr;
    right = reverse(slow);

    left = head;
    // Merged these two List;
    while (left->next) {
      ListNode* temp = left->next;
      left->next = right;
      right = right->next;
      left->next->next = temp;
      left = temp;
    }
    left->next = right;
  }

  // From Leetcode 206. Reverse Linked List
  ListNode* reverse(ListNode* head) {
    // Do something to reverse node
    if (!head) return head;
    ListNode dummy(-1);
    dummy.next = head;

    ListNode* const start = &dummy;
    ListNode* prev = head;
    ListNode* cur = head->next;
    while (cur) {
      prev->next = cur->next;
      cur->next = start->next;
      start->next = cur;
      cur = prev->next;
    }
    return dummy.next;
  }
};
```