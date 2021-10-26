#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode{	//����Ʈ��� ����ü ���� 
   char data[4];
   struct listNode *link;
}listNode;



typedef struct {	//��ũ����Ʈ ��� ����ü ���� 
   listNode * head;
}linkedList_h;

// ���� ���� ����Ʈ�� ����
linkedList_h *createLinkedList_h();
// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h* L);
// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h *L);
// ù��° ���� �����ϴ� ����
void insertFirstNode(linkedList_h *L, char *x);
// ��带 pre �ڿ� �����ϴ� ����
void insertMiddleNode( linkedList_h *L, listNode *pre, char *x);
// �������� ��带 �����ϴ� ����
void insertLastNode( linkedList_h *L, char *x);
// ����Ʈ���� x ��带 Ž���ϱ�( page173, 175 )
linkedList_h *searchNode(linkedList_h *L, char *x);
int main(){
   linkedList_h * L;
   listNode * p;

   printf("(1) ���鸮��Ʈ �����ϱ�! \n");
   L = createLinkedList_h();
   printList( L );
   
   printf("(2) ����Ʈ ó���� [��]��� �����ϱ�! \n");
   insertFirstNode( L, "��");
   printList( L );
   
   printf("(3) ����Ʈ �������� [��]��� �����ϱ�! \n");
   insertLastNode( L, "��");
   printList( L );
   
   printf("(4) ����Ʈ ù ��°�� [��]��� �����ϱ�! \n");
   insertFirstNode( L, "��");
   printList( L );
   
   printf("(5) ����Ʈ���� [��] ��带 ã�� �� �ڿ� [��] �����ϱ�! \n");
   p = searchNode( L, "��");
   if( p == NULL ) printf("ã�� �����Ͱ� �����ϴ�.\n");
   else    insertMiddleNode( L, p, "��");
   printList( L );
   
   printf("(6) ����Ʈ ������ �����Ͽ� ���� ����Ʈ�� �����! \n");
   freeLinkedList_h(L);
   printList( L );
   return 0;
}
// ���� ���� ����Ʈ�� ����
linkedList_h *createLinkedList_h(){
   linkedList_h* L;		//��� L ���� 
   L = (linkedList_h*)malloc(sizeof(linkedList_h)); 	//���� �޸� �Ҵ� 
   L -> head = NULL; 	//���� �ǹ��ϴ� NULL�� ��忡 ���� 
   return L;	//L ��ȯ 
}

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h* L){
   listNode* p;		//��� p ���� 
   while (L -> head != NULL) {		//����� ���� ������ 
      p = L -> head;	//p�� ����� ��� 
      L -> head = L -> head -> link;	//
      free(p);
      p = NULL;
   }
}

// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h *L){
   listNode* p;		//��� p ���� 
   printf ("L = (");	
   p = L -> head;	//p�� L�� ��� 
   while (p != NULL) {		//L�� ������ 
      printf ("%s", p -> data);		//data ��� 
      p = p -> link;	//���� ���� �̵� 
      if (p != NULL) printf (", ");
   }
   printf (") \n");
}

// ù��° ���� �����ϴ� ����
void insertFirstNode(linkedList_h *L, char *x){
   listNode* newnode;		//newnode��� ��� ���� 
   newnode = (listNode*)malloc(sizeof(listNode));	//���� �޸� �Ҵ� 
   strcpy(newnode -> data, x);		//newnode�� ������ �ֱ� 
   newnode -> link = L -> head;		//L->head�� �ּҸ� newnode->link�� �ֱ� 
   L -> head = newnode;		//L->head�� newnode �ֱ� 
}

// ��带 pre �ڿ� �����ϴ� ����
void insertMiddleNode( linkedList_h *L, listNode *pre, char *x){
   listNode* newNode;	//newnode��� ��� ����
   newNode = (listNode*)malloc(sizeof(listNode));	//���� �޸� �Ҵ� 
   strcpy(newNode -> data, x);		//newnode�� ������ �ֱ� 
   if (L->head == NULL) {	//��尡 ���ٸ� 
      newNode -> link = NULL;	
      L -> head = newNode;
   }
   else if (pre == NULL) {	//pre�� ������ ����� 
      L -> head = newNode;
   }
   else {	//��尡 �߰��� �ִٸ� 
      newNode -> link = pre -> link;	//���� pre->link�� newnode���� �ְ� 
      pre -> link = newNode;	//pre����newnode �ֱ� 
   }
}
// �������� ��带 �����ϴ� ����
void insertLastNode( linkedList_h *L, char *x){
   listNode* newNode;	//newnode��� ��� ����
   listNode* temp;		//temp��� ��� ���� 
   newNode = (listNode*)malloc(sizeof(listNode));	//���� �޸� �Ҵ� 
   strcpy(newNode -> data, x);	//newnode�� ������ �ֱ� 
   if (L -> head == NULL) {		//��尡 ���ٸ� 
      L -> head = newNode;		//�ٷ� ��� �߰� 
      return;
   }
   
   temp = L -> head;	
   while (temp -> link != NULL) temp = temp -> link;	//temp->link�� ���� �ƴ϶�� ��� �̵� 
   temp -> link = newNode;	//���̶�� �������� ��� �߰� 
}   
// ����Ʈ���� x ��带 Ž���ϱ�( page173, 175 )
linkedList_h *searchNode(linkedList_h *L, char *x){
   listNode *temp;		//temp��� ��� ���� 
   temp = L -> head;	//temp�� L�� head 
   while (temp != NULL) {	//��尡 NULL�� �ƴ� ������ 
      if (strcmp(temp -> data, x) == 0) return temp;	//temp�� �����Ϳ� ã������ ���� ���ϰ� ������ temp�� ���� ��ȯ 
      else temp = temp -> link;		//�ڷ� �̵� 
   }
   return temp;		//temp ��ȯ 
}
