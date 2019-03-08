---
title: Leetcode 215. Kth Largest Element in an Array
date: 2019-01-31 16:33:40
updated: 2019-01-31 16:33:40
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Find the  **k**th largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

**Example 1:**

> **Input:** `[3,2,1,5,6,4]` and k = 2
> **Output:** 5

**Example 2:**

> **Input:** `[3,2,3,1,2,4,5,5,6]` and k = 4
> **Output:** 4

**Note:**  
You may assume k is always valid, 1 ≤ k ≤ array's length.

**Difficulty**:Medium

**Category**:

<!-- more -->

------------

# Analyze

这道题目是要求找到 k-th Largest Element in An Array, 可以考虑使用堆排序. Leetcode Discuss: [C++ STL, partition and heapsort](https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort)

# Solution

## Solution 1: Sort

时间复杂度 $O(n log n)$, 空间复杂度 $O(1)$

```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};
```

## Solution 2: Heap Sort

排序 ：时间复杂度 O(nlog n)，空间复杂度 O(N)

```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> p;
    for (int& i : nums) p.push(i);
    while (--k) p.pop();
    return p.top();
  }
};
```

稍作修改:

**Max-heap -- Using Priority_queue**

```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    while (--k) p.pop();
    return pq.top();
  }
};
```

**min-heap using priority_queue**

```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int num : nums) {
      pq.push(num);
      if (pq.size() > k) {
        pq.pop();
      }
    }
    return pq.top();
  }
};
```

**min-heap using multiset**

```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    multiset<int> mset;
    for (int num : nums) {
      mset.insert(num);
      if (mset.size() > k) {
        mset.erase(mset.begin());
      }
    }
    return *mset.begin();
  }
};
```

**max-heap using multiset**

```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    multiset<int, greater<int>> mset(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; i++) {
      mset.erase(mset.begin());
    }
    return *mset.begin();
  }
};
```

## Solution 3: Heap Sort

排序 ：时间复杂度 O(nlog n)，空间复杂度 O(N)

```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> p;
    for (int& i : nums) p.push(i);
    while (--k) p.pop();
    return p.top();
  }
};
```

## Solution 3: QuickSort

```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    k = nums.size() - k;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int temp = quick_sort(nums, left, right);
      if (temp == k)
        break;
      else if (temp < k) {
        left = temp + 1;
      } else {
        right = temp - 1;
      }
    }
    return nums[k];
  }

 private:
  int quick_sort(vector<int>& nums, int b, int e) {
    if (b < e) {
      int lb = b, rb = e;
      while (lb < rb) {
        while (nums[rb] >= nums[b] && lb < rb) rb--;
        while (nums[lb] <= nums[b] && lb < rb) lb++;
        swap(nums[lb], nums[rb]);
      }
      swap(nums[b], nums[lb]);
      return rb;
    }
    return 0;
  }
};
```

<!-- TODO: STL Function -->

## Use STL Function:

```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
    return nums[k - 1];
  }
};
```

```cpp
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
    return nums[k - 1];
  }
};
```