---
title: Leetcode 84. Largest Rectangle in Histogram
date: 2018-11-21 06:09:31
updated: 2018-11-21 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given  _n_  non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

![](/images/in-post/2018-11-21-Leetcode-84-Largest-Rectangle-in-histogram/2018-11-21-19-38-09.png)

**Example:**

> **Input:** [2,1,5,6,2,3]
> **Output:** 10

**Difficulty**:Medium

**Category**:Array, Stack

<!-- more -->

# Analyze

**问题：** 求直方图里面的最大矩形面积
**方案一(Solution 1):** 来自于博客 [[LeetCode] Largest Rectangle in Histogram 解题报告](http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html) 通过遍历数组，没找到一个局部峰值，就向前遍历所有的数值，算出矩形面积，每次计算结果进行对比，保留最大值

**方案二(Solution 2)：** 维护一个单调栈，用来保存递增序列，相当于上面那种方法的找局部峰值。我们可以看到，直方图矩形面积要最大的话，需要尽可能的使得连续的矩形多，并且最低一块的高度要高。有点像木桶原理一样，总是最低的那块板子决定桶的装水量。

> **递增栈Vs递减栈**
> 递增栈是维护递增的顺序，当遇到小于栈顶元素的数就开始处理，而递减栈正好相反，维护递减的顺序，当遇到大于栈顶元素的数开始处理。

在这一题中，我们要把大于栈顶的连续数字进入堆栈，而当遇到小于栈顶元素的数字时，就要取出栈顶元素进行处理了，那取出的顺序就是从高板子到矮板子了，于是乎遇到的较小的数字只是一个触发，开始计算矩形面积了，为了使得最后一块板子也被处理，这里用了个小trick，在高度数组最后面加上一个0，这样原先的最后一个板子也可以被处理了。(引自于[博客](http://www.cnblogs.com/grandyang/p/4322653.html))

# Solution

## Solution 1

遍历数组，遇到局部峰值后计算矩阵的大小，1. 然后比较大小:

- `i + 1 < height.size() && height[i] <= height[i + 1]`, 如果当前数值小于等于下一个数值，那就说明这不是一个局部最大值，所以继续向后走，找到在一个局部位置的最大值`int minH = height[i]`
- `for (int j = i; j >= 0; --j)`，向这个局部最大值的前面找一个局部范围内的小值(只要比当前的最大值小就可以了)，使用这个数值计算一个面积，在这里，我们可以计算出来`i`个面积，在这个`i`个面积里面找到那个最大的面积

```cpp
for (int j = i; j >= 0; --j) {
  minH = min(minH, height[j]);
  int area = minH * (i - j + 1);
  res = max(res, area);
}
```

完整代码如下：

```cpp
class Solution {
 public:
  int largestRectangleArea(vector<int> &height) {
    int res = 0;
    for (int i = 0; i < height.size(); ++i) {
      if (i + 1 < height.size() && height[i] <= height[i + 1]) {
        continue;
      }
      int minH = height[i];
      for (int j = i; j >= 0; --j) {
        minH = min(minH, height[j]);
        int area = minH * (i - j + 1);
        res = max(res, area);
      }
    }
    return res;
  }
};
```

## Solution 2

使用的网上推荐的一种方案, 使用**递进增栈**来处理这个问题。

- 为了保证能够处理到最后的一个元素，就在原有的元素最后加上一个`0`,保证最后是一个小的数值，这样能够处理到最后一段元素:`heights.emplace_back(0);`
- 如果当前堆栈为空(第一个元素，或者处理完上一次)，或者当前元素大于堆栈最上面的那个索引数值的话，那么就将这个数据放入到堆栈里面去。

```cpp
if (s.empty() || heights[i] > heights[s.top()]) {
  s.push(i++);
}
```

- 如果遇到一个小的数值的话，那么就处理堆栈里面的数据：`heights[tmp] * (s.empty() ? i : i - s.top() - 1))`

```cpp
else {
  // 取出栈顶的元素
  int tmp = s.top();
  s.pop();
  res = max(res, heights[tmp] * (s.empty() ? i : i - 1 - s.top()));
  // i - 1 is the position at the last element for the smaller element.
}
```

完整的代码如下：

```cpp
class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int res = 0;
    std::stack<int> s;
    heights.emplace_back(0);

    for (int i = 0; i < heights.size();) {
      // If heights[i] > heights[s.top()], then push in the stack
      if (s.empty() || heights[i] > heights[s.top()]) {
        s.push(i++);
      } else {
        int tmp = s.top();
        s.pop();
        res = max(res, heights[tmp] * (s.empty() ? i : i - s.top() - 1));
      }
    }
    return res;
  }
};
```

## Solution 3

**Solution 2简化版本：** 代码如下

```cpp
class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int res = 0;
    stack<int> st;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); ++i) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        int cur = st.top();
        st.pop();
        res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
      }
      st.push(i);
    }
    return res;
  }
};
```