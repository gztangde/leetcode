# 一些 Leetcode 里面经常用到的函数模板

## 类型定义简化

```cpp
using namespace std;
typedef long long LL;
typedef vector<int> VI;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define EACH(i, c) for (__typeof((c).begin()) i = (c).begin(), i##_end = (c).end(); i != i##_end; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int INF = (int)1E9;
#define MAXN 10005
```

## 一些常用的模板函数

From Leetcode 用户[natsugiri](https://leetcode.com/natsugiri/)

```cpp
template <class T>
inline void amin(T &x, const T &y) {
  if (y < x) x = y;
}

template <class T>
inline void amax(T &x, const T &y) {
  if (x < y) x = y;
}

template <class Iter>
void rprintf(const char *fmt, Iter begin, Iter end) {
  for (bool sp = 0; begin != end; ++begin) {
    if (sp)
      putchar(' ');
    else
      sp = true;
    printf(fmt, *begin);
  }
  putchar('\n');
}
```