---
title: Leetcode 744. Find Smallest Letter Greater Than Target
date: 2019-01-21 20:39:59
updated: 2019-01-21 20:39:59
categories: 
- [Leetcode]
- [Leetcode, Biarary-Search]
tags: Leetcode
notshow: true
top:
---

# Question

Given a list of sorted characters  `letters`  containing only lowercase letters, and given a target letter  `target`, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is  `target = 'z'`and  `letters = ['a', 'b']`, the answer is  `'a'`.

**Examples:**  

> **Input:**
> letters = ["c", "f", "j"]
> target = "a"
> **Output:** "c"
>
> **Input:**
> letters = ["c", "f", "j"]
> target = "c"
> **Output:** "f"
>
> **Input:**
> letters = ["c", "f", "j"]
> target = "d"
> **Output:** "f"
>
> **Input:**
> letters = ["c", "f", "j"]
> target = "g"
> **Output:** "j"
>
> **Input:**
> letters = ["c", "f", "j"]
> target = "j"
> **Output:** "c"
>
> **Input:**
> letters = ["c", "f", "j"]
> target = "k"
> **Output:** "c"

**Note:**  

1. `letters`  has a length in range  `[2, 10000]`.
2. `letters`  consists of lowercase letters, and contains at least 2 unique letters.
3. `target`  is a lowercase letter.

**Difficulty**:Easy
**Category**:Binary-Search

<!-- more -->

------------

# Analyze

------------

# Solution

## Solution 1: Line Scan

```cpp
class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    for (const char c : letters)
      if (c > target) return c;
    return letters.front();
  }
};
```

## Solution 2: Binary Search

```cpp
class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int left = 0, right = letters.size();
    while (left < right) {
      const int mid = left + (right - left) / 2;
      if (letters[mid] <= target)
        left = mid + 1;
      else
        right = mid;
    }
    int res = left % letters.size();
    return letters[res];
  }
};
```


<!-- 
------------

# Leetcode Question Summary


------------ -->
