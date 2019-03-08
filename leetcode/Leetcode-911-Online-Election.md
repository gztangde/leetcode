---
title: Leetcode 911. Online Election
date: 2019-01-19 15:39:45
updated: 2019-01-19 15:39:45
categories: 
- [Leetcode]
- [Leetcode, Binary-Search]
tags: Leetcode
notshow: true
top:
---

# Question

In an election, the  `i`-th vote was cast for  `persons[i]`  at time  `times[i]`.

Now, we would like to implement the following query function:  `TopVotedCandidate.q(int t)`  will return the number of the person that was leading the election at time  `t`.

Votes cast at time  `t`  will count towards our query. In the case of a tie, the most recent vote (among tied candidates) wins.

**Example 1:**

> **Input:** ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
> **Output:** [null,0,1,1,0,0,1]
> **Explanation:** 
> At time 3, the votes are [0], and 0 is leading.
> At time 12, the votes are [0,1,1], and 1 is leading.
> At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
> This continues for 3 more queries at time 15, 24, and 8.

**Note:**

1. `1 <= persons.length = times.length <= 5000`
2. `0 <= persons[i] <= persons.length`
3. `times` is a strictly increasing array with all elements in  `[0, 10^9]`.
4. `TopVotedCandidate.q`  is called at most  `10000`  times per test case.
5. `TopVotedCandidate.q(int t)`  is always called with  `t >= times[0]`.

**Difficulty**:Medium

**Category**:Binary-Search

<!-- more -->

------------

# Analyze

**Understand Question**
一次选举中,在`time[i]`的时候会投票给`person[i]`,然后求在`t`时刻得票最多的候选人. 如果存在票数相等的情况,就选择最新获得投票的候选人.

# Solution

```cpp
// Time complexity: Constructor O(n), Query: O(logn)
// Space complexity: O(n)
class TopVotedCandidate {
 public:
  // the i-th person at the times[i] time vote the person[i]
  TopVotedCandidate(vector<int> persons, vector<int> times) {
    vector<int> votes(persons.size() + 1, 0);
    int last_lead = persons.front();
    for (int i = 0; i < persons.size(); ++i) {
      if (++votes[persons[i]] >= votes[last_lead]) last_lead = persons[i];
      // The i-th vote at time times[i]
      lead_[times[i]] = last_lead;
    }
  }

  int q(int t) { return prev(lead_.upper_bound(t))->second; }

 private:
  // time -> leader (IN this time, who lead this vote)
  map<int, int> lead_;
};
```


