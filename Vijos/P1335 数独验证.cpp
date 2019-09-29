#include <iostream>
using namespace std;

int i, j, k;
int yans[10];

bool toyan() {
  int k = 1, flag = 1;
  for (k = 1; k < 10; k++) {
    if (yans[k] != 1)
      flag = 0;
    yans[k] = 0; //清除标记
  }
  if (flag)
    return true;
  else
    return false;
}

bool yanzheng(int a[9][9]) {
  for (i = 0; i < 9; i++) {
    //验证列
    for (j = 0; j < 9; j++) {
      yans[a[j][i]] = 1;
    }
    if (!toyan())
      return false;
    //验证行
    for (j = 0; j < 9; j++) {
      yans[a[i][j]] = 1;
    }
    if (!toyan())
      return false;
  }

  //验证3*3方块
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (int m = 3 * i; m < 3 * i + 3; m++) {
        for (int n = 3 * j; n < 3 * j + 3; n++) {
          yans[a[m][n]] = 1;
        }
      }
      if (!toyan())
        return false;
    }
  }
  return true;
}

int main() {
  int a[9][9];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (j = 0; j < 81; j++) {
      cin >> a[j / 9][j % 9];
    }
    getchar();
    if (yanzheng(a))
      cout << "Right" << endl;
    else
      cout << "Wrong" << endl;
  }
  getchar();
}