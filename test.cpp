#include <memory.h>
#include <stdio.h>
const int MAXN = 100;
int flag[MAXN / 32 + 1];
int primes[MAXN / 3 + 1], pi;
void GetPrime_1() {
  int i, j;
  pi = 0;
  memset(flag, 0, sizeof(flag));
  for (i = 2; i < MAXN; i++)
    if (!((flag[i / 32] >> (i % 32)) & 1)) {
      primes[pi++] = i;
      for (j = i; j < MAXN; j += i) flag[j / 32] |= (1 << (j % 32));
    }
}