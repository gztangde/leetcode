class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<int> ans;
    vector<pair<int, int>> v;
    unordered_map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
      for (int& num : nums[i]) v.push_back({num, i});

    sort(v.begin(), v.end());
    int left = 0, len = v.size(), cnt = 0, diff = INT_MAX;
    for (int right = 0; right < len; ++right) {
      if (m[v[right].second] == 0) cnt++;
      ++m[v[right].second];

      while (cnt == n && left <= right) {
        if (diff > v[right].first - v[left].first) {
          diff = v[right].first - v[left].first;
          ans = {v[left].first, v[right].first};
        }
        if (--m[v[left].second] == 0) --cnt;
        ++left;
      }
    }
    return ans;
  }
};
