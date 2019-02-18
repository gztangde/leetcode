class Solution {
 public:
  string shortestSuperstring(vector<string>& A) {
    const int n = A.size();

    // g[i][j] is the cost of appending word[j] after word[i], or weight of edge[i][j].
    // 计算 Cost
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        g[i][j] = A[j].length();
        for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k)
          if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) g[i][j] = A[j].length() - k;
      }

    // dp[s][i] := min distance to visit nodes (represented as a binary state s) once and only once and the path ends
    // with node i.e.g. dp[7][1] is the min distance to visit nodes (0, 1, 2) and ends with node 1, the possible paths
    // could be (0, 2, 1), (2, 0, 1).
    // dp 的第一维代表的是状态， 表示是否使用了这一个结点， 初始数值设置为 INT_MAX/2防止溢出
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));

    // 使用Parent 来记录 dp 的状态是由那一个状态转移过来的
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));

   // 设置初始数值， 只访问第 i 个结点， 对应的初始数值。
    for (int i = 0; i < n; ++i) dp[1 << i][i] = A[i].length();

    // 枚举所有的状态， 从小到大
    for (int s = 1; s < (1 << n); ++s) {
      // 结尾的结点
      for (int j = 0; j < n; ++j) {
        // s 的 第 ‘i’ 不为 1 的话， 表示藏歌状态是不存在的
        // 需要保证处理的时候， j 这一个结点是已经访问过了的， 如果没有访问， 那么就跳过
        // s表示当前的结点， 必须是以 j 结尾的。
        if (!(s & (1 << j))) continue;
        //得到上一个状态
        int ps = s & ~(1 << j);
        for (int i = 0; i < n; ++i) {
          // 找到一个最短的路径
          if (dp[ps][i] + g[i][j] < dp[s][j]) {
            dp[s][j] = dp[ps][i] + g[i][j];
            // 存储这个路径的由来
            parent[s][j] = i;
          }
        }
      }
    }

    // 找到最后一个， 所有节点否访问过的情况
    // 恢复路径， 找到最优路径
    auto it = min_element(begin(dp.back()), end(dp.back()));
    int j = it - begin(dp.back()); // 得到最后是以那一个结点结尾
    int s = (1 << n) - 1; //表示所有的结点都访问过了
    string ans;
    while (s) {
      int i = parent[s][j]; //找到上一个结点
      if (i < 0) // 表示已经找到最后的一个了，初始的时候初始数值为 -1
        ans = A[j] + ans;
      else
        ans = A[j].substr(A[j].length() - g[i][j]) + ans; // 得到Substr
      s &= ~(1 << j); //修改状态
      j = i;
    }
    return ans;
  }
};
