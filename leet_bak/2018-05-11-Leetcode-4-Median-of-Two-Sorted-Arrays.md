---
title: Leetcode 4. Median of Two Sorted Arrays
date: 2018-05-11 16:26:46
updated: 2018-05-11 16:26:46
categories: Leetcode
tags: Leetcode
---

# Question

There are two sorted arrays nums1 and nums2 of size m and n respectively.  

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:  
> nums1 = [1, 3]    
> nums2 = [2]  
> The median is 2.0  

Example 2:  
> nums1 = [1, 2]  
> nums2 = [3, 4]  
> The median is (2 + 3)/2 = 2.5 

**Difficulty**:Hard
**Category**:Array
****
<!--more-->

----------

# Analyze

The pictures in this post all come from this post: [花花酱 LeetCode 4. Median of Two Sorted Arrays]
(https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/)

There are to sorted arrays. You need to find the median number in these two arrays. How we can choose the method to solve this problem.

The time complexity: O(log(m+n)), So, this time complexity can give us a tips. We need to think about using the `Binary Search` to solve this problem. 

How to use the binary search to do this problem? 

![](/images/in-post/2018-05-11-Leetcode-4-Median-of-Two-Sorted-Arrays/2019-01-17-19-54-23.png)

The median number may in these position in these two arrays. And, we need to cover all conditions as the above picture.

![](/images/in-post/2018-05-11-Leetcode-4-Median-of-Two-Sorted-Arrays/2019-01-17-20-02-29.png)


![](/images/in-post/2018-05-11-Leetcode-4-Median-of-Two-Sorted-Arrays/2019-01-17-20-11-14.png)
-----------

# Solution

**Java Solution:**

```java java
public
class Solution {
 public
  double findMedianSortedArrays(int[] nums1, int[] nums2) {
    int m = nums1.length, n = nums2.length;
    int l = (m + n + 1) >> 1;
    int r = (m + n + 2) >> 1;
    return (getkth(nums1, 0, nums2, 0, l) + getkth(nums1, 0, nums2, 0, r)) / 2.0;
  }

 public
  double getkth(int[] A, int aStart, int[] B, int bStart, in t k) {
    if (aStart == A.length) return B[bStart + k - 1];
    if (bStart == B.length) return A[aStart + k - 1];
    if (k == 1) return Math.min(A[aStart], B[bStart]);
    int aMid = Integer.MAX_VALUE, bMid = Integer.MAX_VALUE;
    if (aStart + k / 2 - 1 < A.length) aMid = A[aStart + k / 2 - 1];
    if (bStart + k / 2 - 1 < B.length) bMid = B[bStart + k / 2 - 1];
    if (aMid < bMid)
      return getkth(A, aStart + k / 2, B, bStart, k - k / 2);
    else
      return getkth(A, aStart, B, bStart + k / 2, k - k / 2);
  }
}
```

**C++ Solution 1**

```cpp
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size();

    if (total % 2 == 1) {
      return findMedianth(nums1, 0, nums2, 0, total / 2 + 1);
    } else {
      return (findMedianth(nums1, 0, nums2, 0, total / 2) +
              findMedianth(nums1, 0, nums2, 0, total / 2 + 1)) /
             2;
    }
  }

  double findMedianth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
    if (nums1.size() - i > nums2.size() - j)
      return findMedianth(nums2, j, nums1, i, k);
    if (nums1.size() == i) return nums2[j + k - 1];

    if (k == 1) return min(nums1[i], nums2[j]);

    int point_1 = min(int(nums1.size()), i + k / 2);
    int point_2 = j + k - point_1 + i;

    if (nums1[point_1 - 1] < nums2[point_2 - 1])
      return findMedianth(nums1, point_1, nums2, j, k - (point_1 - i));
    else if (nums1[point_1 - 1] > nums2[point_2 - 1])
      return findMedianth(nums1, i, nums2, point_2, k - (point_2 - j));
    else
      return nums1[point_1 - 1];
  }
};
```

**Solution 2: Binary Search**

```cpp
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int n1 = nums1.size(), n2 = nums2.size();
    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

    const int k = (n1 + n2 + 1) / 2;

    int left = 0, right = n1;
    while (left < right) {
      const int m1 = left + (right - left) / 2;
      const int m2 = k - m1;
      nums1[m1] < nums2[m2 - 1] ? left = m1 + 1 : right = m1;
    }

    const int m1 = left, m2 = k - left;

    const int center1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1], m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
    if ((n1 + n2) % 2 == 1) return center1;
    const int center2 = min(m1 >= n1 ? INT_MAX : nums1[m1], m2 >= n2 ? INT_MAX : nums2[m2]);
    return (center1 + center2) * 0.5;
  }
};
```