
# Question
Given an array  _nums_  containing  _n_  + 1 integers where each integer is between 1 and  _n_  (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

**Example 1:**

**Input:** `[1,3,4,2,2]`
**Output:** 2

**Example 2:**

**Input:** [3,1,3,4,2]
**Output:** 3

**Note:**

1. You  **must not**  modify the array (assume the array is read only).
2. You must use only constant,  _O_(1) extra space.
3. Your runtime complexity should be less than  _O_(_n_2).
4. There is only one duplicate number in the array, but it could be repeated more than once.

**Difficulty**:Medium
**Category**:


------------

# Analyze

------------

# Solution

双指针的解法


```cpp
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    while (true) {
      // Each step: the slow point move one step
      // Each step: the fast point move two steps
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast) break;
    }
    fast = 0;
    while (fast != slow) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};

```

