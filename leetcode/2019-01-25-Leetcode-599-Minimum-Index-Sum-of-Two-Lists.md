---
title: Leetcode 599. Minimum Index Sum of Two Lists
date: 2019-01-25 22:55:21
updated: 2019-01-25 22:55:21
categories: 
- [Leetcode]
- [Leetcode, Hash-Table]
tags: Leetcode
notshow: true
top:
---

# Question

Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their  **common interest**  with the  **least list index sum**. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

**Example 1:**  

> **Input:**
> ["Shogun", "Tapioca Express", "Burger King", "KFC"]
> ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
> **Output:** ["Shogun"]
> **Explanation:** The only restaurant they both like is "Shogun".

**Example 2:**  

> **Input:**
> ["Shogun", "Tapioca Express", "Burger King", "KFC"]
> ["KFC", "Shogun", "Burger King"]
> **Output:** ["Shogun"]
> **Explanation:** The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).

**Note:**  

1. The length of both lists will be in the range of [1, 1000].
2. The length of strings in both lists will be in the range of [1, 30].
3. The index is starting from 0 to the list length minus 1.
4. No duplicates in both lists.

**Difficulty**:Easy

**Category**:Hash-Table

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> ans;
    int index = INT_MAX;
    for (int i = 0; i < list1.size(); ++i) {
      for (int j = 0; j < list2.size(); ++j) {
        if (list1[i] == list2[j] && i + j <= index) {
          if (i + j < index) {
            index = i + j;
            ans.clear();
          }
          ans.emplace_back(list1[i]);
        }
      }
    }
    return ans;
  }
};
```

<!-- TODO: Try to use hash table to solve this problem. -->


