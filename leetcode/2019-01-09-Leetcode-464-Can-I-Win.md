---
title: Leetcode 464. Can I Win
date: 2019-01-09 19:17:37
updated: 2019-01-09 19:17:37
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer  `maxChoosableInteger`  and another integer  `desiredTotal`, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that  `maxChoosableInteger`  will not be larger than 20 and  `desiredTotal`  will not be larger than 300.

**Example**

> **Input:**
> maxChoosableInteger = 10
> desiredTotal = 11

> **Output:**
> false

> **Explanation:**
> No matter which integer the first player choose, the first player will lose.
> The first player can choose an integer from 1 up to 10.
> If the first player choose 1, the second player can only choose integers from 2 up to 10.
> The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
> Same with other integers chosen by the first player, the second player will always win.

**Difficulty**:Medium

**Category**:Dynamic-Programming, Minimax

<!-- more -->

------------

# Analyze

有一个博弈论相关的方式，使用递归，每次走最好的一步，默认对手也走最好的一步. 这道题目需要求解第一个`player`有没有机会取得胜利，但是这可能会让另外一个`player`没有机会胜利的情况也是返回`true`的。

要求：
- 一个数字只能使用一次， 范围是`1-15`

For example:

![](/images/in-post/2019-01-09-Leetcode-464-Can-I-Win/2019-01-10-00-35-12.png)

根据上图中，我们可以得到，在这道题目中可能存在的情况是`2^m`中情况，但你第一个用户开始的时候，就面临这些情况，我们在这道题目中使用`vector<char> r_`来记录在你面临的每一种情况下，你所能够取得的情况`r_ = vector<char>(1 << m, 0);`。

所以每次递归给对方的就是，你选择了这一个数字，然后把更新之后的状态给对方，如果对方尝试完所有的数据之后都不能够胜利，那么就是你获得胜利了：

```cpp
if (!canIWin(m, d - (i + 1), s | (1 << i))) {
  r_[s] = 1;
  return true;  // Current Player win
}
```

当然，如果对方在每一种情况下面都是可以取得胜利的话，那就是失败了，返回`false`

```cpp
// current player lose
r_[s] = -1;
return false;
```

![](/images/in-post/2019-01-09-Leetcode-464-Can-I-Win/2019-01-10-17-25-19.png)

------------

# Solution

```cpp
// Solution: Recursion with memoization
//Time complexity: O(2^M)
//Space complexity: O(2^M)
// Runtimes: 20ms
class Solution {
 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    int& m = maxChoosableInteger;
    int& d = desiredTotal;
    // Boundary Conditions.
    if (d <= 0) return true;
    const int sum = m * (m + 1) / 2;
    if (sum < d) return false;

    // Recursion function to judge: Can I Win:
    r_ = vector<char>(1 << m, 0);  // Use r_[x] to record which state can win, there are 2^m state
    return canIWin(m, d, 0);
  }

 private:
  vector<char> r_;
  // If you begin with the state(s), can you win this game in this state;
  bool canIWin(const int m, const int d, const int s) {
    // Last person have been win this game
    if (d <= 0) return false;
    // If r_[s] = 0, not know, 1: win, -1: lose
    if (r_[s]) return r_[s] == 1;
    for (int i = 0; i < m; ++i) {
      if (s & (1 << i)) continue;  // This number i+1 has been used before;
      if (!canIWin(m, d - (i + 1), s | (1 << i))) {
        r_[s] = 1;
        return true;  // Current Player win
      }
    }
    // current player lose
    r_[s] = -1;
    return false;
  }
};
```