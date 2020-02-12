/**
 * 钢条切割 <动态规划>
 */
#include <stdio.h>
#define MaxSIze 1000
#define max(a, b) ((a) > (b) ? (a) : (b))

int ButtomUpDynamic(int *p, int n) {
  int r[MaxSIze] = {0}, q;
  for (int i = 1; i <= n; i++) {
    q = -1;
    for (int j = 1; j <= i; j++) {
      q = max(q, p[j] + r[i - j]);
    }
    r[i] = q;
  }
  return r[n];
}

void main() {
  int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  printf("%d", ButtomUpDynamic(p, 5));
}