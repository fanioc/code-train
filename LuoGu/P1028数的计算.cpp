// P1028 数的计算
#include <iostream>
using namespace std;

//定义全局变量自动赋0
int i, j, f[1010];
int n;

int main() {
  cin >> n;

  for (i = 0; i <= n; i++) {
    for (j = 1; j <= i / 2; j++)
      f[i] += f[j];  //每一位叠加，递推走起
    f[i]++;          //加上自身
  }

  cout << f[n];
}