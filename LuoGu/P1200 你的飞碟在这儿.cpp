// P1200 [USACO1.1]你的飞碟在这儿Your Ride Is Here
#include <iostream>
using namespace std;

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  int i = 0, n1 = 1, n2 = 1;
  while (str1[i] != '\0') {
    n1 *= str1[i] - 'A' + 1;
    i++;
  }
  i = 0;
  while (str2[i] != '\0') {
    n2 *= str2[i] - 'A' + 1;
    i++;
  }

  if (n1 % 47 == n2 % 47)
    cout << "GO";
  else
    cout << "STAY";
}