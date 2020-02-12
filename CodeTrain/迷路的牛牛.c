#include <stdio.h>

// %求模时,考虑负数

int main() {
  int N;
  char S[1000];
  scanf("%d", &N);
  scanf("%s", &S);
  int result = 1000;
  const x = 425;
  const char ans[] = {"N", "W", "S", "E"};
  for (int i = 0; i < N; i++) {
    switch (S[i]) {
      case 'L':
        result++;
        break;
      case 'R':
        result--;
        break;
      default:
        return 0;
        break;
    }
  }

  printf("%s", ans[result % 4]);
}