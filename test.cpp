typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i, s, t) for (int i = (s); i < (t); i++)
#define FILL(x, v) memset(x, v, sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

int s[MAXN];

void add(int k, int v) {
  k++;
  for (; k < MAXN; k += -k & k) s[k] = min(s[k], v);
}

int get(int k) {
  if (k < 0) return INF;
  k++;
  int ans = INF;
  for (; k; k -= -k & k) ans = min(ans, s[k]);
  return ans;
}

class Solution {
 public:
  int maxWidthRamp(vector<int>& A) {
    int n = A.size();
    REP(i, 0, MAXN) s[i] = INF;
    int ans = 0;
    REP(i, 1, n + 1) {
      int v = A[i - 1];
      int idx = get(v);
      if (idx != INF && idx >= 1) {
        ans = max(ans, i - idx);
      }
      add(v, i);
    }
    return ans;
  }
};