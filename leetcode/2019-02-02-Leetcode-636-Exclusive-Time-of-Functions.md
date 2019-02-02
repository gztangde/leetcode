---
title: Leetcode 636. Exclusive Time of Functions
date: 2019-02-02 01:12:32
updated: 2019-02-02 01:12:32
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given the running logs of  **n**  functions that are executed in a nonpreemptive single threaded CPU, find the exclusive time of these functions.

Each function has a unique id, start from  **0**  to  **n-1**. A function may be called recursively or by another function.

A log is a string has this format :  `function_id:start_or_end:timestamp`. For example,  `"0:start:0"`  means function 0 starts from the very beginning of time 0.  `"0:end:0"`  means function 0 ends to the very end of time 0.

Exclusive time of a function is defined as the time spent within this function, the time spent by calling other functions should not be considered as this function's exclusive time. You should return the exclusive time of each function sorted by their function id.

**Example 1:**  

> **Input:**
> n = 2
> logs =
> ["0:start:0",
 > "1:start:2",
 > "1:end:5",
 > "0:end:6"]
> **Output:**[3, 4]
> **Explanation:**
> Function 0 starts at time 0, then it executes 2 units of time and reaches the end of time 1.
> Now function 0 **calls function 1**, function 1 starts at time 2, executes 4 units of time and end at time 5.
> Function 0 is running again at time 6, and also end at the time 6, thus executes 1 unit of time.
> So function 0 totally execute 2 + 1 = 3 units of time, and function 1 totally execute 4 units of time.

**Note:**  

1. Input logs will be sorted by timestamp, NOT log id.
2. Your output should be sorted by function id, which means the 0th element of your output corresponds to the exclusive time of function 0.
3. Two functions won't start or end at the same time.
4. Functions could be called recursively, and will always end.
5. 1 <= n <= 100

**Difficulty**:Medium

**Category**:

# Analyze

题目大意：给你一些函数的起始/终止时间的日志，让你输出每个函数的总运行时间。假设单核单线程，支持递归函数。

Notes:

1. 输入的日志数据是按照时间戳排序的, 而不是日志的进程ID号码
2. 输出的结果需要按照函数的ID号码进行排序
3. 两个函数不能够开始和结束在同一个时间的.
4. 函数是可以递归调用的, 并且一定能够结束
5. 1 <= n <= 100

# Solution

**Using Stack**

```cpp
// Runtime: 16 ms, faster than 95.40% of C++ online submissions for Exclusive Time of Functions.
// Memory Usage: 827.4 KB, less than 11.11% of C++ online submissions for Exclusive Time of Functions.
class Solution {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> ans(n, 0);
    stack<int> sta;
    int pretime = 0;
    for (auto& s : logs) {
      int f1 = s.find(":"), f2 = s.find_last_of(":");
      int idx = stoi(s.substr(0, f1)), time = stoi(s.substr(f2 + 1));
      string type = s.substr(f1 + 1, f2 - f1 - 1);
      if (!sta.empty()) ans[sta.top()] += time - pretime;
      pretime = time;
      if (type == "start") sta.push(idx);
      else {
        ++ans[sta.top()];
        sta.pop();
        ++pretime;
      }
    }
    return ans;
  }
};
```