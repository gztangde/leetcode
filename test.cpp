typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i, s, t) for (int i = (s); i < (t); i++)
#define FILL(x, v) memset(x, v, sizeof(x))

const int INF = (int)2E9;
#define MAXN 100005

class Solution {
 public:
  ll dist(vector<vector<int>>& pts, int i, int j) {
    ll dx = pts[i][0] - pts[j][0];
    ll dy = pts[i][1] - pts[j][1];
    return dx * dx + dy * dy;
  }
  double minAreaFreeRect(vector<vector<int>>& points) {
    int n = points.size();
    double ans = 1e18;
    bool found = false;
    REP(i, 0, n) {
      REP(j, i + 1, n) {
        REP(k, j + 1, n) {
          REP(t, k + 1, n) {
            ll a = dist(points, i, j);
            ll b = dist(points, i, k);
            ll c = dist(points, i, t);
            ll d = dist(points, j, k);
            //后面藏歌是对角线
            ll e = dist(points, j, t);
            ll f = dist(points, k, t);
            vector<ll> es({a, b, c, d, e, f});
            sort(es.begin(), es.end());
            if (es[0] != es[1] || es[2] != es[3] || es[4] != es[5] || es[0] + es[2] != es[4]) continue;
            
            vector<ll> ss({es[0], es[2], es[4]});
            vector<ll> ei({a, b, c});

            sort(ei.begin(), ei.end());
            if (ei != ss) continue;

            vector<ll> ej({a, d, e});
            sort(ej.begin(), ej.end());
            if (ej != ss) continue;

            vector<ll> ek({b, d, f});
            sort(ek.begin(), ek.end());
            if (ek != ss) continue;

            vector<ll> et({c, e, f});
            sort(et.begin(), et.end());
            if (et != ss) continue;

            found = true;
            ans = min(ans, sqrt(es[0]) * sqrt(es[2]));
          }
        }
      }
    }
    if (!found) return 0;
    return ans;
  }
};