// Runtime: 28 ms, faster than 100.00% of C++ online submissions for Permutations II.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Permutations II.
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    do {
      res.push_back(nums);
    } while (nextPermutation(nums, 0, n - 1));
    return res;
  }

 private:
  bool nextPermutation(vector<int>& v, int left, int right) {
    if (left >= right) return false;

    int i, j;
    i = right - 1;
    while (i >= left && v[i] >= v[i + 1]) {
      --i;
    }
    if (i < left) return false;

    j = right;
    while (v[i] >= v[j]) --j;

    std::swap(v[i], v[j]);
    std::reverse(v.begin() + i + 1, v.begin() + right + 1);
    return true;
  }
};