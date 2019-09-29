#include <cstdlib>
#include <iostream>
using namespace std;

long long Cpl(int bottom, int top) {
  long long b = 1, t = 1;
  if (top == 0 || bottom == 0)
    return 1;

  for (int i = bottom; i >= bottom - top + 1; i--) {
    b *= i;
  }
  for (int i = 1; i <= top; i++) {
    t *= i;
  }
  return b / t;
}

int main() {
  long long sum = 0;
  int k, A, B, X, Y;
  cin >> k;
  cin >> A >> X >> B >> Y;
  for (int i = 0; i <= X; i++) {
    for (int j = 0; j <= Y; j++) {
      if (A * i + j * B == k) {
        sum += Cpl(X, i) * Cpl(Y, j);
      }
    }
  }
  cout << sum % 1000000007;
}