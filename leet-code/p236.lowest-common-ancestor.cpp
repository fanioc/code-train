// 二叉树的最近公共祖先

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  // 使用多层递归,标记左右节点
  // 执行用时 :24 ms, 在所有 C++ 提交中击败了61.86%的用户
  // 内存消耗 :17 MB, 在所有 C++ 提交中击败了29.41%的用户
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    if (root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right)  // 左右节点都存在
      return root;
    return left ? left : right;
  }
};