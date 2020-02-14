// 执行用时 :4 ms, 在所有 C++ 提交中击败了95.00%的用户
// 内存消耗 :13.6 MB, 在所有 C++ 提交中击败了100.00%的用户

#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

vector<int> levelOrder(TreeNode* root) {
  vector<int> result(0);
  if (root == nullptr) return result;
  vector<TreeNode*> quece(0);
  quece.push_back(root);
  int head = 0;
  while (quece.size() - head != 0) {
    TreeNode* tmpNode = quece[head];
    head++;
    result.push_back(tmpNode->val);
    if (tmpNode->left != nullptr) quece.push_back(tmpNode->left);
    if (tmpNode->right != nullptr) quece.push_back(tmpNode->right);
  }
  return result;
}