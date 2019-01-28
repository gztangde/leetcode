
# Question

Given an array of integers, 1 ≤ a[i] ≤  _n_  (_n_  = size of array), some elements appear  **twice**  and others appear  **once**.

Find all the elements that appear  **twice**  in this array.

Could you do it without extra space and in O(_n_) runtime?

**Example:**  

> **Input:**
> [4,3,2,7,8,2,3,1]
> **Output:**
> [2,3]

**Difficulty**:Medium
**Category**:Array


------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    vec_sort(nums);

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) res.emplace_back(nums[i]);
    }

    return res;
  }

  void vec_sort(vector<int>& nums) {
    // Build a array to store the numsbers
    const unsigned int len_n = nums.size();
    for (int i = 0; i < len_n; ++i) {
      while (nums[i] != i + 1) {
        if (nums[i] <= 0 || nums[i] > len_n || nums[i] == nums[nums[i] - 1]) break;
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
  }
};

```

# Similar Questions

2018-12-17-Leetcode-448-Find-All-Numbers-Disappeared-In-An-Array
2018-12-16-Leetcode-41-First-Missing-Positive
