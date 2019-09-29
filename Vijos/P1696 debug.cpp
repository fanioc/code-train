#include <cmath>
#include <iostream>
using namespace std;
int step = 0;

string toLianfenshu(int a, int b) {
  string x = "";
  if (b == 1 || a % b == 0) {
    x += to_string(a / b);
    step = 0;
    return x + "]";
  }
  if (step == 0)
    x += "[";

  x += to_string((int)a / b);
  if (step == 0) {
    x += ";";
    step++;
  } else {
    x += ",";
    step++;
  }
  a = a % b;
  x += toLianfenshu(b, a);
  return x;
}

struct FenShu {
  int a = 1;
  int b;
};

FenShu LianFenShuAdd(int a, FenShu b) {
  FenShu stru;
  stru.a = a * b.a + b.b;
  stru.b = b.a;
  int min = stru.a < stru.b ? stru.a : stru.b;
  for (int i = 1; i < min; i++) {
    if (stru.a % i == 0 && stru.b % i == 0) {
      stru.a /= i;
      stru.b /= i;
    }
  }
  return stru;
}

string toFenshu(int* a, int n) {
  FenShu xx;
  xx.a = *(a + n - 1);
  xx.b = 1;
  if(n==1)
  return to_string(*a);

  for (int i = 1; i < n; i++) {
    xx = LianFenShuAdd(*(a + n - 1 - i), xx);
  }
  string x = "";
  x = to_string(xx.a) + "/" + to_string(xx.b);
  return x;
}

int main() {
  int a[200];
  int n;
  string str;
  int i, j;
  while (cin >> str) {
    j = 0;
    if (str[0] == '[') {
      i = 1;
      while (str[i] != ']') {
        if ('0' < str[i] && str[i] > '9' || str[i] == ',' ||
            str[i] == ';') {  //一个数记录完毕
          
        } else {
          if ('0' <= str[i - 1] && str[i - 1] <= '9') {
            a[j] = a[j] * 10 + (str[i] - '0');
          } else {
            a[j] = str[i] - '0';
            j++;                //记录第几个数
          }
        }
        i++;
      }
      cout << toFenshu(a, j ) << endl;
    } else {
      i = 0;
      while (str[i] != '\0') {
        if ('0' > str[i] && str[i] < '9' || str[i] == '/') {  //一个数记录完毕
          j++;  //记录第几个数
        } else {
          if (i > 0 && '0' <= str[i - 1] && str[i - 1] <= '9') {
            a[j] = a[j] * 10 + (str[i] - '0');
          } else {
            a[j] = str[i] - '0';
          }
        }
        i++;
      }
      cout << toLianfenshu(a[0], a[1]) << endl;
    }
  }
}
