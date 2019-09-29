#define MAXSIZE 1024

typedef int elemtype;

//顺序表
struct Sequlist {
	elemtype data[MAXSIZE];
	int last;//最大的长度
};

//单链表
typedef struct Node {
	elemtype data;
	struct Node *next;
} SingleLinkList;
LinkList *head;
//插入节点 删除节点
//单链表的逆置 

//静态链表
struct StaticNode {
	elemtype data;
	int link;
};
StaticNode Student[7];

//循环链表

//双向链表
typedef struct DNode {
	elemtype data;
	struct DNode *prior,*next;//前驱 后继 
} DoubleLinkList;
DoubleLinkList *head;






int main() {}
