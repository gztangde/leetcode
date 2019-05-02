---
title: Leetcode 253. Meeting Rooms II
date: 2019-03-24 20:30:16
updated: 2019-03-24 20:30:16
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Question

Given an array of meeting time intervals consisting of start and end times `[[s1,e1],[s2,e2],...]` (si < ei), find the minimum number of conference rooms required.

For example,  
Given `[[0, 30],[5, 10],[15, 20]]`,  
return `2`.

**Difficulty**:Medium

**Category**:

# Solution

先把所有的时间区间按照起始时间排序，然后新建一个最小堆，开始遍历时间区间，如果堆不为空，且首元素小于等于当前区间的起始时间，我们去掉堆中的首元素，把当前区间的结束时间压入堆，由于最小堆是小的在前面，那么假如首元素小于等于起始时间，说明上一个会议已经结束，可以用该会议室开始下一个会议了，所以不用分配新的会议室，遍历完成后堆中元素的个数即为需要的会议室的个数

## Solution 1: Priority_queue

Time complexity: O(n log n), Space complexity: O(n)

```cpp
class Solution {
 public:
  int minMeetingRooms(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) { return a.start < b.start; });
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto a : intervals) {
      if (!q.empty() && q.top() <= a.start) q.pop();
      q.push(a.end);
    }
    return q.size();
  }
};
```