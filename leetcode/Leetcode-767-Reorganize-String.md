---
title: Leetcode 767. Reorganize String
date: 2019-01-31 21:52:48
updated: 2019-01-31 21:52:48
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a string  `S`, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result. If not possible, return the empty string.

**Example 1:**

**Input:** S = "aab"
**Output:** "aba"

**Example 2:**

**Input:** S = "aaab"
**Output:** ""

**Note:**

- `S`  will consist of lowercase letters and have length in range  `[1, 500]`.

**Difficulty**:Medium

**Category**:String, Heap, Greedy, Sort

<!-- more -->

------------

# Analyze

在这道题中考虑使用`堆排序`, 处理步骤如下:

* 使用`vector<int> v_(26, 0)`记录每一个字符出现的次数.
* 使用`priority_queue`对得到的结果进行排序, 在这里可以进行剪枝, 如果其中某一个元素的个数超过了总的字符长度的一半,那就说明这个没有办法按照题目的要求给出输出, 在这里返回去空字符串.
* 当我们得到字符分别个数的排序之后, 我们使用一个队列, 每次到priority_queue 里面去得到当前最大个素的字母,然后將这个字母加载到`ans`里面. 再将其个数减少一, 然后将其推入到队列中, 当队列中的个数超过两个之后, 就处理队列, 將队里中的字母在推入priority_queue里面去重新排序,这样就可以实现字符分开的要求了.

<!-- TODO:相信自己的设计思路, 去实现代码就好了. -->

# Solution

## Solution 1: 堆排序

```cpp
class Solution {
 public:
  string reorganizeString(string S) {
    string ans;
    int n = S.length();
    vector<int> v_(26, 0);
    for (char& c : S) v_[c - 'a']++;
    // Sort the date in the priority_queue
    priority_queue<pair<int, int>> q_;
    for (int i = 0; i < 26; ++i) {
      if (v_[i] > (n + 1) / 2) return "";
      if (v_[i]) q_.push({v_[i], i + 'a'});
    }
    // Deal with two elements each tiem
    queue<pair<int, int>> r_;
    while (!q_.empty() || r_.size() > 1) {
      // r_.size() > 1;
      if (r_.size() > 1) {
        auto cur = r_.front();
        r_.pop();
        if (cur.first > 0) q_.push(cur);
      }

      if (!q_.empty()) {
        auto cur = q_.top();
        q_.pop();
        ans += cur.second;
        cur.first--;
        r_.push(cur);
      }
    }
    return ans;
  }
};
```