class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p_a = m - 1, p_b = n - 1, p_merge = m + n - 1;
    while (p_a >= 0 && p_b >= 0) nums1[p_merge--] = nums1[p_a] >= nums2[p_b] ? nums1[p_a--] : nums2[p_b--];

    while (p_b >= 0) nums1[p_merge--] = nums2[p_b--];
  }
};