class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    const size_t m = s1.length();
    const size_t n = s2.length();
    int f[m + 1][n + 1];
    f[0][0] = 0;
    for (size_t i = 1; i <= m; ++i) f[i][0] = f[i - 1][0] + s1[i - 1];
    for (size_t j = 1; j <= n; ++j) f[0][j] = f[0][j - 1] + s2[j - 1];

    for (size_t i = 1; i <= m; ++i) {
      for (size_t j = 1; j <= n; ++j) {
        if (s1[i - 1] == s2[j - 1]) {
          f[i][j] = f[i - 1][j - 1];
        } else {
          f[i][j] = min(f[i - 1][j] + s1[i - 1], f[i][j - 1] + s2[j - 1]);
        }
      }
    }
    return f[m][n];
  }
};