/*
 * @Author: Fanioc
 * @Date: 2019-12-06 16:48:21
 * @Last Modified by:   Fanioc
 * @Last Modified time: 2019-12-06 16:48:21
 * @Note:
 */
#include <stdio.h>

void move(int n, int a, int b, int c) {
  if (n == 1)
    printf(":: %c -> %c\n", a, c);
  else {
    move(n - 1, a, c, b);
    printf(":: %c -> %c\n", a, c);
    move(n - 1, b, a, c);
  }
}

int main(int argc, char const *argv[]) {
  int n;
  register int a = 'A', b = 'B', c = 'C';
  scanf("%d", &n);
  move(n, a, b, c);
  return 0;
}
