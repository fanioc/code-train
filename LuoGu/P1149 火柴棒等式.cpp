#include <iostream>
using namespace std;

//
// 0+4=4
// 0+11=11
// 1+10=11
// 2+2=4
// 2+7=9
// 4+0=4
// 7+2=9
// 10+1=11
// 11+0=11

//输入样例#1：
// 14
//输出样例#1：
// 2
//输入样例#2：
// 18
//输出样例#2：
// 9

int mapNum[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
  int n, sum = 0;
  cin >> n;
  int i, j, k, vali, valj, valnum;
  for (i = 0; i <= 1000; i++) {
    for (j = 0; j <= 1000; j++) {
      vali = 0, valj = 0, valnum = 0;
      int x = i, y = j;
      do {
        vali += mapNum[x % 10];
        x /= 10;
      } while (x);
      do {
        valj += mapNum[y % 10];
        y /= 10;
      } while (y);
      k = i + j;
      do {
        valnum += mapNum[k % 10];
        k /= 10;
      } while (k);
      if (vali + valj + valnum + 4 == n)
        sum++;
      // cout << i << "+" << j << "=" << k << endl;
    }
  }

  cout << sum;
}