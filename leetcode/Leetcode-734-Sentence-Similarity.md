---
title: Leetcode 734. Sentence Similarity
date: 2019-03-12 23:28:27
updated: 2019-03-12 23:28:27
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Leetcode 734. Sentence Similarity

题目大意：输入是两个句子，判断这两个句子是否相似

Given two sentences `words1, words2` (each represented as an array of strings), and a list of similar word pairs `pairs`, determine if two sentences are similar.

For example, "great acting skills" and "fine drama talent" are similar, if the similar word pairs are `pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]]`.

Note that the similarity relation is not transitive. For example, if "great" and "fine" are similar, and "fine" and "good" are similar, "great" and "good" are not necessarily similar.

However, similarity is symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences `words1 = ["great"], words2 = ["great"], pairs = []` are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like `words1 = ["great"]` can never be similar to `words2 = ["doubleplus","good"]`.

Note:

- The length of `words1` and `words2` will not exceed `1000`.
- The length of `pairs` will not exceed `2000`.
- The length of each `pairs[i]` will be `2`.
- The length of each `words[i]` and `pairs[i][j]` will be in the range `[1, 20]`.

**Difficulty**:Medium

**Category**:

# Solution

cite: [Sentence Similarity 句子相似度](http://www.cnblogs.com/grandyang/p/8016251.html)

这道题目判定的条件是：

* 两个句子的单词数要相同
* 每两个对应的单词要是相似度(题目会给一些相似的单词对，这里说明了单词对的相似具有互逆性但是没有传递性）

这里单词相似是没有传递性，就使得问题变得很容易了，我们只要建立一个单词和其所有相似单词的集合的映射就可以了，比如说如果great和fine类似，且great和good类似，那么就有下面这个映射：

`great -> {fine, good}`

所以我们在逐个检验两个句子中对应的单词时就可以直接去映射中找，注意有可能遇到的单词对时反过来的，比如　fine　和　great，所以我们两个单词都要带到映射中去查找，只要有一个能查找到，就说明是相似的，反之，如果两个都没查找到，说明不相似，直接返回false，参见代码如下：

## Solution 1: HashTable

```cpp
class Solution {
 public:
  bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
    if (words1.size() != words2.size()) return false;
    unordered_map<string, unordered_set<string>> m;
    for (auto pair : pairs) {
      m[pair.first].insert(pair.second);
    }
    for (int i = 0; i < words1.size(); ++i) {
      if (words1[i] == words2[i]) continue;
      if (!m[words1[i]].count(words2[i]) && !m[words2[i]].count(words1[i])) return false;
    }
    return true;
  }
};
```

# Follow up

如果同义的单词具有传递性，应该怎么处理呢。