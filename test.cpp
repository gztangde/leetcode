class Solution {
  vector<string> results;

 public:
  vector<string> generateParenthesis(int n) {
    string str;
    DFS(0, 0, str, n);
    return results;
  }

  void DFS(int left, int right, string& str, int n) {
    if (left == n && right == n)
      results.push_back(str);
    else if (left > n || right > left)
      return;
    else {
      DFS(left + 1, right, str + "(", n);
      DFS(left, right + 1, str + ")", n);
    }
  }
};