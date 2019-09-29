#include <iostream>
#include <cstdlib>
using namespace std;
int n, s, a, b;
int xy[5000][2];

int compare(const void* A, const void* B) {
  return ((int*)A)[1] - ((int*)B)[1];
}

int main() {
  int maxh;
  cin >> n >> s;
  cin >> a >> b;
  for (int i = 0; i < n; i++)
    cin >> xy[i][0] >> xy[i][1];
  maxh = a + b;
  qsort(xy, n, sizeof(xy[0]), compare);

  int k = 0;
  for (int i = 0; i < n; i++)
    if (s - xy[i][1] >= 0 && maxh >= xy[i][0]) {
      k++;
      s -= xy[i][1];
    }
  cout << k << endl;
}