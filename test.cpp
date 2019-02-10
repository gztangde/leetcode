typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i, s, t) for (int i = (s); i < (t); i++)
#define FILL(x, v) memset(x, v, sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

int rep[26];

class Solution {
 public:
  bool equationsPossible(vector<string>& equations) {
    REP(i, 0, 26) rep[i] = i;
    REP(i, 0, equations.size()) {
      int a = equations[i][0] - 'a', b = equations[i][3] - 'a', eq = equations[i][1] == '=';
      if (eq) unionset(a, b);
    }
    REP(i, 0, equations.size()) {
      int a = equations[i][0] - 'a', b = equations[i][3] - 'a', eq = equations[i][1] == '=';
      if (!eq) {
        if (find(a) == find(b)) return false;
      }
    }
    return true;
  }

 private:
  int find(int x) { return rep[x] == x ? x : rep[x] = find(rep[x]); }
  void unionset(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    rep[rx] = ry;
  }
};