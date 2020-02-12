#include <iostream>
using namespace std;
long long f[501] = {0};

int main() {
  int n;
  cin >> n;
  f[0] = 0, f[1] = 1, f[2] = 1, f[3] = 2;
  for (int i = 4; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 3];
  }
  cout << f[n] << endl;
}