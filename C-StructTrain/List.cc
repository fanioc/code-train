#define MAXSIZE 1024

typedef int elemtype;

struct Sequlist {
  elemtype data[MAXSIZE];
  int last;
};

typedef struct Node {
  elemtype data;
  struct Node *next;
} SingleLinkList;
SingleLinkList *head;

struct StaticNode {
  elemtype data;
  int link;
};
StaticNode Student[7];

typedef struct DNode {
  elemtype data;
  struct DNode *prior, *next;
} DoubleLinkList;
DoubleLinkList *head;

int main() {}
