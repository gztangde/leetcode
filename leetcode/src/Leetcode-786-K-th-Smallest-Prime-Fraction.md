---
title: Leetcode 786. K th Smallest Prime Fraction
date: 2019-01-19 17:42:14
updated: 2019-01-19 17:42:14
categories: 
- [Leetcode]
- [Leetcode, Binary-Search]
- [Leetcode, Heap]
tags: Leetcode
notshow: true
top:
---

# Leetcode 786. K th Smallest Prime Fraction

A sorted list  `A`  contains 1, plus some number of primes. Then, for every p < q in the list, we consider the fraction p/q.

What is the  `K`-th smallest fraction considered? Return your answer as an array of ints, where  `answer[0] = p`  and  `answer[1] = q`.

**Examples:**
> **Input:** A = [1, 2, 3, 5], K = 3
> **Output:** [2, 5]
> **Explanation:**
> The fractions to be considered in sorted order are:
> 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
> The third fraction is 2/5.
> 
> **Input:** A = [1, 7], K = 1
> **Output:** [1, 7]

**Note:**

- `A`  will have length between  `2`  and  `2000`.
- Each  `A[i]`  will be between  `1`  and  `30000`.
- `K`  will be between  `1`  and  `A.length * (A.length - 1) / 2`.

**Difficulty**:Hard

**Category**:Binary-Search, Heap

<!-- more -->

# Analyze

在Leetcode里面有好几个类似的题目是利用了`Binary-Search`的方式去查找第`k`小的数.

![](/images/in-post/2019-01-19-Leetcode-786-K-th-Smallest-Prime-Fraction/2019-01-19-17-45-08.png)

根据input的数据大小,确定使用的方法是`Binary-search`.

# Solution

## Solution 1: Binary Search

Time complexity: O(n*C) C <= 31

```cpp
class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    const int n = A.size();
    double left = 0, right = 1.0;
    vector<int> ans(2, 0);
    while (left < right) {
      double mid = left + (right - left) / 2;

      int cnt = count(A, mid, ans);
      if (cnt == K) return ans;
      else if (cnt > K) right = mid;
      else left = mid;
    }
    return {};
  }

 private:
  int count(vector<int>& A, double& target, vector<int>& ans) {
    int n = A.size(), cnt = 0;
    double max_f = 0.0;
    for (int i = 0, j = 1; i < n - 1; ++i) {
      // Count how many frac pair less that target
      while (j < n && A[i] > target * A[j]) ++j;
      if (n == j) break;
      cnt += (n - j);
  
      const double f = static_cast<double>(A[i]) / A[j];
      // Found the last biggest one element in this search
      if (f > max_f) {
        ans[0] = A[i];
        ans[1] = A[j];
        max_f = f;
      }
    }
    return cnt;
  }
};
```

## Solution 2: Priority Queue

Cite:[K-th Smallest Prime Fraction 第K小的质分数](http://www.cnblogs.com/grandyang/p/9135156.html)

输入是一个有序数组，里面是1和一些质数，说是对于任意两个数，都可以组成一个 [0, 1] 之间分数，让我们求第K小的分数是什么。由于数组是有序的，所以最小的分数肯定是由第一个数字和最后一个数字组成的，而接下来第二小的分数我们就不确定是由第二个数字和最后一个数字组成的，还是由第一个数字跟倒数第二个数字组成的。我们的想法是用一个最小堆来存分数，那么每次取的时候就可以将最小的分数取出来，由于前面说了，我们不能遍历所有的分数都存入最小堆，那么我们怎么办呢，我们可以先存n个，哪n个呢？其实就是数组中的每个数字都和最后一个数字组成的分数。由于我们需要取出第K小的分数，那么我们在最小堆中取K个分数就可以了，第一个取出的分数就是那个由第一个数字和最后一个数字组成的最小的分数，然后就是精髓所在了，我们此时将分母所在的位置前移一位，还是和当前的分子组成新的分数，这里即为第一个数字和倒数第二个数字组成的分数，存入最小堆中，那么由于之前我们已经将第二个数字和倒数第一个数字组成的分数存入了最小堆，所以不用担心第二小的分数不在堆中，这样每取出一个分数，我们都新加一个稍稍比取出的大一点的分数，这样我们取出了第K个分数即为所求

```cpp
class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    priority_queue<pair<double, pair<int, int>>> q;
    for (int i = 0; i < A.size(); ++i) {
      q.push({-1.0 * A[i] / A.back(), {i, A.size() - 1}});
    }
    while (--K) {
      auto t = q.top().second;
      q.pop();
      --t.second;
      q.push({-1.0 * A[t.first] / A[t.second], {t.first, t.second}});
    }
    return {A[q.top().second.first], A[q.top().second.second]};
  }
};
```

另外一种书写方式：

```cpp
class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    double left = 0, right = 1;
    int p = 0, q = 1, cnt = 0, n = A.size();
    while (true) {
      double mid = left + (right - left) / 2.0;
      cnt = 0;
      p = 0;
      for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && A[i] > mid * A[j]) ++j;
        cnt += n - j;
        if (j < n && p * A[j] < q * A[i]) {
          p = A[i];
          q = A[j];
        }
      }
      if (cnt == K)
        return {p, q};
      else if (cnt < K)
        left = mid;
      else
        right = mid;
    }
  }
};
```