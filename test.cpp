class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> ans;
    string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string cur;
    dfs(digits, dict, 0, cur, ans);
    return ans;
  }

 private:
  void dfs(string digits, string dict[], int dep, string& cur, vector<string>& ans) {
    if (dep == digits.length()) {
      ans.push_back(cur);
      return;
    }

    for (char& c : dict[digits[dep] - '0']) {
      cur.push_back(c);
      dfs(digits, dict, dep + 1, cur, ans);
      cur.pop_back();
    }
  }
};