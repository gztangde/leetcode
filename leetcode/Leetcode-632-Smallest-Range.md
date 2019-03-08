---
title: Leetcode 632. Smallest Range
date: 2019-02-05 10:50:50
updated: 2019-02-05 10:50:50
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

You have  `k`  lists of sorted integers in ascending order. Find the  **smallest**  range that includes at least one number from each of the  `k`  lists.

We define the range [a,b] is smaller than range [c,d] if  `b-a < d-c`  or  `a < c`  if  `b-a == d-c`.

**Example 1:**  

**Input:**[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]

**Output:** [20,24]

**Explanation:** 

List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

**Note:**  

1. The given list may contain duplicates, so ascending order means >= here.
2. 1 <=  `k`  <= 3500
3. -105  <=  `value of elements`  <= 105.
4. **For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.**

**Difficulty**:Hard

**Category**:Hash-Table, Two-Points, String

<!-- more -->

# Analyze

输入是一些数组, 都是排好序的, 我们需要找到一个最小的数据范围, 使得这个范围至少能够包括每个数组中的一个数字. 我们可以考虑按照以下方式进行处理:

* 將这些数组合并成为一个大的数组并且保留其序号, 使用`vector<pair<int, int>>`, 然后排序.
* 这样等同于, 我们`找到一个最小的窗口`, 然后这个窗口里面要同时包含所有数组中的至少一个数字.

我们用两个指针 `left` 和 `right` 来确定滑动窗口的范围，我们还要用一个哈希表来建立每个数组与其数组中数字出现的个数之间的映射，变量cnt表示当前窗口中的数字覆盖了几个数组，diff为窗口的大小，我们让right向右滑动，然后判断如果right指向的数字所在数组没有被覆盖到，cnt自增1，然后哈希表中对应的数组出现次数自增1，然后我们循环判断如果cnt此时为k(数组的个数)且left不大于right，那么我们用当前窗口的范围来更新结果，然后此时我们想缩小窗口，通过将left向右移，移动之前需要减小哈希表中的映射值，因为我们去除了数字，如果此时映射值为0了，说明我们有个数组无法覆盖到了，cnt就要自减1。这样遍历后我们就能得到最小的范围了

# Solution

```cpp
class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<int> ans;
    vector<pair<int, int>> v;
    unordered_map<int, int> m;
    int n = nums.size();
    // Merge all array in one vector, and save the index in the vector
    for (int i = 0; i < n; ++i)
      for (int& num : nums[i]) v.push_back({num, i});

    // Sort the array by the first val in the pair.
    sort(v.begin(), v.end());

    // Find the smallest window which include at least one number from each array.
    int left = 0, len = v.size(), cnt = 0, diff = INT_MAX;
    for (int right = 0; right < len; ++right) {
      if (m[v[right].second] == 0) cnt++;
      ++m[v[right].second];

      // If there are n array's element in this big array.
      while (cnt == n && left <= right) {
        if (diff > v[right].first - v[left].first) {
          diff = v[right].first - v[left].first;
          ans = {v[left].first, v[right].first};
        }
        if (--m[v[left].second] == 0) --cnt;
        ++left;
      }
    }
    return ans;
  }
};
```

* [Leetcode 76. Minimum Window Substring](./Leetcode-76-Minimum-Window-Substring/)