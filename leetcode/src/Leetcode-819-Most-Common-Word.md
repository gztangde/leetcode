---
title: Leetcode 819. Most Common Words
date: 2018-10-22 19:09:31
updated: 2018-10-22 19:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Leetcode 819. Most Common Words

Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words. It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation. Words in the paragraph are not case sensitive. The answer is in lowercase.

**Example:**

> **Input:**
> paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
> banned = ["hit"]
> **Output:** "ball"
> **Explanation:**s
> "hit" occurs 3 times, but it is a banned word.
> "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive, that punctuation is ignored (even if adjacent to words, such as "ball,"), and that "hit" isn't the answer even though it occurs more because it is banned.

**Note:**

- `1 <= paragraph.length <= 1000`.
- `1 <= banned.length <= 100`.
- `1 <= banned[i].length <= 10`.
- The answer is unique, and written in lowercase (even if its occurrences in  `paragraph` may have uppercase symbols, and even if it is a proper noun.)
- `paragraph`  only consists of letters, spaces, or the punctuation symbols  `!?',;.`
- There are no hyphens or hyphenated words.
- Words only consist of letters, never apostrophes or other punctuation symbols.

<!--more-->

# Analyze

这一道题目只需要排查被禁止的词汇,找到里面重复最高频率的词汇就可以了，处理方式如下：

- 在`string paragraph`里面找到特殊的符号，将这一些特殊的符号全部是使用`空格`代替，为之后更容易的分割输入做准备
- 使用`istringstream stream(paragraph)`将输入全部转换成以空格分割的输入单词`word`.
- 将每个不在禁止字符串数组里面的单词都插入到一个`unordered_map`，如果原来`unordered_map`里面没有的话，那么就存有1，如果原来里面就已经有数据了，那么就取出来对应的数据，将其加一
- 最后遍历`unordered_map`，找到`currentMax = it->second; arg_max = it->first;`最大的位置，然后返回。

----------

# Solution

## Solution 1: istringstream

```cpp
class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    const string symbols = "!?',;.";
    std::unordered_set<std::string> bannedset;
    std::unordered_map<std::string, int> stringMap;
    string word, arg_max;
    unsigned currentMax = 0;

    for (string s : banned) bannedset.emplace(s);
    for (auto it = paragraph.begin(); it != paragraph.end();) {
      if (symbols.find(*it) != std::string::npos) {
        *it = ' ';
      } else {
        *it = tolower(*it);
        ++it;
      }
    }
    istringstream stream(paragraph);
    while (stream >> word) {
      if (bannedset.find(word) == bannedset.end()) {
        auto search = stringMap.find(word);
        if (search == stringMap.end()) {
          stringMap.insert(std::make_pair(word, 1));
        } else {
          stringMap[word] = search->second + 1;
        }
      }
    }

    for (auto it = stringMap.begin(); it != stringMap.end(); ++it) {
      if (it->second > currentMax) {
        arg_max = it->first;
        currentMax = it->second;
      }
    }

    return arg_max;
  }
};
```

## Solution 2: Hashtable

使用一个`set`来保存需要屏蔽的词汇， 然后使用`Ｈashmap`统计每个单词出现的频率，如果这个单词在屏蔽名单里面出现过， 那么就不使用这个单词来计算最高的频率。分为3步：

* 遍历句子，将标点符号替换为空格，将大写字母转换为小写字母O（n=字符串“句子”长度）

`for (auto & c: p) c = isalpha(c) ? tolower(c) : ' ';`

* 用一个unordered_set来记录“黑名单”, O（m=字符串“黑名单”长度）
* 遍历句子中的字符串，用unordered_map来记录各字符串出现的次数，同时需要检查是否在“黑名单”中。同时记录最高频词汇的pair, O（n）
第三步中，句子用stringstream来分割空格, 时间复杂度为O（m+n）

**Hashtable**

```cpp
class Solution {
public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    // Record the banned words set
    unordered_set<string> b(banned.begin(), banned.end());
    unordered_map<string, int> counts;
    const string pattern = "!?',;. ";
    int best = 0;
    string ans;
    const int n = paragraph.size();
    string word;
    for (int i = 0; i <= n; ++i) {
      // If the element is not in the "!?',;. ", then this is a words (Deal with in the else branch).
      if (i == n || pattern.find(paragraph[i]) != string::npos) {
        // Deal with one whole word
        if (++counts[word] > best && !b.count(word) && word.size() > 0) {
          best = counts[word];
          ans = word;
        }
        word.clear();
      } else {
        word += tolower(paragraph[i]);
      }
    }
    return ans;
  }
};
```

## Follow up

如果需要返回的是几个出现最高频率的单词，应该怎么做。