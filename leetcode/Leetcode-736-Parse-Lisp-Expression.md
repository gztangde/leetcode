---
title: Leetcode 736. Parse Lisp Expression
date: 2019-01-09 16:40:39
updated: 2019-01-09 16:40:39
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

You are given a string  `expression`  representing a Lisp-like expression to return the integer value of.

The syntax for these expressions is given as follows.

-   An expression is either an integer, a let-expression, an add-expression, a mult-expression, or an assigned variable. Expressions always evaluate to a single integer.

-   (An integer could be positive or negative.)

-   A let-expression takes the form  `(let v1 e1 v2 e2 ... vn en expr)`, where  `let`  is always the string  `"let"`, then there are 1 or more pairs of alternating variables and expressions, meaning that the first variable  `v1`  is assigned the value of the expression  `e1`, the second variable  `v2`  is assigned the value of the expression  `e2`, and so on  **sequentially**; and then the value of this let-expression is the value of the expression  `expr`.

-   An add-expression takes the form  `(add e1 e2)`  where  `add`  is always the string  `"add"`, there are always two expressions  `e1, e2`, and this expression evaluates to the addition of the evaluation of  `e1`  and the evaluation of  `e2`.

-   A mult-expression takes the form  `(mult e1 e2)`  where  `mult`  is always the string  `"mult"`, there are always two expressions  `e1, e2`, and this expression evaluates to the multiplication of the evaluation of  `e1`  and the evaluation of  `e2`.

-   For the purposes of this question, we will use a smaller subset of variable names. A variable starts with a lowercase letter, then zero or more lowercase letters or digits. Additionally for your convenience, the names "add", "let", or "mult" are protected and will never be used as variable names.

-   Finally, there is the concept of scope. When an expression of a variable name is evaluated,  **within the context of that evaluation**, the innermost scope (in terms of parentheses) is checked first for the value of that variable, and then outer scopes are checked sequentially. It is guaranteed that every expression is legal. Please see the examples for more details on scope.

**Evaluation Examples:**  

> **Input:** (add 1 2)
> **Output:** 3

> **Input:** (mult 3 (add 2 3))
> **Output:** 15

> **Input:** (let x 2 (mult x 5))
> **Output:** 10

> **Input:** (let x 2 (mult x (let x 3 y 4 (add x y))))
> **Output:** 14
> **Explanation:** In the expression (add x y), when checking for the value of the variable x,
> we check from the innermost scope to the outermost in the context of the variable we are trying to evaluate.
> Since x = 3 is found first, the value of x is 3.

> **Input:** (let x 3 x 2 x)
> **Output:** 2
> **Explanation:** Assignment in let statements is processed sequentially.

> **Input:** (let x 1 y 2 x (add x y) (add x y))
> **Output:** 5
> **Explanation:** The first (add x y) evaluates as 3, and is assigned to x.
> The second (add x y) evaluates as 3+2 = 5.

> **Input:** (let x 2 (add (let x 3 (let x 4 x)) x))
> **Output:** 6
> **Explanation:** Even though (let x 4 x) has a deeper scope, it is outside the context
> of the final x in the add-expression.  That final x will equal 2.

> **Input:** (let a1 3 b2 (add a1 1) b2) 
> **Output** 4
> **Explanation:** Variable names can contain digits after the first character.

**Note:**

- The given string  `expression`  is well formatted: There are no leading or trailing spaces, there is only a single space separating different components of the string, and no space between adjacent parentheses. The expression is guaranteed to be legal and evaluate to an integer.
- The length of  `expression`  is at most 2000. (It is also non-empty, as that would not be a legal expression.)
- The answer and all intermediate calculations of that answer are guaranteed to fit in a 32-bit integer.

**Difficulty**:Hard

**Category**:String

<!-- more -->

------------

# Analyze

**嵌套的问题一般使用递归来解决**

![](/images/in-post/2019-01-09-Leetcode-736-Parse-Lisp-Expression/2019-01-09-17-31-23.png)

表达式一般只有三种情况，如上图所示：
- 数字开头
- 变量名
- 括号开头---函数（add, mult, let）,其中的add, mult对应的两个数值

最后的输出就是一个表达式

**递归表达式：**完整的处理一个表达式，遇到括号，就进入新的表达式

![](/images/in-post/2019-01-09-Leetcode-736-Parse-Lisp-Expression/2019-01-09-17-34-49.png)

如果读取到括号，那就返回一个表达式的数值。
虽然上面看上去只有两个部分，但是其实有五个`expr`的处理过程

考虑如何处理`scope`：

![](/images/in-post/2019-01-09-Leetcode-736-Parse-Lisp-Expression/2019-01-09-17-46-19.png)

在这一个题目中，变量的名字是可以嵌套的的，这就是在里面的话，是没有办法得到外面的变量数据的的，只能使用内部的变量数据，这就会使得处理过程比较复杂了。在这里可能需要使用到`stack`的方式，来处理。并且在function call之后的话进行退栈。

------------

# Solution

```cpp
// Solution: Recursive parsing
// Time complexity: O(n^2) in worst case O(n) in practice
// Space complexity: O(n)
// Runtime: 4ms
class Solution {
 public:
  int evaluate(string expression) {
    scopes_.clear();
    int pos = 0;
    return eval(expression, pos);
  }

 private:
  deque<unordered_map<string, int>> scopes_;

  // Function to deal with whole expression
  int eval(string& exp, int& pos) {
    scopes_.push_front(unordered_map<string, int>());
    int value = 0;
    // Deal with the first '('
    if (exp[pos] == '(') ++pos;

    const string token = getToken(exp, pos);

    if (token == "add") {
      int v1 = eval(exp, ++pos), v2 = eval(exp, ++pos);
      value = v1 + v2;
    } else if (token == "mult") {
      int v1 = eval(exp, ++pos), v2 = eval(exp, ++pos);
      value = v1 * v2;
    } else if (token == "let") {
      string val;
      while (exp[pos] != ')') {
        ++pos;  // Pass the space
        if (exp[pos] == '(') {
          value = eval(exp, ++pos);
          break;
        }
        // Get a Token: x or number(last express)
        val = getToken(exp, pos);

        // This Token is the last express;
        if (exp[pos] == ')') {
          if (isalpha(val[0])) {
            value = getValue(val);
          } else {
            // This is a number(int)
            value = std::stoi(val);
          }
          // 处理完了
          break;
        }
        // 如果最后不是右括号，那么就说明这是一个变量名字
        value = scopes_.front()[val] = eval(exp, ++pos);
      }
    } else if (isalpha(token[0])) {
      value = getValue(token);
    } else {
      // This is a number(int)
      value = std::stoi(token);
    }
    if (exp[pos] == ')') ++pos;
    scopes_.pop_front();
    return value;
  }

  // Get the Important Token: let, add, mul, number, string
  const string getToken(string& exp, int& pos) {
    string token;
    while (pos < exp.length()) {
      if (exp[pos] == ')' || exp[pos] == ' ') break;
      token += exp[pos++];
    }
    return token;
  }

  // Get the Value from the scopes_
  const int getValue(const string& name) {
    for (const auto& scope : scopes_) {
      if (scope.count(name)) return scope.at(name);
    }
    return -1;
  }
};
```