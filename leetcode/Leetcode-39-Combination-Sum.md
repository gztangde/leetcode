---
title: Leetcode 39. Combination Sum
date: 2018-10-31 20:09:31
updated: 2018-10-31 20:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a  **set**  of candidate numbers (`candidates`)  **(without duplicates)**  and a target number (`target`), find all unique combinations in  `candidates` where the candidate numbers sums to  `target`.

The  **same**  repeated number may be chosen from  `candidates` unlimited number of times.

**Note:**

- All numbers (including  `target`) will be positive integers.
- The solution set must not contain duplicate combinations.

**Example 1:**

**Input:** candidates = `[2,3,6,7],` target = `7`,
**A solution set is:**
[
  [7],
  [2,2,3]
]

**Example 2:**

**Input:** candidates = [2,3,5]`,` target = 8,
**A solution set is:**
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

<!-- more -->

---------------

# Solution 

```cpp
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    findcombinationSum(candidates, target, 0, temp, res);
    return res;
  }

  void findcombinationSum(vector<int>& candidates, int target, int index,
                          vector<int>& temp, vector<vector<int>>& res) {
    if (target < 0) return;
    if (target == 0) res.emplace_back(temp);
    for (int i = index; i < candidates.size(); ++i) {
      temp.emplace_back(candidates[i]);
      findcombinationSum(candidates, target - candidates[i], i, temp, res);
      temp.pop_back();
    }
  }
};
```

## Solution 1: DFS

这种解法的难点在于要保证没有重复数据的情况出现, 这就要求, 不能有后面的数字又重新来前面的数据来计算和的情况.

```cpp
// Runtime: 20 ms, faster than 75.37% of C++ online submissions for Combination Sum.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Combination Sum.
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if (candidates.empty()) return {{}};
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> out;
    combinationSumDFS(candidates, target, 0, out, ans);
    return ans;
  }
  void combinationSumDFS(vector<int>& candidates, int target, int index, vector<int>& out, vector<vector<int>>& ans) {
    if (target == 0) {
      ans.emplace_back(out);
      return;
    }
    if (target < 0) return;
    for (int i = index; i < candidates.size(); ++i) {
      int x = candidates[i];
      out.push_back(x);
      combinationSumDFS(candidates, target - x, i, out, ans);
      out.pop_back();
    }
  }
};
```

这道题目也可以不先排序也是可以的的, 能够得到一样的结果

```cpp
// Runtime: 20 ms, faster than 75.37% of C++ online submissions for Combination Sum.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Combination Sum.
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if (candidates.empty()) return {{}};
    vector<vector<int>> ans;
    vector<int> out;
    combinationSumDFS(candidates, target, 0, out, ans);
    return ans;
  }
  void combinationSumDFS(vector<int>& candidates, int target, int index, vector<int>& out, vector<vector<int>>& ans) {
    if (target == 0) {
      ans.emplace_back(out);
      return;
    }
    if (target < 0) return;
    for (int i = index; i < candidates.size(); ++i) {
      int x = candidates[i];
      out.push_back(x);
      combinationSumDFS(candidates, target - x, i, out, ans);
      out.pop_back();
    }
  }
};
```

在循环计算的时候可以换一种处理方式

```cpp
for (int i = index; i < candidates.size(); ++i) {
  if (candidates[i] > target) break;
  out.push_back(candidates[i]);
  combinationSumDFS(candidates, target - candidates[i], i, out, ans);
  out.pop_back();
}
```

## updated

* 03/01/2019 Review (BFS: 8mins)