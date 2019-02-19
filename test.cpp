class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    dfs(s, 0, 0, ans, "()");
    return ans;
  }

 private:
  void dfs(const string &s, int last_i, int last_j, vector<string> &res, string p) {
    int n = s.size();
    int cnt = 0;
    for (int i = last_i; i < n; ++i) {
      if (s[i] == p[0])
        ++cnt;
      else if (s[i] == p[1])
        --cnt;
      if (cnt >= 0) continue;

      for (int j = last_j; j <= i; ++j) {
        if (s[j] != p[1]) continue;
        if (j > last_j && s[j - 1] == p[1]) continue;
        dfs(s.substr(0, j) + s.substr(j + 1, n - j - 1), i, j, res, p);
      }
      return;
    }
    string s1 = s;
    reverse(s1.begin(), s1.end());
    if (p[0] == '(')
      dfs(s1, 0, 0, res, ")(");
    else
      res.push_back(s1);
  }
};