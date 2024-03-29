---
title: Leetcode 981. Time Based Key Value Store
date: 2019-03-09 11:37:27
updated: 2019-03-09 11:37:27
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Leetcode 981. Time Based Key Value Store

Create a timebased key-value store class `TimeMap`, that supports two operations.

1.  `set(string key, string value, int timestamp)`

-   Stores the  `key`  and  `value`, along with the given  `timestamp`.

2.  `get(string key, int timestamp)`

-   Returns a value such that  `set(key, value, timestamp_prev)`  was called previously, with  `timestamp_prev <= timestamp`.
-   If there are multiple such values, it returns the one with the largest  `timestamp_prev`.
-   If there are no values, it returns the empty string (`""`).

**Example 1:**

**Input:** inputs = ["TimeMap","set","get","get","set","get","get"], inputs = [[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]
**Output:** [null,null,"bar","bar",null,"bar2","bar2"]
**Explanation: **TimeMap kv;   
kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1   
kv.get("foo", 1);  // output "bar"   
kv.get("foo", 3); // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar"   
kv.set("foo", "bar2", 4);   
kv.get("foo", 4); // output "bar2"   
kv.get("foo", 5); //output "bar2" 

**Example 2:**

**Input:** inputs = ["TimeMap","set","set","get","get","get","get","get"], inputs = [[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]
**Output:** [null,null,null,"","high","high","low","low"]

**Note:**

1.  All key/value strings are lowercase.
2.  All key/value strings have length in the range `[1, 100]`
3.  The  `timestamps`  for all  `TimeMap.set`  operations are strictly increasing.
4.  `1 <= timestamp <= 10^7`
5.  `TimeMap.set`  and  `TimeMap.get` functions will be called a total of  `120000`times (combined) per test case.

**Difficulty**:Medium

**Category**:

# Analyze


# Solution

## Solution: HashTable + Map

```cpp
class TimeMap {
public:
  /** Initialize your data structure here. */
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    s_[key].emplace(timestamp, std::move(value));
  }

  string get(string key, int timestamp) {
    auto m = s_.find(key);
    if (m == s_.end()) return "";
    auto it = m->second.upper_bound(timestamp);
    if (it == begin(m->second)) return "";
    return prev(it)->second;
  }
private:
  unordered_map<string, map<int, string>> s_; 
};
```