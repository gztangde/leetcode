# Combination

## Leetcode 17. Letter Combinations of a Phone Number

```cpp
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans;
    string cur;
    string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    letterCombinationsDFS(digits, dict, 0, cur, ans);
    return ans;
  }
  void letterCombinationsDFS(const string& digits, string dict[], int index, string& out, vector<string>& ans) {
    if (index == digits.length()) {
      ans.emplace_back(out);
      return;
    }
    for (char c : dict[digits[index] - '0']) {
      out.push_back(c);
      letterCombinationsDFS(digits, dict, index + 1, out, ans);
      out.pop_back();
    }
  }
};
```

## Leetcode 39. Combination Sum

```cpp
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
    for (int i = index; i < candidates.size(); ++i) {
      if (candidates[i] > target) break;
      out.push_back(candidates[i]);
      combinationSumDFS(candidates, target - candidates[i], i, out, ans);
      out.pop_back();
    }
  }
};
```

## Leetcode 77. Combinations

```cpp
// Runtime: 104 ms, faster than 71.52% of C++ online submissions for Combinations.
// Memory Usage: 11.7 MB, less than 100.00% of C++ online submissions for Combinations.
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> out;
    ans.reserve(k);
    combineDFS(n, k, 1, out, ans);
    return ans;
  }

 private:
  void combineDFS(int n, int k, int index, vector<int>& out, vector<vector<int>>& ans) {
    if (k == 0) {
      ans.emplace_back(out);
      return;
    }
    for (int i = index; i <= n; ++i) {
      out.emplace_back(i);
      combineDFS(n, k - 1, i + 1, out, ans);
      out.pop_back();
    }
  }
};
```

## Leetcode 40. Combination Sum II

```cpp
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    vector<int> out;
    combinationSum2DFS(candidates, target, 0, out, ans);
    return ans;
  }

 private:
  void combinationSum2DFS(vector<int>& c, int target, int index, vector<int>& out, vector<vector<int>>& ans) {
    if (target == 0) {
      ans.emplace_back(out);
      return;
    }
    for (int i = index; i < c.size(); ++i) {
      if (i > index && c[i] == c[i - 1]) continue;
      if (c[i] > target) break;
      out.emplace_back(c[i]);
      combinationSum2DFS(c, target - c[i], i + 1, out, ans);
      out.pop_back();
    }
  }
};
```

## Leetcode 216. Combination Sum III

```cpp
class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> out;
    combinationSum3DFS(k, n, 1, out, ans);
    return ans;
  }

 private:
  void combinationSum3DFS(int k, int target, int index, vector<int>& out, vector<vector<int>>& ans) {
    if (out.size() == k) {
      if (target == 0) ans.emplace_back(out);
      return;
    }
    for (int i = index; i < 10; ++i) {
      out.emplace_back(i);
      combinationSum3DFS(k, target - i, i + 1, out, ans);
      out.pop_back();
    }
  }
};
```

## Leetcode 78. Subsets

```cpp
// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Subsets.
// Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Subsets.
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.empty()) return {{}};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> out;
    ans.emplace_back(out);
    subsetsDFS(nums, 0, out, ans);
    return ans;
  }

 private:
  void subsetsDFS(vector<int>& nums, int index, vector<int>& out, vector<vector<int>>& ans) {
    if (index == nums.size()) return;
    for (int i = index; i < nums.size(); ++i) {
      out.emplace_back(nums[i]);
      ans.emplace_back(out);
      subsetsDFS(nums, i + 1, out, ans);
      out.pop_back();
    }
  }
};
```

## Leetcode 90. Subsets II

```cpp
class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    if (nums.empty()) return {{}};
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    vector<int> out;
    ans.emplace_back(out);
    subsetsWithDupDFS(nums, 0, out, ans);
    return ans;
  }
 private:
  void subsetsWithDupDFS(vector<int>& nums, int index, vector<int>& out, vector<vector<int>>& ans) {
    if (index == nums.size()) return;
    for (int i = index; i < nums.size(); ++i) {
      if (i > index && nums[i] == nums[i - 1]) continue;
      out.emplace_back(nums[i]);
      ans.emplace_back(out);
      subsetsWithDupDFS(nums, i + 1, out, ans);
      out.pop_back();
    }
  }
};
```