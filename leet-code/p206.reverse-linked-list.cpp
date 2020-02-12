// 链表反转
// 时间复杂度o(n)
// 空间复杂度s(1)
// timging: 8 ms
// rank: 84.5%

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *preNode, *nextNode;
    preNode = head;
    nextNode = preNode->next;
    preNode->next = nullptr;
    while (nextNode != nullptr) {
      ListNode* tmpNode = nextNode->next;
      nextNode->next = preNode;
      preNode = nextNode;
      nextNode = tmpNode;
    }

    return preNode;
  }
};