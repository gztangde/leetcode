---
title: Leetcode 15. 3Sum
date: 2018-05-12 01:30:32
updated: 2018-05-12 01:30:32
categories: Leetcode
tags: Leetcode
---

# 3Sum

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.  
Note: The solution set must not contain duplicate triplets.  
> For example, given array S = [-1, 0, 1, 2, -1, -4],  
> A solution set is:  
> [ [-1, 0, 1],  
>  [-1, -1, 2]] 

**Difficulty**:Easy

**Category**:Array

***

## Solution

### 思路1：夹逼法(时间复杂度O(n^2))

先排序，然后查每一个数后面两数之和为当前数相反数的所有可能。

### 思路2（未实现）
不排序，先做2数和的倒排索引，查每一个数是否有相应的2数和为其相反数。O(n^3)

<!--more-->
Solution 1: 
> **补充知识：**  
> [ArrayList in Java](https://www.geeksforgeeks.org/arraylist-in-java/)

需要处理数组长度小于 3 的边界情况。

```cpp
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.size() < 3) return ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
      if (nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int left = i + 1, right = nums.size() - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
          ans.push_back({nums[i], nums[left++], nums[right--]});
          while (left < right && nums[left] == nums[left - 1]) ++left;
          while (left < right && nums[right] == nums[right + 1]) --right;
        } else if (sum > 0) {
          --right;
        } else {
          ++left;
        }
      }
    }
    return ans;
  }
};
```

思路:求三数之和，比之前那道Two Sum要复杂一些

1. 先Fix一个数，然后另外两个数使用Two Sum那种HashMap的解法，但是会有重复结果出现，就算使用set来去除重复也不行，会TLE，看来此题并不是考我们Two Sum的解法。  

2. 那么我们来分析一下这道题的特点，要我们找出三个数且和为0，那么除了三个数全是0的情况之外，肯定会有负数和正数。
> 先fix一个数，然后去找另外两个数，我们只要找到两个数且和为第一个fix数的相反数就行了，既然另外两个数不能使用Two Sum的那种解法来找，如果能更有效的定位呢？我们肯定不希望遍历所有两个数的组合吧，所以如果数组是有序的，那么我们就可以用双指针以线性时间复杂度来遍历所有满足题意的两个数组合。  

## 思路1： 
我们对原数组进行排序，然后开始遍历排序后的数组，这里注意不是遍历到最后一个停止，而是到倒数第三个就可以了。这里我们可以优化一下：      
- 就是当遍历到正数的时候就break，为啥呢，因为我们的数组现在是有序的了，如果第一个要fix的数就是正数了，那么后面的数字就都是正数，就永远不会出现和为0的情况了。  

- 然后我们还要加上重复就跳过的处理，处理方法是从第二个数开始，如果和前面的数字相等，就跳过，因为我们不想把相同的数字fix两次。对于遍历到的数，用0减去这个fix的数得到一个target，然后只需要再之后找到两个数之和等于target即可。  

- 我们用两个指针分别指向fix数字之后开始的数组首尾两个数，如果两个数和正好为target，则将这两个数和fix的数一起存入结果中。然后就是跳过重复数字的步骤了，两个指针都需要检测重复数字。如果两数之和小于target，则我们将左边那个指针i右移一位，使得指向的数字增大一些。同理，如果两数之和大于target，则我们将右边那个指针j左移一位，使得指向的数字减小一些，代码如下：


# Solution

先排序,然后左右夹逼, 跳过重复的数据, 时间复杂度O(n^2), 空间复杂度 O(1)

```cpp
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int k = 0; k < nums.size(); ++k) {
      if (nums[k] > 0) break;
      int target = 0 - nums[k];
      int i = k + 1, j = nums.size() - 1;
      while (i < j) {
        if (nums[i] + nums[j] == target) {
          res.insert({nums[k], nums[i], nums[j]});
          while (i < j && nums[i] == nums[i + 1]) ++i;
          while (i < j && nums[j] == nums[j - 1]) --j;
          ++i;
          --j;
        } else if (nums[i] + nums[j] < target)
          ++i;
        else
          --j;
      }
    }
    return vector<vector<int>>(res.begin(), res.end());
  }
};
```