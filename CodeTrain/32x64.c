#include <stdio.h>
#include <stdlib.h>
int main() {
  unsigned int i = 0xffffffff;
  if (i > 0) {
    printf("%u\n",-1);
    printf("64bit \n");
  } else {
    printf("32bits \n");
  }
  system("pause");
  return 0;
}