// ## 题目描述
// 你打开了美了么外卖，选择了一家店，你手里有一张满X元减10元的券，店里总共有n种菜，
// 第i种菜一份需要A_i元，因为你不想吃太多份同一种菜，所以每种菜你最多只能点一份，
// 现在问你最少需要选择多少元的商品才能使用这张券。

// ## 输入描述
// 第一行两个正整数n和X，分别表示菜品数量和券的最低使用价格。（1≤n≤100,
// 1≤X≤10000） 接下来一行n个整数，第i个整数表示第i种菜品的价格。（1≤A_i≤100）

// ## 输出描述
// 一个数，表示最少需要选择多少元的菜才能使用这张满X元减10元的券，保证有解。

// 输入示例
// 5 20
// 18 19 17 6 7
// 输出示例
// 23

// Analyze 以动态规划背包为例,计算0-20{21...99}容量,当得出答案时,则停止
// #define MaxPrice 10100
// #define MaxDish 100
// A[k] = {18,19,17, 6, 7}
// price[k][cost] = price[k-1][cost] // overweight
// price[k][cost] = judge(price[k-1][cost-A[k]] + A[k],price[k-1][cost])
// function judge 判断大于x,且最接近x的数   如果都小于x,则取最大
/*
#include <stdio.h>
#include <math.h>
#define MaxPrice 10099
#define MaxDish 100

int judge(int a, int b, int minPrice) {
  if (a < minPrice && b < minPrice) return a > b ? a : b;
  if (a >= minPrice) return a;
  if (b >= minPrice) return b;
  return abs(minPrice - a) < abs(minPrice - b) ? a : b;
}

int main() {
  int A[MaxDish + 1] = {0};
  int price[MaxDish + 1][MaxPrice + 1] = {0};
  int dishNum, minPrice;
  int cost, k;
  scanf("%d %d", &dishNum, &minPrice);
  for (k = 1; k <= dishNum; k++) scanf("%d", &A[k]);
  for (cost = 1; cost <= minPrice + 100; cost++) {
    for (k = 1; k <= dishNum; k++) {
      if (cost < A[k])
        price[k][cost] = price[k - 1][cost];  // overweight
      else {
        price[k][cost] = judge(price[k - 1][cost - A[k]] + A[k],
                               price[k - 1][cost], minPrice);
      }
      // printf("k:%d cost:%d => %d\n", k, cost, price[k][cost]);
    }
    if (price[dishNum][cost] >= minPrice) {
      printf("%d", cost);
      return 0;
    }
  }
  // printf("can't.");
}
 */

// Analyze 方案2
// price[cost] = price[cost-1]  // overweight
// price[cost] = max(price[cost-A[k]]+A[k],price[cost-1])

#include <stdio.h>
#include <math.h>
#define MaxPrice 10099
#define MaxDish 100

int judge(int a, int b, int minPrice) {
  if (a < minPrice || b < minPrice) return a > b ? a : b;
  return abs(minPrice - a) < abs(minPrice - b) ? a : b;
}

int main() {
  int A[MaxDish + 1] = {0};
  int price[MaxPrice + 1] = {0};
  int dishNum, minPrice;
  int cost, k, q;
  scanf("%d %d", &dishNum, &minPrice);
  for (k = 1; k <= dishNum; k++) scanf("%d", &A[k]);

  for (cost = 1; cost <= minPrice + 100; cost++) {
    for (k = 1; k <= dishNum; k++) {
      if (cost < A[k])
        price[cost] = price[cost - 1];  // overweight
      else {
        q = judge(price[cost - A[k]] + A[k], q, minPrice);
      }
    }
    price[cost] = q;
    printf("k:%d cost:%d => %d\n", k, cost, price[cost]);
    if (price[cost] >= minPrice) {
      printf("%d", cost);
      return 0;
    }
  }
}