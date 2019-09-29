#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void replaceSpace(char *str, int length)
{
  if (str == nullptr || length < 0)
    return;
  char *prt = str;
  int blankNum = 0;
  while (*prt != '\0')
  {
    if (*prt == ' ')
      blankNum++;
    prt++;
  }

  if (blankNum > 0)
  {
    int newLength = length + blankNum * 2;
    char *p1 = (char *)(str + length - 1), *p2 = (char *)(str + newLength - 1);
    while (p1 != p2)
    {
      if (*p1 == ' ')
      {
        *p2 = '0';
        p2--;
        *p2 = '2';
        p2--;
        *p2 = '%';
        p2--;
        p1--;
      }
      else
      {
        *p2 = *p1;
        p2--;
        p1--;
      }
    }
  }
  else
    return;
}

int main()
{
  char str[50] = "hell word !";
  // cin>>str;
  cin.getline(str,50);
  replaceSpace(str, 12);
  cout << str;
}