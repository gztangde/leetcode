---
title: Leetcode 937. Reorder Log Files
date: 2019-02-04 12:53:39
updated: 2019-02-04 12:53:39
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

You have an array of  `logs`. Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric  _identifier_. Then, either:

- Each word after the identifier will consist only of lowercase letters, or;
- Each word after the identifier will consist only of digits.

We will call these two varieties of logs  _letter-logs_  and  _digit-logs_. It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log. The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties. The digit-logs should be put in their original order.

Return the final order of the logs.

**Example 1:**

**Input:** ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
**Output:** ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]

**Note:**

1. `0 <= logs.length <= 100`
2. `3 <= logs[i].length <= 100`
3. `logs[i]`  is guaranteed to have an identifier, and a word after the identifier.

**Difficulty**:Easy

**Category**:

<!-- more -->

# Analyze

给若干行，每一行是以一个identifier开头，后面跟着以空格分隔的若干字符串，除了identifier外，一行中要不全是字母组成的字符串，要不全是数字。要求将所有“字母行”放到最上边，而且要排好序，排序的原则是除identifier外，一行与另一行进行字母序比较。若相同，则再比较identifier；而“数字行”则维持原来的先后顺序。

Log的格式是第一个单词是Log的索引，后面的都是Log的内容。有两种Log，一种内容是纯数字的，一种内容是纯英文字符的。现在要求，把所有的英文Log放到数字Log前面。而且如果是纯英文的字符Log，需要按照内容对Log进行排序，当内容相同的时候按照索引排序；如果是数字Log，保持原来的顺序。

# Solution

```cpp
bool myCompare(string a, string b) {
  int i = a.find(' ');
  int j = b.find(' ');
  if (!isdigit(a[i + 1]) && !isdigit(b[j + 1]))
    return a.substr(i + 1) < b.substr(j + 1);
  else {
    if (!isdigit(a[i + 1])) return true;
    return false;
  }
}
class Solution {
 public:
  vector<string> reorderLogFiles(vector<string>& logs) {
    stable_sort(logs.begin(), logs.end(), myCompare);
    return logs;
  }
};
```


**Solution: Partition + Sort**
partition the array such that all digit logs are after all letter logs
sort the letter logs part based on the log content
Time complexity: O(n + aloga)

Space complexity: O(n)

```cpp
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
      auto alpha_end = std::stable_partition(begin(logs),  end(logs), 
        [](const string& log){ return isalpha(log.back()); });
      std::sort(begin(logs), alpha_end, [](const string& a, const string& b){
        return a.substr(a.find(' ')) < b.substr(b.find(' '));
      });
      return logs;
    }
};
```