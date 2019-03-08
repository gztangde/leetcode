---
title: Leetcode Input Size Vs. Time Complexity
date: 2019-01-17 19:09:09
updated: 2019-01-17 19:09:09
categories: 
- [Notes]
tags: Node
notshow: true
mathjax: true
top:
---

当我们在处理Leetcode的问题的时候,没有思路的时候,我们应该考虑使用其他的的一些条件缩小我们方法的选择区间. 在这部分, 分析如果根据题目中给定的`input size` 和 `Time Complexity` 来缩小一些选择区间, 估计使用的算法.

<!-- more -->

# 为什么我们可以使用Input Size 和Time Complexity来选择算法呢?

![](/images/in-post/2019-01-17-Leetcode-How-to-choose-a-good-method/2019-01-17-19-14-10.png)

我们在使用过程中会使用到一些数据结构,所以我们在使用过程中,我们对输入的数据结构大小是有一些要求的. 一个 O($n^2$), 输入数据是1000的话,差不多这就是图中的速度. 这就有这下面几种方案
- 如果数据规模是100, 那么就可以使用 $n^3$, 但是 $n ^ 4$ 可能就不可以的.
- 如果数据规模是1000, 那么就可以使用 $n^2$, 但是 $n ^ 3$ 可能就不可以的.

**在做题的过程中,先保证自己的算法是正确的,如果超时的话,再想办法进行优化处理(很多时候搜索能够解决大部分问题,但是优化的时候在考虑动态规划之内的方式处理)**


![](/images/in-post/2019-01-17-Leetcode-How-to-choose-a-good-method/2019-01-17-19-30-16.png)

The above picture shows how we can choose the way for the leetcode questions.


| Input Data Size | Time Complexity(We can Choose) | Tips                                        | Used                      |
| --------------- | ------------------------------ | ------------------------------------------- | ------------------------- |
| 1 - 10          | O(n!)                          | Permutation                                 | 排列(Search, DFS生成)     |
| 1 - 20          | O(2^n)                         | Combination                                 | 组合(Search, DFS生成 )    |
| 10 - 50         | O(n^4)                         | DP, 图                                      |
| 1 - 200         | O(n^3)                         | DP, 图                                      |
| 1000 -  2000    | O(n^2)                         | DP, 图                                      |
| 1.000.000       | O(n*log n)                     | Sorting Based(归例), heap, divide & conquer |
| 1.000.000.0     | O(n)                           | DP, Graph Traversal / Topological sorting   | 常用                      |
| 2^32            | O(sqrt(n))                     | 判断素数,平方和                             | 不常见                    |
| 2^32            | O(log n)                       | Binary Search                               |
| 2^32            | O(1)                           | Math                                        | 一般是有规律,归纳得到结果 |
   