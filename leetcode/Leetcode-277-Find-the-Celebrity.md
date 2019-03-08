---
title: Leetcode 277. Find the Celebrity
date: 2019-03-05 18:03:05
updated: 2019-03-05 18:03:05
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

题目大意：在一群人中寻找名人，所谓名人就是每个人都认识他，他却不认识任何人，限定了只有1个或0个名人，给定了一个API函数，输入a和b，用来判断a是否认识b，让我们尽可能少的调用这个函数，来找出人群中的名人。

Suppose you are at a party with `n` people (labeled from `0` to `n - 1`) and among them, there may exist one celebrity. The definition of a celebrity is that all the other `n - 1`people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function `bool knows(a, b)` which tells you whether A knows B. Implement a function `int findCelebrity(n)`, your function should minimize the number of calls to `knows`.

Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return `-1`.

**Difficulty**:Medium

**Category**:

# Analyze

建立个一维数组用来标记每个人的名人候选状态，开始均初始化为true，表示每个人都是名人候选人，然后我们一个人一个人的验证其是否为名人，对于候选者i，我们遍历所有其他人 j，如果 i 认识 j，或者 j 不认识 i，说明i不可能是名人，那么我们标记其为false，然后验证下一个候选者，反之如果 i 不认识 j，或者 j 认识 i，说明 j 不可能是名人，标记之。对于每个候选者i，如果遍历了一圈而其候选者状态仍为true，说明i就是名人，返回即可，如果遍历完所有人没有找到名人，返回-1

# Solution

```cpp
class Solution {
 public:
  int findCelebrity(int n) {
    vector<bool> candidate(n, true);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (candidate[i] && i != j) {
          if (knows(i, j) || !knows(j, i)) {
            candidate[i] = false;
            break;
          } else {
            candidate[j] = false;
          }
        }
      }
      if (candidate[i]) return i;
    }
    return -1;
  }
};
```

设定候选人res为0，原理是先遍历一遍，对于遍历到的人i，若候选人res认识i，则将候选人res设为i，完成一遍遍历后，我们来检测候选人res是否真正是名人，我们如果判断不是名人，则返回-1，如果并没有冲突，返回res

```cpp
class Solution {
 public:
  int findCelebrity(int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (knows(res, i)) res = i;
    }
    for (int i = 0; i < n; ++i) {
      if (res != i && (knows(res, i) || !knows(i, res))) return -1;
    }
    return res;
  }
};
```