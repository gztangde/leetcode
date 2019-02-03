class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int val = 1, c = (n + 1) / 2, p = n;

    for (int i = 0; i < c; ++i, p -= 2) {
      for (int row_up = i; row_up <= i + p - 1; ++row_up)  //UP
        res[i][row_up] = val++;

      for (int row_right = i + 1; row_right <= i + p - 1; ++row_right) //Right
        res[row_right][i + p - 1] = val++;

      for (int row_bottom = n - i - 2; row_bottom >= i; --row_bottom) //Bottom
        res[i + p - 1][row_bottom] = val++;
  
      for (int row_left = n - i - 2; row_left > i; --row_left) { //Left
        res[row_left][i] = val++;
    }
    return res;
  }
};