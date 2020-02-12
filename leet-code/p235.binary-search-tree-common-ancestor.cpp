// 二叉搜索树的最近公共祖先

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  // 递归利用搜索树的性质
  // O(N) S(N)
  // 执行用时 :40 ms, 在所有 C++ 提交中击败了71.26%的用户
  // 内存消耗 :26 MB, 在所有 C++ 提交中击败了5.11%的用户
  TreeNode* lowestCommonAncestorRecurve(TreeNode* root, TreeNode* p,
                                        TreeNode* q) {
    if (p->val < root->val && q->val < root->val)
      return lowestCommonAncestorRecurve(root->left, p, q);
    if (p->val > root->val && q->val > root->val)
      return lowestCommonAncestorRecurve(root->right, p, q);
    return root;
  }

  // 来自官方题解
  // 可以看出区别不算大 
  // O(N) S(1)
  // 执行用时 :36 ms, 在所有 C++ 提交中击败了88.97%的用户
  // 内存消耗 :26 MB, 在所有 C++ 提交中击败了5.11%的用户
  TreeNode* lowestCommonAncestorIterator(TreeNode* root, TreeNode* p,
                                         TreeNode* q) {
    int pVal = p->val;
    int qVal = q->val;
    TreeNode* node = root;
    while (node != nullptr) {
      int parentVal = node->val;
      if (pVal < parentVal && qVal < parentVal) {
        node = node->left;
      } else if (pVal > parentVal && qVal > parentVal) {
        node = node->right;
      } else {
        return node;
      }
    }
    return nullptr;
  }
};