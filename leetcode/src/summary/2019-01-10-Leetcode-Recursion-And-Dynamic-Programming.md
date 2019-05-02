# Recursion and Dynamic Programming

There are a large number of recursive problems, many follow similar patterns. A goof hint: 
**A problem is recursive is that it can be build off of subproblems**.

A good candidate for recursion:

* Design an algorithm to compute the n-th...
* Write code to list the first n ...
* Implement a method to compute all ...
  
**First of the thing: Recognize recursive problems**

## How to approach

Three of the most common approaches to develop an algorithm are `bottom-up`, `Top-Down-Approach` and `Half-and-half`.

**Bottom-Up approach**

* Start with knowing how to solve the problem from a simple case, one element, two elements, three elements ... and so on.
* The key here is to think about how you can build the solution for one case off of the previous case (Or multiple previous case.)

**Top-Down Approach**

Think about how we can divide the problem for case **N** into subproblems.

> Be careful overlap between the cases.

**Half-And-Half Approach**(Often)

Divide the data set in half.

For example, **binary search** works with a `half-and-half` approach. When we look for an elements in a sorted array, we first figure out which half of the array contains the value. Then we recurse and search fro it in that half.

**Merge Sort** is also a `half-and-half` approach. We sort each half of the array and then merge together the sorted halves.

> All recursive algorithms can be implemented iteratively, although sometimes the code to do so is much more complex.

## Dynamic Programming & Memoization

For example-Fibonacci Numbers.([Leetcode 509. Fibonacci Number](../Leetcode-509-Fibonacci-Number.md))

```cpp
int fibonacci(int i) {
  if (i == 0) return 0;
  if (i == 1) return 1;
  return fibonacci(i - 1) + fibonacci(i - 2);
}
```

![](/images/2019-02-10-16-41-00.png)

Optimize(Top-Down Dynamic Programming(Or Memoization)

```cpp
int fibonacci(int n) {
  return fibonacci(n, new int[n + 1];
}

int fibonacci(int i, int [] memo) {
  if (i == 0 || i == 1) return i;

  if (memo[i] == 0) {
    memo[i] = fibonacci(i - 1, memo) + fibonacci(i - 2, memo);
  }
  return memo[i];
}
```

Buttom-Up Dynamic Programming

```cpp
int fibonacci(int n) {
  if (n == 0) return 0;
  else if (n == 1) return 1;

  int [] memo = new int[n];
  memo[0] = 0;
  memo[1] = 1;
  for(int i = 2; i < n; i++){
    momo[i] = memo[i - 1] + memo[i - 2];
  }
  return memo[n - 1] + memo[n - 2];
}
```

We don't need the meno[n], we use a, b:

```cpp
int fibonacci(int n) {
  if (n == 0) return 0;
  int a = 0, b = 1;
  for (int i = 2; i < n; i++) {
    int c = a + b;
    a = b;
    b = c;
  }
  return a + b;
}
```

# Relative Questions

* **Q1. Climbing Stairs / Triple Step.** ([Leetcode 70. Climbing-Stairs](../Leetcode-70-Climbing-Stairs.md))
* **Q2. Robot in a Grid.** Imagine a robot sitting on the upper left hand corner of an NxN grid. The robot can only move in two directions: right and down. How many possible paths are there for the robot? ([Leetcode 64. Unique Paths](../Leetcode-63-Unique-Paths-II.md))
* **Q3. Magic Index.**
* **Q4. Power set.** Write a method that returns all subsets of a set.([Leetcode 78. Subsets](../Leetcode-78-Subsets.md))
* **Q5. Recursive Multiply.**
* **Q6. Tower of Hanoi.**
* **Q7. Permutations without Dups.**
* **Q8. Permutations with Dups.**
* **Q9. Parens.**
* **Q10. Paint Fill.**
* **Q11. Coins.**
* **Q12. Eight Queens.**
* **Q13. Stack of Boxes.**
* **Q14. Boolean Evaluation.**
