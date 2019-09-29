#include <iostream>
using namespace std;

int remove(char* s, int num) {
  char back = '\0', now = '\0';
  int i = 0, flag = 0;
  if (num < 2)
    return num;

  while (i < num) {
    if (now == '\0') {  //???
      back == '\0';
      now = *(s + i);
    } else if (back == '\0' && now != '\0') {
      back = now;
      now = *(s + i);
    } else {
      if (back == '0' && now == '1' || back == '1' && now == '0') {
        for (int j = i; j <= num - 1; j++) {
          *(s + i) = *(s + i + 2);
        }
        num -= 2;
        //?????

        return remove(s, num);
      } else {
        //??????
        back = now;
        now = *(s + i);
      }
    }
    i++;
  }

  return num;
}

int main() {
  int n;
  char s[200000];

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];

  cout << remove(s, n) << endl;
}