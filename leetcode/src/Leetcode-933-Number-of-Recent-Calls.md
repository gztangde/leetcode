---
title: Leetcode 933. Number of Recent Calls
date: 2019-01-10 00:48:47
updated: 2019-01-10 00:48:47
categories: Leetcode
tags: Leetcode

notshow: true
top:
---

# Question

Write a class  `RecentCounter`  to count recent requests.

It has only one method: `ping(int t)`, where t represents some time in milliseconds.

Return the number of  `ping`s that have been made from 3000 milliseconds ago until now.

Any ping with time in  `[t - 3000, t]`  will count, including the current ping.

It is guaranteed that every call to  `ping`  uses a strictly larger value of `t`  than before.

**Example 1:**

> **Input:** inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
> **Output:** [null,1,2,3,3]

**Note:**

1.  Each test case will have at most  `10000`  calls to  `ping`.
2.  Each test case will call `ping`  with strictly increasing values of  `t`.
3.  Each call to ping will have  `1 <= t <= 10^9`.

**Difficulty**:Easy

**Category**:Queue

<!-- more -->

# Analyze

这道题目，一眼看过去，没有搞明白这个题目说的是什么东西。就是找出最近的`3000`毫秒内有多少个调用的请求，每个调用请求对应的是就是`pint(t)`函数，其中的`t`就是请求的时间，可以保证每一次`ping`的参数`t`是不大于前面３０００．

**Understand this Question：**

The input is the `inputs = [[],[1],[100],[3001],[3002]]`. These number in the array descript the `time` when the `Ping` is coming. As a result, I need to calculate the `numbers` of `ping` within the last `3000 milliseconds`.

**Plan 1(Solution 1)**: Queue

We can easily use the data structure `Queue` to solve this problem.
- If this cur `ping - q.front > 3000`, then we can pop the front one because we don't need them any more.
- If the cur `ping - q.front < 3000 `, then we need to push the cur's time in the queue.
- We use the queue's size as the return value.

# Solution

## Solution 1: Queue

```cpp
// Solution 1: Queue
// Runtimes:
class RecentCounter {
 public:
  RecentCounter() {}

  int ping(int t) {
    while (!q.empty() && t - q.front() > 3000) q.pop();
    q.push(t);
    return q.size();
  }

 private:
  queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
```