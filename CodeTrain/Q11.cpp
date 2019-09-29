#include <cmath>
#include <iostream>
using namespace std;

int compare(const void* A, const void* B) {
  return (*(int*)A - *(int*)B);
}

int main() {
  int m, n, coin[102];
  int i, x, sum = 0;
  cin >> m >> n;
  for (i = 0; i < n; i++)
    cin >> coin[i];

  coin[n] = m + 1;  //设定最后一个数据
  qsort(coin, n, sizeof(int), compare);

  if (coin[0] != 1) {
    cout << "-1" << endl;  //找到最小的不符合
    return 0;
  }

  int k = 0, num = 0;  //保存每次判断需要带的硬币数
  for (i = 1; i <= n && coin[i] <= m + 1; i++) {
    //判断是否已经包含该次数
    if (coin[i] - 1 <= sum)
      continue;
    k = ceil(1.0 * (coin[i] - 1 - sum) /
             (coin[i - 1]));  //取整，取最少要带的面额数
    num += k;                 //需要带的硬币加
    sum += coin[i - 1] * k;
  }

  cout << num << endl;
}