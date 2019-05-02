---
title: Leetcode Algorithm Linked List, Array
date: 2019-01-26 00:51:16
updated: 2019-01-26 00:51:16
categories: 
- [Notes]
tags: Node
notshow: true
mathjax: true
top:
---

# Introduce

主要介绍: 数组(矩阵), 链表(单链表,双向链表)

<!-- more -->

------------

# Related Problems

## Array

常用STL函数:

**distance, unique函数**

```cpp
// distance: The number of elements between first and last.
// unique(nums.begin(), nums.end(): An iterator to the element that follows the last element not removed.
// The range between first and this iterator includes all the elements in the sequence that were not considered duplicates.
distance(nums.begin(), unique(nums.begin(), nums.end())
remove(nums.begin(), nums.end(), target)
```

**重点题目:**
- 经典题目: [Median Of two Sorted Arrays](../Leetcode-4-Median-of-Two-Sorted-Arrays/), 给定两个已经排序好的数组,找到两者所有元素中第k大的元素

- 处理元素:[Remove Element](../Leetcode-27-Remove-Element/), [Remove Duplicates From Sorted Array](../Leetcode-26-Remove-Duplicates-From-Sorted-Array/), [Remove Duplicates From Sorted Array II](../Leetcode-80-Remove-Duplicates-From-Sorted-Array-II/)
- 二分搜索: [Search in Rotated Sorted Array](../Leetcode-33-Search-In-Rotated-Sorted-Array/), [Search in Rotated Sorted Array II](../Leetcode-81-Search-In-Rotated-Sorted-Array-II/)
- 经典题目: [Median Of two Sorted Arrays](../Leetcode-4-Median-of-Two-Sorted-Arrays/), 给定两个已经排序好的数组,找到两者所有元素中第k大的元素
- [Longest Consecutive Sequence](../Leetcode-128-Longest-Consecutive-Sequence/), [Max Consecutive Ones](../Leetcode-485-Max-Consecutive-Ones/)
- [Two-Sum](../Leetcode-1-Two-Sum/), [Two-Sum(Sorted array)](../Leetcode-167-Two-Sum-II-Input-Array-Is-Sorted/), [3Sum](../Leetcode-15-3Sum/), [3Sum Cloest](../Leetcode-16-3Sum-Closest/), [4Sum](../Leetcode-18-4Sum/)
- [Next Permutation](../Leetcode-31-Next-Permutation/), [Permutation Sequence](../Leetcode-60-Permutation-Sequence/)
- [Trapping Rain Water](../Leetcode-42-Trapping-Rain-Water/)
- [Plus One](../Leetcode-66-Plus-One/)
- [Climbing Stairs](../Leetcode-70-Climbing-Stairs/)
- [Gray Code](../Leetcode-89-Gray-Code/)
- [Gas Station](../Leetcode-134-Gas-Station/)
- [Single Number](../Leetcode-136-Single-Number/), [Single Number II](../Leetcode-137-Single-Number-II/)
- [Set Mismatch](../Leetcode-645-Set-Mismatch/), [Find All Numbers Disappeared in an Array](../Leetcode-448-Find-All-Numbers-Disappeared-In-An-Array/), [Find All Duplicates in an Array](../Leetcode-442-Find-All-Duplicates-In-An-Array/), [Find the Duplicate Number](../Leetcode-287-Find-the-Duplicate-Number/)

## Martix

- [Rotate Image](../Leetcode-48-Rotate-Image/)
- [Set Matrix Zeros](../Leetcode-73-Set-Matrix-Zeroes/)
- [Valid Sudoku](../Leetcode-36-Valid-Sudoku/)
- [Reshape The Matrix](../Leetcode-566-Reshape-the-Matrix/)
- 二分搜索: [Search a 2D Matrix](../Leetcode-74-Search-a-2D-Matrix/), [Kth-Smallest Element in a Sorted Matrix](../Leetcode-378-Kth-Smallest-Element-in-a-Sorted-Matrix/)

## Linked List

- [Remove Duplicates From Sorted List](../Leetcode-83-Remove-Duplicates-From-Sorted-List/), [Remove Duplicates From Sorted List II](../Leetcode-82-Remove-Duplicates-From-Sorted-List-II/), [Remove Nth Node From End of List](../Leetcode-19-Remove-Nth-Node-From-End-Of-List/)
- [Add Two Numbers](../Leetcode-2-Add-Two-Numbers/)
- [Reverse Linked List II](../Leetcode-92-Reverse-Linked-List-II/)
- [Partition List](../Leetcode-86-Partition-List/)
- [Rotate List](../Leetcode-61-Rotate-List/)
- [Swap Nodes in Pairs](../Leetcode-24-Swap-Nodes-In-Pairs/)
- [Reverse Nodes in k-Group](../Leetcode-25-Reverse-Nodes-In-K-Group/)
- [Copy List with Random Pointer](../Leetcode-138-Copy-List-With-Random-Pointer/)
- [Linked List Cycle](../Leetcode-141-Linked-List-Cycle/), [Linked List Cycle II](../Leetcode-142-Linked-List-Cycle-II/)
- [Reorder List](../Leetcode-143-Reorder-List/)
- [LRU Cache](../Leetcode-146-LRU-Cache/)