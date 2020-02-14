#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// 从给出的0-1之间的小鼠,打印二进制字符串
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100%的用户
// 内存消耗 :	8.3 MB, 在所有 C++ 提交中击败了100.00%的用户


string printBin(double num) {
  double result = 0;
  string result_str = "0.";
  double add = 0.5;
  int i = 1;
  while (i <= 32) {
    if (result + add <= num) {
      result += add;
      result_str.append("1");
    } else
      result_str.append("0");
    // cout << result << endl;
    if (abs(num - result) < 0.000000000000001) return result_str;
    add = add / 2;
    i++;
  }
  return "ERROR";
}

int main() { cout << printBin(0.1); }