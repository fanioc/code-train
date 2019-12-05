#include <stdio.h>
#include <stdlib.h>
int main()
{
  double *p;
  int z = sizeof(p);

  printf("%d\n", z);

  if (z == 8)
  {
    printf("%d\n", z);
    printf("64bit \n");
  }
  else
  {
    printf("32bits \n");
  }
  system("pause");
  return 0;
}