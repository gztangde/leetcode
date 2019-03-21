Fenwick Tree is mainly designed for solving the single point update range sum problems. e.g. what’s the sum between i-th and j-th element while the values of the elements are mutable.

Init the tree (include building all prefix sums) takes O(nlogn)

Update the value of an element takes O(logn)

Query the range sum takes O(logn)

Space complexity: O(n)


![](/images/2019-03-20-23-05-47.png)

![](/images/2019-03-20-23-05-59.png)


```cpp
class FenwickTree {
 public:
  FenwickTree(int n) : sums_(n + 1, 0) {}

  void update(int i, int delta) {
    while (i < sums_.size()) {
      sums_[i] += delta;
      i += lowbit(i);
    }
  }

  int query(int i) const {
    int sum = 0;
    while (i > 0) {
      sum += sums_[i];
      i -= lowbit(i);
    }
    return sum;
  }

 private:
  static inline int lowbit(int x) { return x & (-x); }
  vector<int> sums_;
};
```