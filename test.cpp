class Solution {
 public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    N = N % 14;
    if (N == 0) N = 14;
    for (int i = 1; i <= N; ++i) {
      vector<int> temp = cells;
      for (int j = 0; j < temp.size(); ++j) {
        if (j == 0 || j == temp.size() - 1) {
          cells[j] = 0;
          continue;
        } else {
          if (temp[j - 1] == temp[j + 1]) {
            cells[j] = 1;
          } else {
            cells[j] = 0;
          }
        }
      }
      // for (auto cell : cells) {
      //   std::cout << cell << ", ";
      // }
      // std::cout << std::endl;
    }
    return cells;
  }
};