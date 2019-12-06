#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

bool Find(int target, vector<vector<int> > arrays) {
  int row = -1, col = -1;
  for (int i = 0; i < arrays.size(); i++) {
    if (row >= i) {
      continue;
    }
    for (int j = arrays[i].size() - 1; j >= 0; j--) {
      if (j >= col && col != -1) continue;
      if (arrays[i][j] == target) return true;
      if (arrays[i][j] < target) {
        row = i;  //跳过该行
        break;
      }
      if (arrays[i][j] > target) {
        col = j;  //跳过该列
        continue;
      }
    }
  }
  return false;
}

int main() {
  vector<vector<int> > arrays = {
      {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
  cout << Find(7, arrays);
}