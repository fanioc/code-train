#include <iostream>
using namespace std;
int heightMap[26] = {};
int maxHeight = 0;

//去除结尾多余空格
void trimend(string* str) {
  string::iterator pend = str->end();
  while (*(pend) == ' ') {
    pend--;
  }
  str->erase(pend, str->end());
}

int main() {
  string temp;
  int k = 1;
  while (k++ <= 4) {     //读取4次
    getline(cin, temp);  //读取一行数据
    int i = 0;
    do {
      if (temp[i] <= 'Z' && temp[i] >= 'A') {
        heightMap[temp[i] - 'A']++;  //记录每个字符的次数
        maxHeight = maxHeight > heightMap[temp[i] - 'A']
                        ? maxHeight
                        : heightMap[temp[i] - 'A'];
      }
    } while (temp[++i] != '\0');
  }

  // print out
  for (int i = 0; i < maxHeight; i++) {
    string tmpline = "";
    for (int n = 0; n < 26; n++) {
      if (heightMap[n] >= maxHeight - i)
        tmpline += "* ";
      else
        tmpline += "  ";
    }
    trimend(&tmpline);  //去除结尾空行
    cout << tmpline << endl;
  }
  
  for (int m = 0; m < 26; m++) {
    char c = m + 'A';
    if (m == 25)  //避免结尾空格
      cout << c;
    else
      cout << c << " ";
  }
}