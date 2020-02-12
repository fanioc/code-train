#include <stdio.h>
#include <stdlib.h>

void main() {
  int m, n;
  scanf("%d %d", &m, &n);
  int **u = (int **)malloc(sizeof(int *) * m);
  for (int i = 0; i < n; i++) {
    u[i] = (int *)malloc(sizeof(int));
  }

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) u[i][j] = i * 10 + j;

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) printf("%d ", u[i][j]);
}