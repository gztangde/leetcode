---
title: Highest Five
date: 2019-03-08 23:29:33
updated: 2019-03-08 23:29:33
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Higest Five

**Description**  
There are two properties in the node student id and scores, to ensure that each student will have at least 5 points, find the average of 5 highest scores for each person.  

**Example**  
Given results = [[1,91],[1,92],[2,93],[2,99],[2,98],[2,97],[1,60],[1,58],[2,100],[1,61]]  
  
Return:
  
# Analyze

根据题意，对于每一个id，我们维护一个大小为K的min-heap。一个一个把Record放进去，如果容量超了，就把最小的踢掉。这样heap里永远是最大的K个。  
全部放完以后，对于每一个id，我们把heap里的Record拿出来算一下平均数。(用 `unordered_map<int, priority_queue<double>>` 储存数据，其中的min heap优先队列保持size为5，然后对各自的top 5求平均值)

# Solution

```cpp
/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
class Solution {
 public:
  map<int, double> highFive(vector<Record>& results) {
    int len = results.size();

    map<int, priority_queue<int, vector<int>, greater<int>>> mp;  // id, min-heap
    map<int, double> result;
    // Save all the points for each student
    for (int i = 0; i < len; ++i) {
      int studentId = results[i].id;
      int studentScore = results[i].score;
      mp[studentId].push(studentScore);
      if (mp[studentId].size() > 5) mp[studentId].pop();
    }
  
    // 分别处理每一个学生的成绩
    for (auto m : mp) {
      double sum = 0;
      while (m.second.size() > 0) {
        sum += m.second.top();
        m.second.pop();
      }
      result[m.first] = sum / 5;  // strictly speacking, it needs to check if the student has >= 5 courses
    }
    return result;
  }
};
]
```