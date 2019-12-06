typedef int elemtype;
typedef struct BinaryTreeNode {
  struct BinaryTreeNode *left, *right;
  elemtype data;
} BinaryTree;