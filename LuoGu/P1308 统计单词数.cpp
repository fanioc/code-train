#include <cctype>
#include <iostream>
using namespace std;

int main() {
  string word, str;
  getline(cin, word);
  getline(cin, str);
  int i = 0, flag = 1, n = 0, k = 0, find = -1;
  while (1) {
    if (str[i] == '\0') {
      if (flag) {
        if (word[n] == '\0') {
          k++;
        }
      }
      break;
    } else if (str[i] == ' ') {
      if (flag) {
        if (word[n] == '\0') {
          k++;
        }
      }
      flag = 1;
      n = 0;
    } else {
      if (flag) {  //可以比较
        if (tolower(str[i]) == tolower(word[n])) {
          if (k < 1)
            if (find < 0)
              find = i;  //标记第一次找到
          // cout << "find:" << n << "- flag:" << flag << " -i:" << i << " n:"
          // << n
          //      << endl;
          n++;
        } else {  //字符不相等
          // cout << "not equl" << n << endl;
          if (k < 1)
            if (find >= 0)
              find = -1;  //标记第一次找到
          flag = 0;
          n = 0;
        }
      }
    }
    i++;
  }

  if (k == 0)
    cout << -1 << endl;
  else
    cout << k << " " << find << endl;
}