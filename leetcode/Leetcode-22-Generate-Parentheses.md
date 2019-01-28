
# Question

Given  _n_  pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


For example, given  _n_  = 3, a solution set is:
> [
>  "((()))",
>  "(()())",
>  "(())()",
>  "()(())",
>  "()()()"
>]

# solution

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> res;
      generatePar(n,n,"",res);
      return res;
    }
  
  void generatePar(int left_n, int right_n, string out, vector<string> & res) {
    if(left_n > right_n) return;
    if(left_n == 0 && right_n == 0) res.emplace_back(out);
    else {
      if(left_n > 0) generatePar(left_n - 1, right_n, out + '(', res);
      if(right_n > 0) generatePar(left_n, right_n - 1, out+')', res);
    }
  }
};
```
