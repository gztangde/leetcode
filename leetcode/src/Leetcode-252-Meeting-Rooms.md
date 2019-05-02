---
title: Leetcode 252. Meeting Rooms
date: 2019-03-24 20:41:31
updated: 2019-03-24 20:41:31
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Question

Given an array of meeting time intervals consisting of start and end times `[[s1,e1],[s2,e2],...]` (si < ei), determine if a person could attend all meetings.

For example,  
Given `[[0, 30],[5, 10],[15, 20]]`,  
return `false`.

**Difficulty**:Easy

**Category**:

# Solution

```cpp
class Solution {
 public:
  bool canAttendMeetings(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) { return a.start < b.start; });
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start < intervals[i - 1].end) {
        return false;
      }
    }
    return true;
  }
};
```