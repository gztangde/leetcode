class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
    return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
  }
  int rob(vector<int>& nums, int left, int right) {
    int rob = 0, notRob = 0;
    for (int i = left; i < right; ++i) {
      int preRob = rob, preNotRob = notRob;
      rob = preNotRob + nums[i];
      notRob = max(preRob, preNotRob);
    }
    return max(rob, notRob);
  }
};