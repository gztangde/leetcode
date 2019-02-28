class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    rows_ = vector<vector<int>>(9, vector<int>(10));
    cols_ = vector<vector<int>>(9, vector<int>(10));
    boxes_ = vector<vector<int>>(9, vector<int>(10));

    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        if (board[r][c] != '.') {
          int n = board[r][c] - '0';
          int br = r / 3, bc = c / 3;
          rows_[r][n] = 1;
          cols_[c][n] = 1;
          boxes_[br * 3 + bc][n] = 1;
        }
      }
    }

    fill(board, 0, 0);
  }

 private:
  vector<vector<int>> rows_, cols_, boxes_;

  bool fill(vector<vector<char>>& board, int r, int c) {
    if (r == 9) return true;

    // Get the next element index
    int nc = (c + 1) % 9;
    int nr = nc == 0 ? r + 1 : r;

    if (board[r][c] != '.') return fill(board, nr, nc);

    for (int i = 1; i <= 9; ++i) {
      int br = r / 3, bc = c / 3;
      int box_index = br * 3 + bc;
      if (!rows_[r][i] && !cols_[c][i] && !boxes_[box_index][i]) {
        rows_[r][i] = 1;
        cols_[c][i] = 1;
        boxes_[box_index][i] = 1;
        board[r][c] = i + '0';
        if (fill(board, nr, nc)) return true;
        board[r][c] = '.';
        boxes_[box_index][i] = 0;
        cols_[c][i] = 0;
        rows_[r][i] = 0;
      }
    }
    return false;
  }
};