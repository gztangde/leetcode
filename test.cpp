class Solution {
 public:
  int minDistance(string word1, string word2) {
    const size_t m = word1.length();
    const size_t n = word2.length();
    int f[m + 1][n + 1];
    for (size_t i = 0; i <= m; ++i) f[i][0] = i;
    for (size_t j = 0; j <= n; ++j) f[0][j] = j;

    for (size_t i = 1; i <= m; ++i) {
      for (size_t j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          f[i][j] = f[i - 1][j - 1];
        } else {
          f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
        }
      }
    }
    return f[m][n];
  }
};