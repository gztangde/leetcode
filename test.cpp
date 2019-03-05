class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p = m - 1, q = n - 1, merge = m + n - 1;
    while (p >= 0 && q >= 0) nums1[merge--] = nums1[p] >= nums2[q] ? nums1[p--] : nums2[q--];
    // If the p == 0
    while (q >= 0) nums1[merge--] = nums2[q--];
  }
};