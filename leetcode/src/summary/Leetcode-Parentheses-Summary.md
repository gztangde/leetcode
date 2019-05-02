<!-- TOC -->

- [括号问题小结](#%E6%8B%AC%E5%8F%B7%E9%97%AE%E9%A2%98%E5%B0%8F%E7%BB%93)
  - [LC.20 Valid Parentheses, 验证括号合法](#lc20-valid-parentheses-%E9%AA%8C%E8%AF%81%E6%8B%AC%E5%8F%B7%E5%90%88%E6%B3%95)
  - [LC.22 Generate Parentheses, 生成合法括号](#lc22-generate-parentheses-%E7%94%9F%E6%88%90%E5%90%88%E6%B3%95%E6%8B%AC%E5%8F%B7)
  - [LC.32 Longest Valid Parentheses, 最长的合法括号长度](#lc32-longest-valid-parentheses-%E6%9C%80%E9%95%BF%E7%9A%84%E5%90%88%E6%B3%95%E6%8B%AC%E5%8F%B7%E9%95%BF%E5%BA%A6)
  - [LC.678 Valid Parenthesis String, 括号加正则--判断是否合法](#lc678-valid-parenthesis-string-%E6%8B%AC%E5%8F%B7%E5%8A%A0%E6%AD%A3%E5%88%99--%E5%88%A4%E6%96%AD%E6%98%AF%E5%90%A6%E5%90%88%E6%B3%95)
  - [LC.921 Minimum Add to Make Parentheses Valid, 最小添加次数，合法](#lc921-minimum-add-to-make-parentheses-valid-%E6%9C%80%E5%B0%8F%E6%B7%BB%E5%8A%A0%E6%AC%A1%E6%95%B0%E5%90%88%E6%B3%95)
  - [LC.241 Different Ways to Add Parentheses, 表达式中添加括号](#lc241-different-ways-to-add-parentheses-%E8%A1%A8%E8%BE%BE%E5%BC%8F%E4%B8%AD%E6%B7%BB%E5%8A%A0%E6%8B%AC%E5%8F%B7)
  - [LC.301 Remove Invalid Parentheses, 删除不合法的括号位置](#lc301-remove-invalid-parentheses-%E5%88%A0%E9%99%A4%E4%B8%8D%E5%90%88%E6%B3%95%E7%9A%84%E6%8B%AC%E5%8F%B7%E4%BD%8D%E7%BD%AE)
  - [LC.856 Score of Parentheses, 括号的度](#lc856-score-of-parentheses-%E6%8B%AC%E5%8F%B7%E7%9A%84%E5%BA%A6)

<!-- /TOC -->

# 括号问题小结

## LC.20 Valid Parentheses, 验证括号合法

```cpp
class Solution {
 public:
  bool isValid(string s) {
    std::stack<char> parentheses;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        parentheses.push(s[i]);
      else {
        if (parentheses.empty()) return false;
        if (s[i] == ')' && parentheses.top() != '(') return false;
        if (s[i] == '}' && parentheses.top() != '{') return false;
        if (s[i] == ']' && parentheses.top() != '[') return false;
        parentheses.pop();
      }
    }
    return parentheses.empty();
  }
};
```

## LC.22 Generate Parentheses, 生成合法括号

```cpp
// Runtime: 16 ms, faster than 49.46% of C++ online submissions for Generate Parentheses.
// Memory Usage: 17.4 MB, less than 100.00% of C++ online submissions for Generate Parentheses.
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    generateParenthesisDFS(n, n, "", ans);
    return ans;
  }

 private:
  void generateParenthesisDFS(int left_n, int right_n, string out, vector<string>& ans) {
    if (left_n > right_n) return;
    if (left_n == 0 && right_n == 0) {
      ans.emplace_back(out);
    } else {
      if (left_n > 0) generateParenthesisDFS(left_n - 1, right_n, out + "(", ans);
      if (right_n > 0) generateParenthesisDFS(left_n, right_n - 1, out + ")", ans);
    }
  }
};
```

## LC.32 Longest Valid Parentheses, 最长的合法括号长度

```cpp
class Solution {
 public:
  int longestValidParentheses(string s) {
    int res = 0, left = 0;
    stack<int> m;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        m.push(i);
      else {
        if (m.empty())
          left = i + 1;
        else {
          m.pop();
          if (m.empty())
            res = max(res, i + 1 - left);
          else
            res = max(res, i - m.top());
        }
      }
    }
    return res;
  }
};
```

## LC.678 Valid Parenthesis String, 括号加正则--判断是否合法

Input: "()", Output: True

Input: "(*)", Output: True

Input: "(*))", Output: True

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') star.push(i);
            else if (s[i] == '(') left.push(i);
            else {
                if (left.empty() && star.empty()) return false;
                if (!left.empty()) left.pop();
                else star.pop();
            }
        }
        while (!left.empty() && !star.empty()) {
            if (left.top() > star.top()) return false;
            left.pop(); star.pop();
        }
        return left.empty();
    }
};
```

## LC.921 Minimum Add to Make Parentheses Valid, 最小添加次数，合法

```cpp
class Solution {
 public:
  int minAddToMakeValid(string s) {
    int ans = 0;
    stack<char> sta;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        sta.push(s[i]);
      else {
        if (sta.empty()) {
          ans++;
          continue;
        } else if (s[i] == ')' && sta.top() != '(')
          ans++;
        sta.pop();
      }
    }
    ans += sta.size();
    return ans;
  }
};

```

## LC.241 Different Ways to Add Parentheses, 表达式中添加括号

```cpp
// Author: Huahua
namespace leetcode {
int add(int a, int b) { return a + b; }
int minus(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
}  // namespace leetcode

class Solution {
 public:
  vector<int> diffWaysToCompute(string input) { return ways(input); }

 private:
  unordered_map<string, vector<int>> m_;
  const vector<int>& ways(const string& input) {
    if (m_.count(input)) return m_[input];
    vector<int> res;

    for (int i = 0; i < input.length(); ++i) {
      const char op = input[i];
      if (op == '+' || op == '-' || op == '*') {
        const string left = input.substr(0, i);
        const string right = input.substr(i + 1);

        const vector<int>& l = ways(left);
        const vector<int>& r = ways(right);

        std::function<int(int, int)> f;

        switch (op) {
          case '+':
            f = leetcode::add;
            break;
          case '-':
            f = leetcode::minus;
            break;
          case '*':
            f = leetcode::multiply;
            break;
        }

        for (int a : l)
          for (int b : r) res.emplace_back(f(a, b));
      }
    }

    if (res.empty()) res.emplace_back(std::stoi(input));

    m_[input] = res;
    return m_[input];
  }
};
```

## LC.301 Remove Invalid Parentheses, 删除不合法的括号位置

```cpp
// Runtime: 8 ms, faster than 97.09% of C++ online submissions for Remove Invalid Parentheses.
// Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for Remove Invalid Parentheses.
// Solution: DFS
// Step 1. Count how many parentheses we need to remove
// Step 2. dfs function --- Try to remove each parentheses.
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    int l_cnt = 0, r_cnt = 0;

    // l_cnt and r_cnt is the number "()" which we need to remove;
    for (char& c : s) {
      if (c == '(') ++l_cnt;
      else if (c == ')') l_cnt == 0 ? ++r_cnt : --l_cnt;
    }

    dfs(s, 0, l_cnt, r_cnt, ans);
    if (ans.empty()) ans.emplace_back("");
    return ans;
  }

 private:
  void dfs(string& s, int start, int l_cnt, int r_cnt, vector<string>& ans) {
    if (l_cnt == 0 && r_cnt == 0) {
      if (isValidParentheses(s)) ans.emplace_back(s);
      return;
    }

    for (int i = start; i < s.length(); ++i) {
      // deal with the repetitive element.
      if (i > start && s[i] == s[i - 1]) continue;
      if (s[i] == '(' || s[i] == ')') {
        string cur = s;
        cur.erase(i, 1);
        if (r_cnt > 0 && s[i] == ')')
          dfs(cur, i, l_cnt, r_cnt - 1, ans);
        else if (l_cnt > 0 && s[i] == '(')
          dfs(cur, i, l_cnt - 1, r_cnt, ans);
      }
    }
  }
};
  // Judge the s is valid parentheses, if not, return false. Otherwise, return true.
  bool isValidParentheses(string& s) {
    int cnt = 0;
    for (char& a : s) {
      if (a == '(') cnt++;
      else if (a == ')') cnt--;
      if (cnt < 0) return false;
    }
    return cnt == 0;
  }
```

## LC.856 Score of Parentheses, 括号的度

```cpp
class Solution {
 public:
  int scoreOfParentheses(string S) {
    int res = 0;
    std::stack<char> par_stack;
    bool flag = false;
    for (int i = 0; i < S.size(); ++i) {
      if (S[i] == '(') {
        par_stack.push(S[i]);
        flag = true;
      } else if (flag == true) {
        flag = false;
        if (par_stack.size() == 1)
          res++;
        else
          res += 1 * pow(2, par_stack.size() - 1);
        par_stack.pop();
      } else
        par_stack.pop();
    }

    return res;
  }
};
```
