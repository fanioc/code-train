#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int m, n, A[102], Ans;
  int i, x, tot = 0, t;
  cin >> m >> n;
  for (i = 0; i < n; i++)
    cin >> A[i];

  A[n] = m + 1;

  // alg排序
  sort(A, A + n + 1);

  if (A[0] != 1) {
    cout << "-1" << endl;
    return 0;
  }

  for (i = 2; i <= n + 1 && A[i] <= m + 1; i++) {
    if (A[i] - 1 <= tot)
      continue;
    t = ceil(1.0 * (A[i] - 1 - tot) / (A[i - 1]));
    Ans += t;
    tot += A[i - 1] * t;
  }

  printf("%d", Ans);
}