
# Question

Given a chemical  `formula`  (given as a string), return the count of each atom.

An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

1 or more digits representing the count of that element may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

**Example 1:**  

> **Input:** 
> formula = "H2O"
> **Output:** "H2O"
> **Explanation:** 
> The count of elements are {'H': 2, 'O': 1}.

**Example 2:**  

> **Input:** 
> formula = "Mg(OH)2"
> **Output:** "H2MgO2"
> **Explanation:** 
> The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

**Example 3:**  

> **Input:** 
> formula = "K4(ON(SO3)2)2"
> **Output:** "K4N2O14S4"
> **Explanation:** 
> The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.

**Note:**

- All atom names consist of lowercase letters, except for the first character which is uppercase.
- The length of  `formula`  will be in the range  `[1, 1000]`.
- `formula`  will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.

**Difficulty**:Hard
**Category**:Hash-Table, Stack, Recursion


------------

# Analyze

题目描述：

给你一个分子方程式，返回去每个原子的个数（判断化学式是否是符合题目含义的）。 

思路：

![](/images/in-post/2019-01-09-Leetcode-726-Number-of-Atoms/2019-01-09-12-05-43.png)

- 使用`Map`存储每个部分得到的`ATOM`和‘Count’

------------

# Solution

## 递归的方案

```cpp
// Solution: Recursion
// Time complexity: O(n)
// Space complexity: O(n)
// Runtime: 4ms
class Solution {
 public:
  string countOfAtoms(string formula) {
    int i = 0;
    string ans;
    for (const auto& atom : countAtoms(formula, i)) {
      ans += atom.first;
      if (atom.second > 1) ans += to_string(atom.second);
    }
    return ans;
  }

 private:
  map<string, int> countAtoms(string& formula, int& i) {
    map<string, int> counts;
    while (i != formula.length()) {
      if (formula[i] == '(') {
        // Do Something to get name and number
        // Dealwith the information between `(` and `)`
        const auto& counts_ = countAtoms(formula, ++i);
        const int count = getCount(formula, i);
        for (auto& k : counts_) {
          counts[k.first] += k.second * count;
        }

      } else if (formula[i] == ')') {
        ++i;
        // Finish one Parentntheses, return the counts for this parentntheses
        return counts;
      } else {
        const string& name = getName(formula, i);
        counts[name] += getCount(formula, i);
      }
    }
    return counts;
  }

  const string getName(string& formula, int& i) {
    string name;
    while (isalpha(formula[i]) && (name.empty() || islower(formula[i]))) name += formula[i++];
    return name;
  }

  const int getCount(string& formula, int& i) {
    string count_str;
    while (isdigit(formula[i])) count_str += formula[i++];
    return count_str.empty() ? 1 : std::stoi(count_str);
  }
};
```
