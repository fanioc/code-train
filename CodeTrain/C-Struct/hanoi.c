#include <stdio.h>
#include <string.h>

void move(int n, int a, int b, int c) {
  if (n == 1)                       // dsfasf
    printf(":: %c -> %c\n", a, c);  // dsaf
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
