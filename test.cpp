class Solution {
 public:
  string shortestSuperstring(vector<string>& A) {
    const int n = A.size();

    // 预处理阶段： 计算將单词 j 接到单词  i 后面的最小 Cost 是多少
    g_ = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        g_[i][j] = A[j].length();
        for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k)
          if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) 
            g_[i][j] = A[j].length() - k; // g_[i][j]表示將单词 j 放在 i后面
      }
    vector<int> path(n); // 当前的路径---各个单词的 index
    best_len_ = INT_MAX;
    dfs(A, 0, 0, 0, path);

    string ans = A[best_path_[0]];
    for (int k = 1; k < best_path_.size(); ++k) {
      int i = best_path_[k - 1];
      int j = best_path_[k];
      ans += A[j].substr(A[j].length() - g_[i][j]);
    }
    return ans;
  }

 private:
  vector<vector<int>> g_;  //预处理
  vector<int> best_path_;
  int best_len_;
  // d: 当前搜素的深度， uesd: 表示那些单词已经被使用了， cur_len 当前路径所有单词的长度和
  void dfs(const vector<string>& A, int d, int used, int cur_len, vector<int>& path) {
    // 剪枝处理
    if (cur_len >= best_len_) return;
    if (d == A.size()) { // 表示所有的单词已经全部使用过了， 当前最优解
      best_len_ = cur_len;
      best_path_ = path;
      return;
    }

    for (int i = 0; i < A.size(); ++i) {
      if (used & (1 << i)) continue; // 判断当前单词是否已经使用过了
      path[d] = i; // 表示第 d 步使用的是 A[i] 这个单词
      dfs(A, d + 1, used | (1 << i), d == 0 ? A[i].length() : cur_len + g_[path[d - 1]][i], path);
    }
  }
};