---
title: Leetcode 378. Kth Smallest Element in a Sorted Matrix
date: 2019-01-19 17:39:40
updated: 2019-01-19 17:39:40
categories: 
- [Leetcode]
- [Leetcode, Binary-Search]
- [Leetcode, Heap]
tags: Leetcode
notshow: true
top:
---

# Leetcode 378. Kth Smallest Element in a Sorted Matrix

Given a  _n_  x  _n_  matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

**Example:**

```
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
```

**Note:**  
You may assume k is always valid, 1 ≤ k ≤ n2.

**Difficulty**:Medium

**Category**:Binary-Search, Heap

<!-- more -->

# Solution

Cite:[Kth Smallest Element in a Sorted Matrix 有序矩阵中第K小的元素](http://www.cnblogs.com/grandyang/p/5727892.html)

求有序矩阵中第K小的元素. 这道题中的矩阵并不是完全有序的，行之间可能并不有序，所以是当前行的最后一个元素并不一定会小于下一行的首元素。这就不能够简单的利用二叉搜索来求解了。但是可以使用变化的二叉搜索来求解。

由于矩阵左上角的数字一定是最小的，而右下角的数字一定是最大的，所以这个是我们搜索的范围，然后我们算出中间数字mid，由于矩阵中不同行之间的元素并不是严格有序的，所以我们要在每一行都查找一下mid，我们使用upper_bound，这个函数是查找第一个大于目标数的元素，如果目标数在比该行的尾元素大，则upper_bound返回该行元素的个数，如果目标数比该行首元素小，则upper_bound返回0, 我们遍历完所有的行可以找出中间数是第几小的数，然后k比较，进行二分查找，left和right最终会相等，并且会变成数组中第k小的数字

## Solution 1: Binary Search

Time complexity: O(n log(n) * log(max – min)), Space complexity: O(1)

```cpp
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int row = matrix.size(), col = matrix[0].size();
    int left = matrix[0][0], right = matrix[matrix.size() - 1][matrix[0].size() - 1] + 1;

    while (left < right) {
      int mid = left + (right - left) / 2;
      int cnt = 0;
      for (auto& x : matrix) {
        cnt += upper_bound(x, mid);
      }
      if (cnt < k) left = mid + 1;
      else right = mid;
    }
    return left;
  }

 private:
  int upper_bound(vector<int>& A, int val) {
    int l = 0, r = A.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      A[m] > val ? r = m : l = m + 1;
    }
    return l;
  }
};
```

在上面的代码里面，我们可以考虑使用`STL`提供的`upper_bound`函数，而不是自己去写。

```cpp
cnt += upper_bound(x.begin(), x.end(), mid) - x.begin();
或：
cnt += (s = distance(begin(x), upper_bound(begin(x), begin(x) + s, mid)));
```

优化：Time complexity: O(n log(max – min)), Space complexity: O(1)

我们并不用对每一行都做二分搜索法, 每列是有序的，我们可以利用这个性质，从数组的左下角开始查找，如果比目标值小，我们就向右移一位，而且我们知道当前列的当前位置的上面所有的数字都小于目标值，那么cnt += i+1，反之则向上移一位，这样我们也能算出cnt的值。其余部分跟上面的方法相同

```cpp
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int left = matrix[0][0], right = matrix.back().back();
    while (left < right) {
      int mid = left + (right - left) / 2;
      int cnt = search_less_equal(matrix, mid);
      if (cnt < k)
        left = mid + 1;
      else
        right = mid;
    }
    return left;
  }

  int search_less_equal(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), i = n - 1, j = 0, res = 0;
    while (i >= 0 && j < n) {
      if (matrix[i][j] <= target) {
        res += i + 1;
        ++j;
      } else {
        --i;
      }
    }
    return res;
  }
};
```

## Solution 2: Priority_Queue

我们使用一个最大堆，然后遍历数组每一个元素，将其加入堆，根据最大堆的性质，大的元素会排到最前面，然后我们看当前堆中的元素个数是否大于k，大于的话就将首元素去掉，循环结束后我们返回堆中的首元素即为所求.

Time complexity: O(m * n * log(m*n))
Space complexity: O(m * n)

```cpp
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> q;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        q.emplace(matrix[i][j]);
        if (q.size() > k) q.pop();
      }
    }
    return q.top();
  }
};
```