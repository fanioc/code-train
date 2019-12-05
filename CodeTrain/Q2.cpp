#include <iostream>
using namespace std;

int remove(char *s, int num)
{
  char back = '\0', now = '\0';
  int i = 0;
  while (num > 0)
  {
    if (now == '\0')
    { //第一次
      back == -1;
      now = *(s + i);
    }
    else if (back == '\0' && now != -1)
    {
      back = now;
      now = *(s + i);
    }
    else
    {
      if (back == '0' && now == '1' || back == '1' && now == '0')
      {
        num -= 2;
      }
      back = now;
      now = *(s + i);
    }
  }

  return num;
}

int main()
{
  int n;
  char s[200000];

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];
}