
# Question

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

![](/images/in-post/2018-12-16-Leetcode-274-H-Index/2018-12-16-22-02-53.png)

According to the  [definition of h-index on Wikipedia](https://en.wikipedia.org/wiki/H-index): "A scientist has index  _h_  if  _h_  of his/her  _N_  papers have  **at least**  _h_  citations each, and the other  _N − h_  papers have  **no more than**  _h_  citations each."

**Note:** If there are several possible values for  _h_, the maximum one is taken as the h-index.

**Difficulty**:Medium
**Category**:Hash-Table, Sort


------------

# Analyze

可以按照如下方法确定某人的H指数：

1. 将其发表的所有[SCI](https://zh.wikipedia.org/wiki/%E7%A7%91%E5%AD%A6%E5%BC%95%E6%96%87%E7%B4%A2%E5%BC%95 "科学引文索引")论文按被引次数从高到低排序；
2. 从前往后查找排序后的列表，直到某篇论文的序号大于该论文被引次数。所得序号减一即为H指数。

------------

# Solution

```cpp
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    // For example: [3,0,6,1,5] ---> [6,5,3,1,0]
    // More than i paper bigger than the value;
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); ++i) {
      if (i >= citations[i]) return i;
    }
    return citations.size();
  }
};
```