#define MAXSIZE 1024

typedef int elemtype;

//˳���
struct Sequlist {
	elemtype data[MAXSIZE];
	int last;//���ĳ���
};

//������
typedef struct Node {
	elemtype data;
	struct Node *next;
} SingleLinkList;
SingleLinkList *head;
//����ڵ� ɾ���ڵ�
//������������ 

//��̬����
struct StaticNode {
	elemtype data;
	int link;
};
StaticNode Student[7];

//ѭ������

//˫������
typedef struct DNode {
	elemtype data;
	struct DNode *prior,*next;//ǰ�� ��� 
} DoubleLinkList;
DoubleLinkList *head;






int main() {}
