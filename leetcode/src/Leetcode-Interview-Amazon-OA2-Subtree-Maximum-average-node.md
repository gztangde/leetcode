---
title: Subtree-Maximum average node
date: 2019-03-08 23:55:08
updated: 2019-03-08 23:55:08
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Subtree: Maximum average node

两个版本的情况，可能是二叉树，也可能是多子节点的情况。我之前看到过这个题型的两种版本，一种是二叉树的，一种则是有多个子节点的。很不幸我遇到的是后者，为什么说不幸呢，且听我娓娓道来。
要注意我用的语言是C++，所以题目里对CategoryNode类的描述和截图里稍有不同。坑爹的是出题人写错了。。TA把成员变量subCategoryNode的类型写成了vector<CategoryNode>（经事实证明应该是vector<CategoryNode*>），直接导致了我编译一直没通过。等到我捣鼓了半天终于编译过了发现结果不对，时间只剩3分钟的我脑袋炸裂，并没能奇迹般的找出bug来。
解答看这里：https://www.1point3acres.com/bbs ... read&tid=478916
（另外OA要求那里好像有说不能用global以及static变量，所以我把res作为了helper的实参）

需要注意的是返回的必须是内部节点

general tree, leaves not counted), return tree node

![](images/2019-02-28-17-43-50.png)

## Find substrings of size k with k-1 distinct characters

K-1 distinct subarray with length K

多差树 找最大平均的TreeNode 不包括叶子  

变形题：  
Number of substrings containing K distinct characters，返回满足条件的子串个数  
-corner case：K=0时，返回0  
-注意相同的子串只算一次，所以用unordered_set来记录符合条件的子串，可以达到除重的目的  
  
**若要求子串长度为K：**

-可以考虑用双指针来模拟大小为k的窗口，用一个unordered_map来存窗口内的，移动时把左指针所指的字符在map中—，若等于0则从map中删去该项；而右指针所指的新字符则在map中++（或新建），若map.size等于k则说明该子串符合条件，否则不符合条件。  
-时间复杂度为O(n+mk)其中n为大字符串的长度，m为符合条件的子串数目（mk是取substr的开销）  
  
**若子串长度没有限制：**

-举例来说，“aba”的k=2的子串有“ab”、“aba”，亦即要求有k种字母，而单种字母是可以出现多次的  
-用两重循环的方法，对每个左指针i，右指针j从i开始一直移动到n-1，此过程中维护一个hashmap。若hashmap的size为k，则将该子串加入到结果中  
-时间复杂度是O(n^2)。如果相同子串只算一次的话，需要用unordered_set来存结果。需要注意的是每一层i循环中移动指针j的时候也需要维护一个[i,j]的子串，这样当符合条件时就不需要调用substr产生额外的开销了

**find substrings of size k with k-1 distinct characters，返回满足条件的子串个数**

-与上题算法的区别：判断条件从map.size==k 改为 `map.size == k - 1`
