// 0-1 knapsack problem.
// w[i] 2,3,5,7,9
// v[i] 4,6,8,9,12
// capacity 20

#include <stdio.h>
#define Num 5
#define MaxCap 20

int Knapsack(int* w, int* v, int cap, int num) {
  int B[Num + 1][MaxCap + 1] = {0};
  int k, c;
  for (c = 1; c <= cap; c++)
    for (k = 1; k <= Num; k++) {
      if (w[k] > c) {  // overweight
        B[k][c] = B[k - 1][c];
      } else {
        int v1 = B[k - 1][c - w[k]] + v[k];
        int v2 = B[k - 1][c];
        B[k][c] = v1 > v2 ? v1 : v2;
      }
    }
  return B[num][cap];
}

void main() {
  int W[] = {0, 2, 3, 5, 7, 9};
  int V[] = {0, 4, 6, 8, 9, 12};
  printf("%d", Knapsack(W, V, 20, 5));
}