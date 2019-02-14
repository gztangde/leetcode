class Solution {
 public:
  double minAreaFreeRect(vector<vector<int>>& points) {
    int n = points.size();
    bool find = false;
    double ans = INT_MAX;
    vector<vector<int>>& P = points;
    for (int a = 0; a < n; ++a)
      for (int b = 0; b < n; ++b)
        for (int c = 0; c < n; ++c)
          for (int d = 0; d < n; ++d) {
            if (a == b || a == c || a == d || b == c || b == d || c == d) continue;
            if (P[a][0] - P[b][0] != P[d][0] - P[c][0]) continue;
            // Deal with the parallel sides
            if (P[a][1] - P[b][1] != P[d][1] - P[c][1]) continue;

            double x1 = P[a][0] - P[b][0];
            double x2 = P[c][0] - P[b][0];
            double y1 = P[a][1] - P[b][1];
            double y2 = P[c][1] - P[b][1];

            if (x1 * x2 + y1 * y2 == 0) {
              double area = abs(x1 * y2 - x2 * y1);
              if (area > 0 && area < ans) {
                find = true;
                ans = area;
              }
            }
          }
    if (!find) return 0;
    return ans;
  }
};