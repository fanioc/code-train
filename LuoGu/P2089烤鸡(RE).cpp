#include <cstdio>
#include <iostream>
using namespace std;
int n, a[10], k, kv[100000][10];

void backtrace(int x[10], int start, int left) {
  if (left >= 1)
    for (int i = 9; i >= 0; i--) {
      if (x[i] >= 3) {
        continue;
      }
      x[i]++;
      backtrace(x, i, left - 1);
      x[i]--;
    }
  else {
    for (int i = 0; i < 10; i++)
      kv[k][i] = x[i];
    k++;
  }
}

int main() {
  cin >> n;
  if (n < 10)
    cout << 0 << endl;
  else {
    for (int i = 0; i < 10; i++)
      a[i] = 1;
    backtrace(a, 0, n - 10);
    cout << k << endl;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < 10; j++)
        cout << kv[i][j] << " ";
      cout << endl;
    }
  }
}