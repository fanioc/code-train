/*
 * @Author: Fanioc
 * @Date: 2019-09-05 18:37:57
 * @Description:
 */
#include <stdio.h>
typedef int elemtype;
typedef struct BinaryTreeNode {
  struct BinaryTreeNode *left, *right;
  elemtype data;
} BinaryTree;

int main() {
  BinaryTree xx, y;
  xx.data = 3;
  printf("%d", xx.data);
  return 0;
}