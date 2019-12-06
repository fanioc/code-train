/*
 * @Author: mikey.zhaopeng 
 * @Date: 2019-12-06 16:42:16 
 * @Last Modified by:   mikey.zhaopeng 
 * @Last Modified time: 2019-12-06 16:42:16 
 */
typedef int elemtype;
typedef struct BinaryTreeNode {
  struct BinaryTreeNode *left, *right;
  elemtype data;
} BinaryTree;