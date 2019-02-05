class Solution {
public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<int> ans;
    vector<pair<int, int>> v;
    unordered_map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; ++i) 
      for (int& num : nums[i])
        v.push_back({num, i});

    sort(v.begin(), v.end());
    int left = 0, len = v.size(), cnt = 0, diff = INT_MAX;
    for (int right = 0; right < len; ++right) {
      pair<int, int> r_num = v[right], l_num = v[left];
      if (m[r_num.second] == 0) cnt++;
      ++m[r_num.second];
      
      while(cnt == n && left <= right) {
        r_num = v[right];
        l_num = v[left];
        if (diff > r_num.first - l_num.first) {
          diff = r_num.first - l_num.first;
          ans = {l_num.first, r_num.first};
        }
        if(--m[l_num.second] == 0) --cnt;
        ++left;
      }
    }
    return ans;
  }
};
