
# Question

Given an array of integers that is already  **_sorted in ascending order_**, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

**Note:**

- Your returned answers (both index1 and index2) are not zero-based.
- You may assume that each input would have  _exactly_  one solution and you may not use the  _same_  element twice.

**Example:**

> **Input:** numbers = [2,7,11,15], target = 9
> **Output:** [1,2]
> **Explanation:** The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.


----------

# Analyze

这道题目完全可以使用`Two-Sum`的解法代码一模一样的来解决这个题目的: [Two-Sum](../Leetcode-1-Two-Sum/)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int, int> numsMap;
    for (int i = 0; i < numbers.size(); ++i) {
      const int diff = target - numbers[i];
      if (numsMap.find(diff) != numsMap.end())
        return {numsMap[diff] + 1, i + 1};
      numsMap[numbers[i]] = i;
    }
    return {};
  }
};
```

但是这一个题目是排序之后的,所有我们要寻找一些更快捷的方式来解决该题目. 使用二分搜索的方式

---------

# solution

```cpp
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    res.reserve(2);
    for (int i = 0; i < numbers.size(); ++i) {
      int val = target - numbers[i];
      int left = i + 1, right = numbers.size() - 1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (numbers[mid] > val)
          right = mid - 1;
        else if (numbers[mid] < val)
          left = mid + 1;
        else {
          res.emplace_back(i + 1);
          res.emplace_back(mid + 1);
          return res;
        }
      }
    }
    return res;
  }
};
```
