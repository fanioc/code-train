#include <iostream>
using namespace std;
int k[3], value[100][3], n;

bool judge(const int za[3]) {
  int a[3] = {za[0], za[1], za[2]};
  int map[10] = {0};
  for (int i = 0; i < 3; i++) {
    do {
      if (map[a[i] % 10] == 1)
        return false;
      else
        map[a[i] % 10] = 1;
      a[i] /= 10;
    } while (a[i]);
  }
  for (int i = 1; i <= 9; i++)
    if (map[i] != 1)
      return false;
  return true;
}

int main() {
  cin >> k[0] >> k[1] >> k[2];
  for (int i = 100; i <= 333; i++) {
    if (i % k[0] != 0)
      continue;
    value[n][0] = i;
    value[n][1] = i / k[0] * k[1];
    value[n][2] = i / k[0] * k[2];
    if (value[n][2] > 999)
      continue;

    if (judge(value[n]))
      n++;
  }

  if (n > 0)
    for (int i = 0; i < n; i++)
      cout << value[i][0] << " " << value[i][1] << " " << value[i][2] << endl;
  else
    cout << "No!!!";
}