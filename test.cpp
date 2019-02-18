class Solution {
 public:
  int numSquarefulPerms(vector<int>& A) {
    const int n = A.size();
    // For deduplication.
    std::sort(begin(A), end(A));
    // g[i][j] == 1 if A[i], A[j] are squareful.
    vector<vector<int>> g(n, vector<int>(n, 0));
    // dp[s][i] := number of ways to reach state s and ends with node i.
    vector<vector<int>> dp(1 << n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        int r = sqrt(A[i] + A[j]);
        if (r * r == A[i] + A[j]) g[i][j] = 1;
      }
    }

    // For the same numbers, only the first one can be the starting point.
    for (int i = 0; i < n; ++i)
      if (i == 0 || A[i] != A[i - 1]) dp[(1 << i)][i] = 1;

    int ans = 0;
    for (int s = 0; s < (1 << n); ++s)
      for (int i = 0; i < n; ++i) {
        if (!dp[s][i]) continue;
        for (int j = 0; j < n; ++j) {
          if (!g[i][j]) continue;
          if (s & (1 << j)) continue;
          // Only the first one can be used as the dest.
          if (j > 0 && !(s & (1 << (j - 1))) && A[j - 1] == A[j]) continue;
          dp[s | (1 << j)][j] += dp[s][i];
        }
      }

    for (int i = 0; i < n; ++i) ans += dp[(1 << n) - 1][i];
    return ans;
  }
};