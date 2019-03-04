const int N = 40;
const int INF = 1 << 29;
int dp[N][N];
int sum[N];

class Solution {
 public:
  int k;
  vector<int> a;
  int solve(int L, int R) {
    int& ret = dp[L][R];
    if (ret >= 0) return ret;
    if (R - L == 1) return 0;
    ret = INF;
    vector<int> d(N, INF), e(N);
    for (int i = L + 1; i < R; ++i) {
      if ((R - i - 1) % (k - 1) == 0) d[i] = solve(i, R);
    }
    for (int i = L; i < R; ++i) cout << d[i] << " " << endl;
    for (int u = 1; u < k; ++u) {
      fill(e.begin(), e.end(), INF);
      for (int i = L; i < R; ++i) {
        for (int j = i + 1; j < R; ++j) {
          if ((j - i - 1) % (k - 1)) continue;
          e[i] = min(e[i], solve(i, j) + d[j]);
        }
      }
      swap(d, e);
    }
    ret = d[L] + sum[R] - sum[L];
    return ret;
  }
  int mergeStones(vector<int>& a, int k) {
    this->a = a;
    this->k = k;
    int n = a.size();
    if ((n - 1) % (k - 1)) return -1;
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i - 1];
    memset(dp, 255, sizeof(dp));
    int ret = solve(0, n);
    return ret;
  }
};