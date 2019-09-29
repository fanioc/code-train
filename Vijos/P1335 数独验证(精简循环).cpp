#include <cstring>
#include <iostream>

using namespace std;

int arr[9][9];

int main() {
  int i, j, k;
  int n;
  scanf("%d", &n);

  int arr_idx[3][9];
  while (n--) {
    for (i = 0; i < 9; ++i) {
      for (j = 0; j < 9; ++j) {
        scanf("%d", &arr[i][j]);
      }
    }

    //横竖向检测
    int mapi[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
    int mapj[9] = {0, 3, 6, 0, 3, 6, 0, 3, 6};

    for (i = 0; i < 9; ++i) {
      memset(arr_idx, 0, sizeof(arr_idx));
      for (j = 0; j < 9; ++j) {
        if (++arr_idx[0][arr[i][j] - 1] > 1)
          break;  //横向
        if (++arr_idx[1][arr[j][i] - 1] > 1)
          break;  //竖向
        if (++arr_idx[2][arr[j / 3 + mapi[i]][j % 3 + mapj[i]] - 1] > 1)
          break;  //九宫格
      }
      if (j < 9)
        break;
    }
    if (i < 9) {
      printf("Wrong\n");
    } else {
      printf("Right\n");
    }
  }
  system("pause");
  return 0;
}